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
#include <sstream>

void read_unformatted_file(QMap<double, double> &Data, QString fileName);
void write_unformatted_file(const QMap<double, double> &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);


#endif // ADD_FUNCTIONS_H
