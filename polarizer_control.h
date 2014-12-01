#ifndef POLARIZER_CONTROL_H
#define POLARIZER_CONTROL_H
#include <QObject>
#include <QThread>
#include <QVector>
#include <memory>

#include "../BlackLib/v2_0/BlackLib.h"

enum Polarizer{xPol = 0, yPol = 1, zPol = 2};
Q_DECLARE_METATYPE(Polarizer)

class polarizer_control_worker:public QObject
{
    Q_OBJECT
private:
    std::vector<std::unique_ptr<BlackLib::BlackGPIO> > POL;
public slots:
    void switchPolarizer(Polarizer pol);
signals:
    void PolarizerSwitched(Polarizer pol);
public:
    polarizer_control_worker();
};

class polarizer_control_master:public QObject
{
    Q_OBJECT
    QThread workerThread;
private:
public slots:
    void setPolarizers(Polarizer pol);
    //Internal, for getting data about success
    void PolarizerSwitchSuccess(Polarizer pol);
signals:
    //External
    void switchingSuccess(Polarizer);
    //Internal, for controlling worker
    void switchPolarizer(Polarizer);
public:
    polarizer_control_master();
    ~polarizer_control_master()
    {
        workerThread.quit();
        workerThread.wait();
    }

};

#endif // POLARIZER_CONTROL_H
