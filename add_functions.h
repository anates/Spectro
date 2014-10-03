#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <fstream>
#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

void read_unformatted_file(QMap<double, double> &Data, QString fileName);
void write_unformatted_file(const QMap<double, double> &Data, QString fileName);

#endif // ADD_FUNCTIONS_H
