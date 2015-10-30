#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
//#define _GLIBCXX_USE_NANOSLEEP

#include <cstring>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <vector>
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <termios.h>
#include <ctype.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cmath>
#include <memory>

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>
#include <QThread>
#include <QDebug>
#include <QFileDialog>
#include <QDialogButtonBox>

#include "scan.h"

void read_unformatted_file(Scan &Data, const QString &fileName);
void write_unformatted_file(const Scan &Data, QString fileName);
void write_log_file(const Scan &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<std::tuple<qreal, qreal, qreal> > &indata, QMap<double, double> &outdata, bool Valueposition);

inline double convertWNtoWL(double input)
{
    return 10000000/input;
}

inline double convertWLtoWN(double input)
{
    return 10000000/input;
}

inline double convertPosToWN(double input)
{
    return input*0.0048;
}

inline double convertWNtoPos(double input)
{
    return input/0.0048;
}

inline double convertPosToWL(double input)
{
    return convertWNtoWL(convertPosToWN(input));
}

inline double convertWLtoPos(double input)
{
    return convertWNtoPos(convertWLtoWN(input));
}

#endif // ADD_FUNCTIONS_H
