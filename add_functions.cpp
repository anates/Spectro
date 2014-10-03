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
        QVector<double> tmp_input;
        if(line.split(" ").size() == 7)
        {
            tmp_input.push_back(line.split(" ")[3].toDouble());
            tmp_input.push_back(line.split(" ")[6].toDouble());
        }
        if(tmp_input.size() == 2)
            Data[tmp_input[0]] = tmp_input[1];
        tmp_input.clear();
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
