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
#include <QDate>
#include <sstream>

int read_DPC(void);

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
    qreal MonoPos;
    //Something to add?
};

//class DataProcessingThread : public QThread
//{
//public:
//    void run();
//signals:
//    void currentCount(int);
//};

//void DataProcessingThread::run()
//{
//    while(1)
//    {
//        usleep(50);
//        emit currentCount(read_DPC());
//    }
//}

void read_unformatted_file(Scan &Data, const QString &fileName);
void write_unformatted_file(const Scan &Data, QString fileName);
void write_log_file(const Scan &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<qreal, qreal> &outdata);

#endif // ADD_FUNCTIONS_H
