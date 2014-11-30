#ifndef SCANNER_H
#define SCANNER_H
#include "stepper_control.h"


class Scanner_Worker:public QObject
{
    Q_OBJECT
private:
public slots:
signals:
public:

};


class Scanner_Master:public QObject
{
    Q_OBJECT
private:
    bool doScan = false;
    int startpos, stoppos, accuracy;
    int MonoPos;
    int MonoPosOrig;
    bool direction;
    volatile bool stopScanDevice = false;
public slots:
    void cancelScan(void);
    void runScan(void);
    void stopScanner(void);
    void init(int start_pos, int stop_pos, int _accuracy, int _MonoPosOrig, bool _direction);
    void scan();
signals:
    void currentStatus(qreal);
    void scanFinished(void);
    void scanInterrupted(void);
    void moveStepUp(void);
    void moveStepDown(void);
    void currentValue(qreal, qreal);
    void moveToPosition(int, int);
public:
    Scanner_Master();
    ~Scanner_Master();
    void resetScanner(void);

};


#endif // SCANNER_H
