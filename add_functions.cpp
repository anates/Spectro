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
    if(version == "8008135")
    {
        Data.startPos = in.readLine().toDouble();
        Data.finPos = in.readLine().toDouble();
        Data.scanSpeed = in.readLine().toDouble();
        int polSettingsInt = in.readLine().toInt();
        Data.polSettings[0] = (polSettingsInt%2 == 1);
        Data.polSettings[1] = (polSettingsInt%2 == 0 && polSettingsInt != 4);
        Data.polSettings[2] = (polSettingsInt >= 4);
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
    file.close();
}

void write_unformatted_file(const Scan &Data/*const QMap<double, double> &Data*/, QString fileName)//Muss dringend geupdatet werden???
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);
    out << "8008135\n";
    out << Data.startPos << '\n';
    out << Data.finPos << '\n';
    out << Data.scanSpeed << '\n';
    out << (int)(Data.polSettings[0]?1:0) + (int)(Data.polSettings[1]?2:0) + (int)(Data.polSettings[2]?4:0) << '\n';
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
