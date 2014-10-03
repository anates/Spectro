#include "add_functions.h"

void read_unformatted_file(QMap<double, double> &Data, QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);

    while(!in.atEnd()) {
        //QMessageBox::information(0, "Info", "In while-loop");
        QString line = in.readLine();
        //QMessageBox::information(0, "Info", line);
        QStringList fields = line.split("  ");
        Data[fields[0].toDouble()] = fields[1].toDouble();
        //QMessageBox::information(0, "Info", fields[0]);
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
