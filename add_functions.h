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

#include "../BlackLib/v2_0/BlackGPIO.h"

#define ACCURACY 10

void read_unformatted_file(Scan &Data, const QString &fileName);
void write_unformatted_file(const Scan &Data, QString fileName);
void write_log_file(const Scan &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<double, double> &outdata);

//New inserted from Monokrom
void MonoOpp(const qreal step, qreal &MonoPos);
void MonoNed(const qreal step, qreal &MonoPos);
void moveToTarget(const double &NewMonoPos, qreal &MonoPos);



#endif // ADD_FUNCTIONS_H
