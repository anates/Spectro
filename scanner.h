#ifndef SCANNER_H
#define SCANNER_H
#include <QThread>
#include <QPair>

class Scanner_Worker:public QObject
{
    Q_OBJECT
private:
    bool ScanRunning;
    int counts = 0;
    int number_of_rounds = 0;
public slots:
    void runScan(int steps, int accuracy);
    void stopScan(void);
    void currentCounts(int counts);
signals:
    void currentData(QPair<int, int>);
    void moveStep(void);
public:

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
    void interruptScan(void);
public slots:
    //External
    void currentCounts(int counts);
    void runScan(int start, int stop, int accuracy, int currentPos);
//    void cancelScan(void);
//    void runScan(void);
//    void stopScanner(void);
//    void init(int start_pos, int stop_pos, int _accuracy, int _MonoPosOrig, bool _direction);
//    void scan();
signals:
    //Internal
    void runScanWorker(int, int);
    void currentCountsToWorker(int);
    //External
    void currentDataToExt(QPair<int, int>);
    void moveStepperToTarget(int, int);
    void scanFinished(void);
    void scanInterrupted(void);
//    void moveStepUp(void);
//    void moveStepDown(void);
//    void currentValue(qreal, qreal);
//    void moveToPosition(int, int);
public:
    Scanner_Master();
    ~Scanner_Master();
    //void resetScanner(void);

};


#endif // SCANNER_H
