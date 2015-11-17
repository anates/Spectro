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
    Data.hasWN = false;
    if(linecheck.size() != 3)
    {
        if(version == "8008135" || version == "80081E5" || version == "B0081E5" || version == "130081E5" || version == "B0O81ES")
        {
            qDebug() << "First data check!";
            Data.scanName = in.readLine();
            Data.Params.startPos = in.readLine().toDouble();
            Data.Params.finPos = in.readLine().toDouble();
            Data.Params.scanSpeed = in.readLine().toDouble();
            int polSettingsInt = in.readLine().toInt();
            Data.Params.polSettings[0] = (polSettingsInt%2 == 1);
            Data.Params.polSettings[1] = (polSettingsInt == 3 || polSettingsInt > 5);
            Data.Params.polSettings[2] = (polSettingsInt >= 4);
        }
        if(version == "80081E5" || version == "B0081E5" || version == "130081E5")
        {
            qDebug() << "Second data check!";
            Data.log.countNumber = in.readLine().toDouble();
            Data.log.laserIntensity = in.readLine().toDouble();
            Data.log.name = in.readLine();
            Data.log.sensitivity = in.readLine().toDouble();
            Data.log.oldSlit = in.readLine().toDouble();
            Data.log.logfileSet = true;
        }
        if(version == "B0O81ES")
        {
            Data.log.laserIntensity = in.readLine().toDouble();
            Data.log.name = in.readLine();
            Data.log.sensitivity = in.readLine().toDouble();
            QString slitwidth = in.readLine();
            QStringList slits = slitwidth.split('\t');
            if(slits.length() == 4)
                if(Data.log.slits.length() == 4)
                {
                    Data.log.slits[0] = slits[0].toDouble();
                    Data.log.slits[1] = slits[1].toDouble();
                    Data.log.slits[2] = slits[2].toDouble();
                    Data.log.slits[3] = slits[3].toDouble();
                }
                else
                {
                    Data.log.slits[0] = slits[0].toDouble();
                    Data.log.slits[1] = slits[0].toDouble();
                    Data.log.slits[2] = slits[0].toDouble();
                    Data.log.slits[3] = slits[0].toDouble();
                }
            else
            {
                Data.log.slits[0] = slits[0].toDouble();
                Data.log.slits[1] = slits[0].toDouble();
                Data.log.slits[2] = slits[0].toDouble();
                Data.log.slits[3] = slits[0].toDouble();
            }
            Data.log.logfileSet = true;
            Data.Central_WL = in.readLine().toDouble();
            Data.hasWN = true;
        }
        if(version == "B0081E5" || version == "130081E5")
        {
            qDebug() << "Third data check!";
            Data.isCalibrated = (bool)in.readLine().toInt();
        }
        if(version == "130081E5")
        {
            qDebug() << "Fourth data check!";
            Data.Central_WL = in.readLine().toDouble();
            Data.hasWN = true;
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
        if(version == "130081E5" || version == "B0O81ES")
        {
            if(tmpline.size() == 4)
                Data.values.Data.push_back(std::make_tuple(convertToNumber<qreal>(tmpline[0]), convertToNumber<qreal>(tmpline[1]), convertToNumber<qreal>(tmpline[2])));
        }
        else
        {
            if(tmpline.size() == 3)
                Data.values.Data.push_back(std::make_tuple(convertToNumber<qreal>(tmpline[0]), 0, convertToNumber<qreal>(tmpline[1])));
        }
    }
    if(Data.Params.startPos == -1)
    {
        Data.Params.startPos = std::get<0>(Data.values.Data.first());
    }
    if(Data.Params.finPos == -1)
    {
        Data.Params.finPos = std::get<0>(Data.values.Data.last());
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
    out << "Slit width [mm]: " << Data.log.oldSlit << '\n';
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
    out << "B0O81ES\n";//Update auf v0.5, reformatted log file
    out << Data.scanName << '\n';
    out << Data.Params.startPos << '\n';
    out << Data.Params.finPos << '\n';
    out << Data.Params.scanSpeed << '\n';
    int polarSettings = Data.Params.polSettings[0];
    polarSettings += Data.Params.polSettings[1]?2:0;
    polarSettings += Data.Params.polSettings[2]?4:0;
    out << polarSettings << '\n';//(int)(Data.polSettings[0]?1:0) + (int)(Data.polSettings[1]?2:0) + (int)(Data.polSettings[2]?4:0) << '\n';
    out << Data.log.laserIntensity << '\n';
    out << Data.log.name << '\n';
    out << Data.log.sensitivity << '\n';
    out << Data.log.slits[0] << '\t' << Data.log.slits[1] << '\t' << Data.log.slits[2] << '\t' << Data.log.slits[3] << '\t' << '\n';
    out << Data.Central_WL << '\n';
    out << std::get<0>(Data.values.Data[0]) << '\t' << std::get<2>(Data.values.Data[0]) << '\n';
    for(int i = 0; i < Data.values.Data.size(); i++)
    {
        out << std::get<0>(Data.values.Data[i]) << '\t' << std::get<1>(Data.values.Data[i]) << '\t' << std::get<2>(Data.values.Data[i]) << '\n';
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

void vectorToMap(const QVector<std::tuple<qreal, qreal, qreal> > &indata, QMap<double, double> &outdata, bool Valueposition)//Assumes that all values are already ordered
{
    if(Valueposition)
        for(int i = 0; i < indata.size(); i++)
        {
            outdata[std::get<1>(indata[i])] = std::get<2>(indata[i]);
        }
    else
        for(int i = 0; i < indata.size(); i++)
        {
            outdata[std::get<0>(indata[i])] = std::get<2>(indata[i]);
        }
}

inline double getAverage(const QVector<double> indata)
{
    double res = 0;
    for(int i = 0; i < indata.size(); i++)
    {
        res += indata[i];
    }
    res/= indata.size();
    return res;
}

void walkingAverage(int length, const QMap<double, double> &indata, QMap<double, double> &outdata)
{
    if(length > indata.size())
        length = indata.size()-1;
    for(int i = 0; i < indata.size(); i++)
    {
        if((i - length) < 0)
        {
            QVector<double> vec;
            int x0 = 0;
            int x1 = i + length;
            for(int j = x0; j < x1; j++)
            {
                vec.push_back(indata.value(j));
            }
            outdata[indata.key(i)] = getAverage(vec);
        }
        else if((i+length) > indata.size()-1)
        {
            QVector<double> vec;
            int x0 = i-length;
            int x1 = indata.size()-1;
            for(int j = x0; j < x1; j++)
            {
                vec.push_back(indata.value(j));
            }
            outdata[indata.key(i)] = getAverage(vec);
        }
        else
        {
            QVector<double> vec;
            int x0 = i-length;
            int x1 = i+length;
            for(int j = x0; j < x1; j++)
            {
                vec.push_back(indata.value(j));
            }
            outdata[indata.key(i)] = getAverage(vec);
        }
    }
    qDebug() << "Walking Average calculated!";
}

void bicubicAverage(const QMap<double, double> &indata, QMap<double, double> outdata)
{
    //temporary support before implementing function
    outdata = indata;
}

void splineAverage(const QMap<double, double> &indata, QMap<double, double> outdata)
{
    //temporary support
    outdata = indata;
}

void calculateInterpolation(const QMap<double, double> &indata, QMap<double, double> &outdata, interpolMethods method, const int interpolVariable = 0)
{
    switch(method)
    {
        case walking:
        {
            walkingAverage(interpolVariable, indata, outdata);
            break;
        }
        case bicubic:
        {
            bicubicAverage(indata, outdata);
            break;
        }
        case spline:
        {
            splineAverage(indata, outdata);
            break;
        }
        default:
            break;
    }
}
