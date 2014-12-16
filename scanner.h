#ifndef SCANNER_H
#define SCANNER_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QDebug>
#include <QPair>
#include <unistd.h>
#include "dpc.h"
//#include <dpc.h>



class Scanner_Worker:public QObject
{
    Q_OBJECT
private:
    bool ScanRunning;
    int counts = 0;
    int number_of_rounds = 0;
    QMutex *MovingMutex;
    QWaitCondition *MovingCond;
    counterData *Data;
public slots:
    void runScan(int steps, int accuracy);
    void stopScan(void);
    void currentCounts(int counts);
signals:
    void ScanFinished(void);
    void currentPosition(qreal position);
    void currentData(QPair<int, int>);
    void moveStep(void);
public:
    Scanner_Worker(QMutex *_MovingMutex, QWaitCondition *_MovingCond, counterData *data);
};


class Scanner_Master:public QObject
{
    Q_OBJECT
    QThread workerThread;
private:
    bool doScan = false;
    int startpos, stoppos, accuracy;
    int MonoPos;
    int MonoPosOrig;
    bool direction;
    volatile bool stopScanDevice = false;
private slots:
    //Internal

    void currentData(QPair<int, int> data);
    void moveStep(void);
    void scanIsFinished(void);
    void currentPosition(qreal position);
public slots:
    //External
    void interruptScan(void);
    void currentCounts(int counts);
    void runScan(int start, int stop, int accuracy);
signals:
    //Internal
    void runScanWorker(int, int);
    void currentCountsToWorker(int);
    //External
    void currentDataToExt(QPair<int, int>);
    void moveStepperToTarget(int, int);
    void scanFinished(void);
    void scanInterrupted(void);
    void scanCurrentPosition(qreal position);
//    void moveStepUp(void);
//    void moveStepDown(void);
//    void currentValue(qreal, qreal);
//    void moveToPosition(int, int);
public:
    Scanner_Master(QMutex *MovingMutex, QWaitCondition *MovingCond, counterData *data);
    ~Scanner_Master();
    //void resetScanner(void);

};


#endif // SCANNER_H
