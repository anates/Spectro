#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
#define _GLIBCXX_USE_NANOSLEEP

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
#include <QFileDialog>
#include <QDialogButtonBox>

#define ACCURACY 10

enum AveMode{ NoAverage, Point, Intervall };
enum Polarizer{xPol = 0, yPol = 1, zPol = 2};
Q_DECLARE_METATYPE(Polarizer);

class ScanData
{
public:
    QVector<QPair<qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;

    void clear(void);
};

class LogFile
{
public:
    bool logfileSet = false;
    QString name = "";
    qreal laserIntensity = 0;
    qreal slitWidth = 0;
    qreal sensitivity = 0;
    qreal countNumber = 0;

    void clear(void);
};

class ScanParams
{
public:
    qreal startPos;
    qreal finPos;
    qreal scanSpeed;
    QVector<bool> polSettings;

    void clear();
    ScanParams();
};

class Scan
{
public:
    ScanData values;
    QString scanName;
    ScanParams Params;
    AveMode av;
    LogFile log;
    bool readonly = false;
    bool isLoaded = false;

    void clear(void);
    Scan();
};

class ScanList: public QObject
{
    Q_OBJECT
private:
    QVector<Scan> Scans;
    QString fileName;
    QVector<QString> scanFileNames;
    qint32 currentScan;
public:
    ScanList();
    void addScan(Scan newScan);
    void dropScan(void);
    int getScanNumbers(void);
    int getCurrentScanNumber(void);
    Scan &getCurrentScan(void);
    Scan getNextScan(void);
    Scan getLastScan(void);
    Scan & getScan(qint32 ScanNumber);
    void setFileName(QString fileName);
    void setCurrentScan(int ScanNumber);
    QString getFileName(void);
    QVector<QString> getFileNames(void);
    void addFileName(QString fileName);
    void deleteFileName(QString fileName);
};

class Spectrometer: public QObject
{
    Q_OBJECT
private:
    qreal MonoPos = 0;
    qreal MonoSpeed = 0;
    QVector<bool> polarizerSetting;
public slots:
    void setMonoPosSlot(qreal MonoPos);
    void setMonoSpeedSlot(qreal MonoSpeed);
    void setPolarizersSlot(Polarizer pol, bool state);
public:
    Spectrometer();
    void setMonoPos(qreal MonoPos);
    qreal & getMonoPos(void);
    void setMonoSpeed(qreal MonoSpeed);
    qreal & getMonoSpeed(void);
    void setPolarizers(QVector<bool> polarizers);
    void setPolarizers(Polarizer pol, bool state);
    bool getPolarizers(Polarizer pol);
    QVector<bool> getPolarizers(void);
    //Something to add?
};

int Read_DPC(void);
void read_unformatted_file(Scan &Data, const QString &fileName);
void write_unformatted_file(const Scan &Data, QString fileName);
void write_log_file(const Scan &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<double, double> &outdata);

//New inserted from Monokrom
void MonoOpp(const qreal step, qreal &MonoPos);
void MonoNed(const qreal step, qreal &MonoPos);
void moveToTarget(const double &NewMonoPos, qreal &MonoPos);

class DPC: public QThread
{
    Q_OBJECT
private:
    bool runThread;
public:
    DPC();
    void run();
public slots:
    void cancelThread(void);
signals:
    void currentCount(int);
};

class scanner: public QThread
{
    Q_OBJECT
private:
    bool doScan = false;
    qreal startpos, stoppos, speed;
    qreal MonoPos;
    qreal MonoPosOrig;
    bool direction;
    volatile bool stopScanDevice = false;
public slots:
    void cancelScan(void);
    void runScan(void);
    void stopScanner(void);
    void init(qreal start_pos, qreal stop_pos, qreal _speed, qreal _MonoPosOrig, bool _direction);
public:
    void resetScanner(void);
    void run();
    void scan();
signals:
    void currentStatus(qreal);
    void scanFinished(void);
    void scanInterrupted(void);
    void moveStepUp(void);
    void moveStepDown(void);
    void currentValue(qreal, qreal);
    void moveToPosition(qreal, qreal, bool);
};

class Spec_Control: public QThread
{
    Q_OBJECT
private:
    QVector<bool> polState;
    qreal MonoPos;
    volatile bool control;
public slots:
    void movePolarizer(Polarizer pol, bool state);
    void moveStepMotor(qreal CurrentPos, qreal newPos, bool dir);
    void moveUp(void);
    void moveDown(void);
    void stopControl(void);
public:
    Spec_Control(qreal MonoPos);
    void run();
signals:
    void movedPolarizer(Polarizer, bool);
    void movedStepper(qreal);
    void movedStepperTX(bool);
    void movedPolarizerTX(int);
};

#endif // ADD_FUNCTIONS_H
