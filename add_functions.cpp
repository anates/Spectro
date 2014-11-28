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
            Data.Params.startPos = in.readLine().toDouble();
            Data.Params.finPos = in.readLine().toDouble();
            Data.Params.scanSpeed = in.readLine().toDouble();
            int polSettingsInt = in.readLine().toInt();
            Data.Params.polSettings[0] = (polSettingsInt%2 == 1);
            Data.Params.polSettings[1] = (polSettingsInt == 3 || polSettingsInt > 5);
            Data.Params.polSettings[2] = (polSettingsInt >= 4);
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
    {
        Data.scanName = fileName;
    }
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
    if(Data.Params.startPos == -1)
    {
        Data.Params.startPos = Data.values.Data.first().first;
    }
    if(Data.Params.finPos == -1)
    {
        Data.Params.finPos = Data.values.Data.last().first;
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
    out << Data.Params.startPos << '\n';
    out << Data.Params.finPos << '\n';
    out << Data.Params.scanSpeed << '\n';
    int polarSettings = Data.Params.polSettings[0];
    polarSettings += Data.Params.polSettings[1]?2:0;
    polarSettings += Data.Params.polSettings[2]?4:0;
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

void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<double, double> &outdata)//Assumes that all values are already ordered
{
    for(int i = 0; i < indata.size(); i++)
    {
        outdata[indata[i].first] = indata[i].second;
    }
}

void ScanParams::clear(void)
{
    ScanParams::finPos = 0;
    ScanParams::scanSpeed = 0;
    ScanParams::startPos = 0;
    ScanParams::polSettings[0] = false;
    ScanParams::polSettings[1] = false;
    ScanParams::polSettings[2] = false;
}

void ScanData::clear(void)
{
    ScanData::Data.clear();
    ScanData::FWHM.clear();
    ScanData::Maxima.clear();
}

void LogFile::clear(void)
{
    LogFile::countNumber = 0;
    LogFile::laserIntensity = 0;
    LogFile::logfileSet = false;
    LogFile::name = "";
    LogFile::sensitivity = 0;
    LogFile::slitWidth = 0;
}

void Scan::clear(void)
{
    Scan::av = NoAverage;
    Scan::log.clear();
    Scan::Params.clear();
    Scan::readonly = false;
    Scan::scanName = "";
    Scan::isLoaded = false;
    Scan::values.clear();
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

DPC::DPC()
{
    DPC::runThread = true;
    /*DPC::A[0] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_32, BlackLib::input));
    /*DPC::A[1] = new B*/A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_33, BlackLib::input));
    /*DPC::A[2] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_34, BlackLib::input));
    /*DPC::A[3] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_35, BlackLib::input));
    /*DPC::A[4] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_36, BlackLib::input));
    /*DPC::A[5] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_37, BlackLib::input));
    /*DPC::A[6] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_38, BlackLib::input));
    /*DPC::A[7] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_39, BlackLib::input));

    /*DPC::B[0] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_65, BlackLib::input));
    /*DPC::B[1] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_66, BlackLib::input));
    /*DPC::B[2] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_67, BlackLib::input));
    /*DPC::B[3] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_68, BlackLib::input));
    /*DPC::B[4] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_69, BlackLib::input));
    /*DPC::B[5] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_72, BlackLib::input));
    /*DPC::B[6] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_73, BlackLib::input));
    /*DPC::B[7] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_74, BlackLib::input));

    /*DPC::C[0] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_2, BlackLib::input));
    /*DPC::C[1] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_3, BlackLib::input));
    /*DPC::C[2] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_4, BlackLib::input));
    /*DPC::C[3] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_5, BlackLib::input));
    /*DPC::C[4] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_10, BlackLib::input));
    /*DPC::C[5] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_11, BlackLib::input));
//    //DPC::C[6] = new BlackLib::BlackGPIO(BlackLib::I2C_0, BlackLib::input);
//    //DPC::C[7] = new BlackLib::BlackGPIO(BlackLib::I2C_1, BlackLib::input);
//    //qDebug() << "DPC: " << thread() << currentThread();
}

DPC::~DPC()
{
    qDebug() << "Clearing up DPC!";
    //delete[] *(DPC::A);
    //qDebug() << "Cleared A";
    //delete[] *DPC::B;
    //delete[] *DPC::C;
    //qDebug() << "Finished clearing up DPC!";
}

void DPC::run()
{
    int counts = 0, old_counts = 0;
    //qDebug() << thread() << currentThread();
    while(DPC::runThread)
    {
        msleep(50);
        counts = 50;//Read_DPC();
        if(counts != old_counts)
        {
            emit currentCount(counts);
            old_counts = counts;
        }

    }
    //if(runThread == false)
        //qDebug() << "Counting should stop";
}

void DPC::cancelThread(void)
{
    DPC::runThread = false;
}

//qreal runScan(qreal start, qreal stop, qreal speed, qreal MonoPosOrig, bool direction)//deprecated, not used anymore
//{
//    int steps = 0;
//    qreal currentCounts = 0;
//    qreal MonoPos = MonoPosOrig;
//    if(speed > fabs(stop - start))
//        steps = 1;
//    else
//        steps = (int)(fabs(stop-start)/speed) + 1;
//    for(int i = 0; i < steps; i++)
//    {
//        direction?MonoOpp(((steps==1)||(i == (steps - 1)))?(int)(fabs(stop-start)):speed, MonoPos):MonoNed((steps==1)?(int)(fabs(stop-start)):speed, MonoPos);
//        currentCounts = Read_DPC();
//    }
//    return MonoPos;
//}

void scanner::init(int start_pos, int stop_pos, int _accuracy, int _MonoPosOrig, bool _direction)
{
    //qDebug() << "Scanner: " << thread() << QThread::currentThread();
    scanner::doScan = true;
    scanner::startpos = start_pos;
    scanner::stoppos = stop_pos;
    scanner::accuracy = _accuracy;
    scanner::MonoPos = _MonoPosOrig;
    scanner::MonoPosOrig = _MonoPosOrig;
    scanner::direction = _direction;
    //qDebug() << "Scanner has been initialized with Monopos: " << scanner::MonoPos << " and " << scanner::startpos;
    emit moveToPosition(scanner::MonoPos, scanner::startpos);
    //qDebug() << "Returning to main thread";
}

void scanner::runScan()
{
    doScan = true;
    scanner::scan();
}

void scanner::run()
{
    while(stopScanDevice == false)
    {
        msleep(50);
        if(scanner::doScan)
            scan();
    }
}

void scanner::scan()
{
    //qreal MonoPos = scanner::MonoPos;
    //qDebug() << "From scanner::run(): " << thread() << currentThread();//Sei speed als Verweildauer pro Punkt definiert
    qreal currentCount = 0;
    qreal length = fabs(scanner::startpos - scanner::stoppos);
    for(int i = 0; i < length; i++)
    {
        if(doScan == false)
        {
            scanner::resetScanner();
            break;
        };
        //For debug disabled//Not anymore
        if(direction)
            emit scanner::moveStepUp();
        else
            emit scanner::moveStepDown();
        for(int j = 0; j < ((accuracy <= 1 )? 1 : accuracy); j++)
            currentCount += Read_DPC();
        usleep(50000);//For Debug
        emit scanner::currentStatus(((qreal)(i)/length)*100);
        emit scanner::currentValue(i + scanner::startpos, currentCount);
        currentCount = 0;
        //qDebug() << "Current count: " << ((qreal)(i)/length)*100;
    }
    //qDebug() << "Scan Finished";
    doScan = false;
    emit scanFinished();
}

void scanner::resetScanner(void)
{
    emit moveToPosition(scanner::MonoPos, scanner::MonoPosOrig);
    emit scanInterrupted();
}

void scanner::cancelScan(void)
{
    scanner::doScan = false;
}

void scanner::stopScanner(void)
{
    stopScanDevice = true;
}

ScanParams::ScanParams()
{
    for(int i = 0; i < 3; i++)
        ScanParams::polSettings.push_back(false);
    ScanParams::finPos = 0;
    ScanParams::scanSpeed = 0;
    ScanParams::startPos = 0;
}

Scan::Scan()
{
    Scan::isLoaded = false;
    Scan::log.clear();
    Scan::Params.clear();
    Scan::readonly = false;
    Scan::scanName = "";
    Scan::values.clear();
}

ScanList::ScanList()
{
    //qDebug() << "ScanList: " << thread() << QThread::currentThread();
    ScanList::currentScan = 0;
    ScanList::fileName = "";
    ScanList::scanFileNames.clear();
    ScanList::Scans.clear();
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

int ScanList::getCurrentScanNumber(void)
{
    return ScanList::currentScan;
}

Scan & ScanList::getCurrentScan(void)
{
    if(!Scans.isEmpty())
        return Scans[currentScan];
}

Scan ScanList::getNextScan(void)
{
    if(!Scans.isEmpty())
    {
        if(ScanList::currentScan + 1 == Scans.size())
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

void ScanList::setCurrentScan(int ScanNumber)
{
    ScanList::currentScan = (ScanNumber >= 0 && ScanNumber < ScanList::getScanNumbers())?ScanNumber:ScanList::currentScan;
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
    //qDebug() << "Spectrometer: " << thread() << QThread::currentThread();
    for(int i = 0; i < 3; i++)
        polarizerSetting.push_back(false);
    Spectrometer::MonoPos = 0;
    Spectrometer::MonoSpeed = 0;
}

void Spectrometer::setMonoPos(int MonoPos)
{
    Spectrometer::MonoPos = MonoPos;
}

int & Spectrometer::getMonoPos(void)
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

void Spectrometer::setPolarizers(Polarizer pol, bool state)
{
    Spectrometer::polarizerSetting[pol] = state;
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

Spec_Control::Spec_Control(int MonoPos)
{
    for(int i = 0; i < 3; i++)
    {
        Spec_Control::polState.push_back(false);
    }
    Spec_Control::MonoPos = MonoPos;
    Spec_Control::control = true;
    Spec_Control::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_120, BlackLib::output));
    Spec_Control::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_121, BlackLib::output));
    Spec_Control::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_122, BlackLib::output));
    Spec_Control::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_123, BlackLib::output));
    Spec_Control::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_117, BlackLib::output));
    //Spec_Control::POL[5] = new BlackLib::BlackGPIO(BlackLib::GPIO_115, BlackLib::output);

    Spec_Control::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_86, BlackLib::output));
    Spec_Control::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_87, BlackLib::output));
    Spec_Control::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_88, BlackLib::output));
    Spec_Control::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_89, BlackLib::output));
    //qDebug() << "SpecControl: " << thread() << QThread::currentThread();
}

Spec_Control::~Spec_Control()
{
    qDebug() << "Clearing up Spec_control";
}

void Spec_Control::run()
{
    bool i = false;
    while(control)
    {
        msleep(50);
        i = !i;
    }
}

void Spec_Control::movePolarizer(Polarizer pol, bool state)
{
    //connect to pins is missing, has to be done###
    //Connections done, but I have no clue which pin connects to which polarizer...
    int pol_intValue = Spec_Control::polState[0]*1 + Spec_Control::polState[1]*2 + Spec_Control::polState[2]*4;
    emit movedPolarizerTX(pol_intValue);
    emit movedPolarizer(pol, state);
}

void Spec_Control::moveStepMotor(int CurrentPos, int newPos)
{
    //qDebug() << "Now a signal from moveStepMotor should be emitted" << thread() << QThread::currentThread();

    bool dir = (newPos - CurrentPos) >= 0;
    for(int i = 0; i < fabs(CurrentPos-newPos); i++)
    {
        if(dir)
        {
            Spec_Control::moveUp();
            emit movedStepper(Spec_Control::MonoPos);
            //MonoPos++;//Only for debug, after MonoOpp is not working at the moment###
        }
        else
        {
            Spec_Control::moveDown();//MonoNed(1, Spec_Control::MonoPos);
            emit movedStepper(Spec_Control::MonoPos);
            //MonoPos--;//Only for debug, after MonoOpp is not working at the moment###
        }
    }
    //qDebug() << "Current position of Stepper should be: " << Spec_Control::MonoPos;7
    emit movedStepperTX(dir);
    emit movedStepper(Spec_Control::MonoPos);
}

void Spec_Control::moveUp(void)
{
    //MonoOpp(1, Spec_Control::MonoPos);//For debug disabled###
    Spec_Control::STP[1]->setValue(BlackLib::high);
    Spec_Control::STP[0]->setValue(BlackLib::high);
    msleep(50);
    qDebug() << "Stepper moved for one step!";
    Spec_Control::STP[0]->setValue(BlackLib::low);
    Spec_Control::MonoPos++;
    emit movedStepperTX(true);
    emit movedStepper(Spec_Control::MonoPos);
}

void Spec_Control::moveDown(void)
{
    //MonoNed(1, Spec_Control::MonoPos);//For debug disabled###
    Spec_Control::STP[1]->setValue(BlackLib::low);
    Spec_Control::STP[0]->setValue(BlackLib::high);
    msleep(50);
    qDebug() << "Stepper moved for one step!";
    Spec_Control::STP[0]->setValue(BlackLib::low);
    Spec_Control::MonoPos--;
    emit movedStepperTX(false);
    emit movedStepper(Spec_Control::MonoPos);
}

void Spec_Control::stopControl(void)
{
    control = false;
}
