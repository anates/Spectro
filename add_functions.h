#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H

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

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>
#include <QThread>
#include <QDebug>

//int read_DPC(void);

enum AveMode{ NoAverage, Point, Intervall };

struct ScanData
{
    QVector<QPair<qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;
};

struct LogFile
{
    bool logfileSet = false;
    QString name = "";
    qreal laserIntensity = 0;
    qreal slitWidth = 0;
    qreal sensitivity = 0;
    qreal countNumber = 0;
};

struct Scan
{
    ScanData values;
    QVector<bool> polSettings = {false, false, false};
    QString scanName;
    qreal startPos;
    qreal finPos;
    qreal scanSpeed;
    AveMode av;
    LogFile log;
};

struct ScanList
{
    QVector<Scan> Scans;
    QString fileName;
    QVector<QString> scanFileNames;
};

struct Spectrometer
{
    qreal MonoPos = 0;
    qreal MonoSpeed = 0;
    //Something to add?
};

int Read_DPC(void);
void read_unformatted_file(Scan &Data, const QString &fileName);
void write_unformatted_file(const Scan &Data, QString fileName);
void write_log_file(const Scan &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<qreal, qreal> &outdata);

//New inserted from Monokrom
void MonoOpp(const qreal step, qreal &MonoPos);
void MonoNed(const qreal step, qreal &MonoPos);
void moveToTarget(const double &NewMonoPos, qreal &MonoPos);

class DPC: public QThread
{
    Q_OBJECT
public:
    void run();
signals:
    void currentCount(int);
};

class scanner: public QThread
{
    Q_OBJECT
public:
    void start(qreal start, qreal stop, qreal speed, qreal &MonoPosOrig, bool direction);
signals:
    void currentStatus(qreal);
};

#endif // ADD_FUNCTIONS_H
