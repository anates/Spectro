#ifndef SPECTROMETER_H
#define SPECTROMETER_H
#include <QVector>
#include <QThread>
#include "dpc.h"
#include "scanner.h"
#include "stepper_control.h"
#include "polarizer_control.h"

class Spectrometer: public QObject
{
    Q_OBJECT
private:
    int MonoPos = 0;

    DPC_Master dpcControl;
    polarizer_control_master polarizerControl;
    Scanner_Master scannerControl;
    Stepper_Control_Master stepperControl;
private slots:
    //Inside wiring
    //Polarizer
    void switchingSuccess(Polarizer pol);
    //Stepper
    void stepperMoved(int steps, bool dir);
    //DPC
    void currentCounts(int counts);
    //Scanner
    void currentData(QPair<int, int> data);
    void updatePosition(int oldpos, int newpos);
public slots:
    //From outside
    void setMonoPos(int MonoPos);
    void setPolarizers(QVector<bool> polarizers);
    void switchPol(Polarizer pol);
    void moveToTarget(int target);
    void runScan(int start, int stop, int accuracy);
signals:
    //Internal
    //To polarizer
    void switchPolarizer(Polarizer);
    //to Stepper
    void moveStepperToTarget(int, int);
    //to scanner
    void scanNow(int, int, int);
    void interruptScan(void);
    //to extern
public:
    Spectrometer();
    ~Spectrometer();

};

class Spectrometer_Control:public QObject
{
    Q_OBJECT
    QThread workerThread;
private:
public slots:
signals:
public:
    Spectrometer_Control()
    {
        Spectrometer *newSpectrometer = new Spectrometer;
        newSpectrometer->moveToThread(&workerThread);
        //connections fehlen noch
        workerThread.start();
    }
    ~Spectrometer_Control()
    {
        workerThread.quit();
        workerThread.wait();
    }
};

#endif // SPECTROMETER_H
