#include "add_functions.h"

class BadConversion : public std::runtime_error
{
public:
    BadConversion(std::string const & s) : std::runtime_error(s)
    {

    }
};

template <typename T>
inline T convertToNumber(std::string const & s)
{
    std::istringstream i(s);
    T x;
    if (!(i >> x))
        throw BadConversion("convertToNumber(\"" + s + "\")");
    return x;
}

void read_unformatted_file(Scan &Data, const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);
    QString version;
    Data.scanName = fileName;
    version = in.readLine();
    std::stringstream iss_temp(version.toStdString());
    QVector<std::string> linecheck;
    do
    {
        std::string tmpstring;
        iss_temp >> tmpstring;
        linecheck.push_back(tmpstring);
    }while(iss_temp);
    if(linecheck.size() != 3)
    {
        if(version == "8008135" || version == "80081E5")
        {
            Data.scanName = in.readLine();
            Data.startPos = in.readLine().toDouble();
            Data.finPos = in.readLine().toDouble();
            Data.scanSpeed = in.readLine().toDouble();
            int polSettingsInt = in.readLine().toInt();
            Data.polSettings[0] = (polSettingsInt%2 == 1);
            Data.polSettings[1] = (polSettingsInt == 3 || polSettingsInt > 5);
            Data.polSettings[2] = (polSettingsInt >= 4);
        }
        if(version == "80081E5")
        {
            Data.log.countNumber = in.readLine().toDouble();
            Data.log.laserIntensity = in.readLine().toDouble();
            Data.log.name = in.readLine();
            Data.log.sensitivity = in.readLine().toDouble();
            Data.log.slitWidth = in.readLine().toDouble();
            Data.log.logfileSet = true;
        }
    }
    else
        Data.scanName = fileName;
    while(!in.atEnd()) {
        std::string line = in.readLine().toStdString();
        std::stringstream iss(line);
        QVector<std::string> tmpline;
        do
        {
            std::string tmpstring;
            iss >> tmpstring;
            tmpline.push_back(tmpstring);
        }while(iss);
        if(tmpline.size() == 3)
            Data.values.Data.push_back(qMakePair(convertToNumber<qreal>(tmpline[0]), convertToNumber<qreal>(tmpline[1])));
    }
    file.close();
}

void write_log_file(const Scan &Data, QString fileName)
{
    fileName += ".log";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(0, "Error!", file.errorString());
        return;
    }
    QTextStream out(&file);
    out << "This log is for scan " << fileName <<", written on " << QDate::currentDate().toString() << '\n';
    out << "Laser power [mW]: " << Data.log.laserIntensity << '\n';
    out << "Slit width [mm]: " << Data.log.slitWidth << '\n';
    out << "Sensitivity: " << Data.log.sensitivity << '\n';
    out << "Count Number: " << Data.log.countNumber << '\n';
    out << "All these data has been saved to the scan file, too\n";
    file.close();
}

void write_unformatted_file(const Scan &Data/*const QMap<double, double> &Data*/, QString fileName)
{
    fileName += ".txt";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream out(&file);
    out << "80081E5\n";
    out << Data.scanName << '\n';
    out << Data.startPos << '\n';
    out << Data.finPos << '\n';
    out << Data.scanSpeed << '\n';
    int polarSettings = Data.polSettings[0];
    polarSettings += Data.polSettings[1]?2:0;
    polarSettings += Data.polSettings[2]?4:0;
    out << polarSettings << '\n';//(int)(Data.polSettings[0]?1:0) + (int)(Data.polSettings[1]?2:0) + (int)(Data.polSettings[2]?4:0) << '\n';
    out << Data.log.countNumber << '\n';
    out << Data.log.laserIntensity << '\n';
    out << Data.log.name << '\n';
    out << Data.log.sensitivity << '\n';
    out << Data.log.slitWidth << '\n';
    out << Data.values.Data[0].first << '\t' << Data.values.Data[0].second << '\n';
    for(int i = 0; i < Data.values.Data.size(); i++)
    {
        out << Data.values.Data[i].first << '\t' << Data.values.Data[i].second << '\n';
    }

    file.close();
}

void splitToDoubles(QPair<double, double> &valuePair, QString input)
{
    QStringList stringlist = input.split(" ");
    double x, y;
    int i = 0;
    while(stringlist.at(i).isEmpty())
    {
        stringlist.removeAt(i);
        i++;
    }
    while(stringlist.at(stringlist.size()-1).isEmpty())
        stringlist.removeAt(stringlist.size()-1);

    x = stringlist.at(0).toDouble();
    y = stringlist.at(stringlist.size()-1).toDouble();
    valuePair = qMakePair(x, y);
}

void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<qreal, qreal> &outdata)//Assumes that all values are already ordered
{
    for(int i = 0; i < indata.size(); i++)
    {
        outdata[indata[i].first] = indata[i].second;
    }
}

int Read_DPC(void)
{
    int Inhibit = 0x0, Enable = 0x4;
    unsigned char Flag = 0, Highbytes = 0, Lowbytes = 0;

    unsigned char Digit[4] = {0, 0, 0, 0};

    //Port[Flagport] : = Enable;//Flagport muss angepasst werden

    //{ Waiting till bit 7 is on high : }
    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) > 0);
    //{ Waiting till bit 7 is low again}
    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) = 0);

    //Port[Flagport] : = Inhibit;

    //{ Read data port }
    //Highbytes: = Port[Highport]; Ports und Auslesevorgang muss angepasst werden
    //Lowbytes: = Port[Lowport];

    //Port[Flagport] : = Enable;

    //{ convert it into a decimal number }
    //Hier muss ebenfalls noch angepasst werden
    Digit[3] = Highbytes / 0x10;
    Digit[2] = Highbytes % 0x10;
    Digit[1] = Lowbytes / 0x10;
    Digit[0] = Lowbytes % 0x10;

    //{ Hardcoding to repair a particular data transfer error : }
    if(Digit[3] > 7)
        Digit[3] = 0;

    return Digit[3] * 1000 + Digit[2] * 100 + Digit[1] * 10 + Digit[0];
}

void DPC::run()
{
    int counts = 0, old_counts = 0;
    qDebug() << thread() << currentThread();
    while(1)
    {
        msleep(50);
        counts = 50;//Read_DPC();
        if(counts != old_counts)
        {
            emit currentCount(counts);
            old_counts = counts;
        }

    }
}

qreal runScan(qreal start, qreal stop, qreal speed, qreal MonoPosOrig, bool direction)
{
    int steps = 0;
    qreal currentCounts = 0;
    qreal MonoPos = MonoPosOrig;
    if(speed > fabs(stop - start))
        steps = 1;
    else
        steps = (int)(fabs(stop-start)/speed) + 1;
    for(int i = 0; i < steps; i++)
    {
        direction?MonoOpp(((steps==1)||(i == (steps - 1)))?(int)(fabs(stop-start)):speed, MonoPos):MonoNed((steps==1)?(int)(fabs(stop-start)):speed, MonoPos);
        currentCounts = Read_DPC();
    }
    return MonoPos;
}

scanner::scanner(qreal start_pos, qreal stop_pos, qreal _speed, qreal _MonoPosOrig, bool _direction)
{
    scanner::startpos = start_pos;
    scanner::stoppos = stop_pos;
    scanner::speed = _speed;
    scanner::MonoPos = _MonoPosOrig;
    scanner::direction = _direction;
}

void scanner::run()
{
    int steps = 0;
    //qreal MonoPos = scanner::MonoPos;
    qDebug() << thread() << currentThread();
    qreal currentCount = 0;
    if(scanner::speed > fabs(scanner::stoppos - scanner::startpos))
        steps = 1;
    else
        steps = (int)(fabs(scanner::stoppos-scanner::startpos)/scanner::speed) + 1;
    for(int i = 0; i < steps; i++)
    {
        //For debug disabled//Not anymore
        direction?1:0;//MonoOpp(((steps==1)||(i == (steps - 1)))?(int)(fabs(stop-start)):speed, MonoPos):MonoNed((steps==1)?(int)(fabs(stop-start)):speed, MonoPos);
        currentCount = Read_DPC();
        usleep(50000);//For Debug
        emit scanner::currentStatus(((qreal)(i)/steps)*100);
    }
}

ScanList::ScanList()
{
    currentScan = -1;
}

void ScanList::addScan(Scan newScan)
{
    ScanList::Scans.push_back(newScan);
    currentScan++;
}

void ScanList::dropScan(void)
{
    ScanList::Scans.remove(ScanList::currentScan);
    currentScan = currentScan - 1;
}

int ScanList::getScanNumbers(void)
{
    return ScanList::Scans.size();
}

Scan ScanList::getCurrentScan(void)
{
    if(!Scans.isEmpty())
        return Scans[currentScan];
}

Scan ScanList::getNextScan(void)
{
    if(!Scans.isEmpty())
        if(ScanList::currentScan + 2 >= Scans.size())
        {
            currentScan = 0;
            return Scans[0];
        }
        else
        {
            currentScan += 1;
            return Scans[currentScan];
        }
}

Scan ScanList::getLastScan(void)
{
    if(!Scans.isEmpty())
    {
        if(ScanList::currentScan == 0)
        {
            currentScan = Scans.size() - 1;
            return Scans[currentScan];
        }
        else
        {
            currentScan -= 1;
            return Scans[currentScan];
        }
    }
}

Scan & ScanList::getScan(qint32 ScanNumber)
{
    if(!Scans.isEmpty())
        if(ScanNumber >= 0 && ScanNumber < Scans.size())
            return Scans[ScanNumber];
}

void ScanList::setFileName(QString fileName)
{
    ScanList::fileName = fileName;
}

QString ScanList::getFileName(void)
{
    return ScanList::fileName;
}

QVector<QString> ScanList::getFileNames(void)
{
    return ScanList::scanFileNames;
}

void ScanList::addFileName(QString fileName)
{
    ScanList::scanFileNames.push_back(fileName);
}

void ScanList::deleteFileName(QString fileName)
{
    for(int i = 0; i < ScanList::scanFileNames.size(); i++)
    {
        if(ScanList::scanFileNames[i] == fileName)
        {
            ScanList::scanFileNames.remove(i);
            return;
        }
    }
}

Spectrometer::Spectrometer()
{
    for(int i = 0; i < 3; i++)
        polarizerSetting.push_back(false);
}

void Spectrometer::setMonoPos(qreal MonoPos)
{
    Spectrometer::MonoPos = MonoPos;
}

qreal & Spectrometer::getMonoPos(void)
{
    return Spectrometer::MonoPos;
}

void Spectrometer::setMonoSpeed(qreal MonoSpeed)
{
    Spectrometer::MonoSpeed = MonoSpeed;
}

qreal & Spectrometer::getMonoSpeed(void)
{
    return Spectrometer::MonoSpeed;
}

void Spectrometer::setPolarizers(QVector<bool> polarizers)
{
    if(polarizers.size() != 3)
        return;
    else
    {
        Spectrometer::polarizerSetting[0] = polarizers[0];
        Spectrometer::polarizerSetting[1] = polarizers[1];
        Spectrometer::polarizerSetting[2] = polarizers[2];
    }
}

bool Spectrometer::getPolarizers(Polarizer pol)
{
    return Spectrometer::polarizerSetting[pol];
}

QVector<bool> Spectrometer::getPolarizers()
{
    return Spectrometer::polarizerSetting;
}

void Spectrometer::setMonoPosSlot(qreal MonoPos)
{
    Spectrometer::MonoPos = MonoPos;
}

void Spectrometer::setMonoSpeedSlot(qreal MonoSpeed)
{
    Spectrometer::MonoSpeed = MonoSpeed;
}

void Spectrometer::setPolarizersSlot(Polarizer pol, bool state)
{
    Spectrometer::polarizerSetting[pol] = state;
}
