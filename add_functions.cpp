#include "add_functions.h"

void read_unformatted_file(QMap<double, double> &Data, QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QPair<double, double> valuePair;
        splitToDoubles(valuePair, line);
        Data[valuePair.first] = valuePair.second;
    }
    file.close();
}

void write_unformatted_file(const QMap<double, double> &Data, QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream out(&file);

    QVector<double> x, y;
    x = QVector<double>::fromList(Data.keys());
    y = QVector<double>::fromList(Data.values());
    for(int i = 0; i < Data.size(); i++)
    {
        out << x[i] << '\t' << y[i] << '\n';
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
