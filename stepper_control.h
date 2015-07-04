#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H
#include <vector>
#include <memory>
#include <QVector>
#include <QMutex>
#include <QWaitCondition>
#include <unistd.h>
#include <QDebug>
#include <QThread>

#include "../BlackLib/v2_0/BlackLib.h"

class Stepper_Control_Worker:public QObject
{
    Q_OBJECT
private:
    QMutex *waitMutex;
    QWaitCondition *WaitCond;
    std::vector<std::unique_ptr<BlackLib::BlackGPIO> > STP;
public slots:
    void moveStepper(int steps, bool dir);
signals:
    void StepperMoved(int, bool);
    void currentStatus(int);
public:
    Stepper_Control_Worker(QMutex *mutex, QWaitCondition *cond);
    ~Stepper_Control_Worker();
};


class Stepper_Control_Master: public QObject
{
    Q_OBJECT
private:
    QThread workerThread;
public slots:
    //Internal
    void StepMotorMoved(int steps, bool dir);
    void Status(int status);
    //External
    void moveStepMotor(int steps, bool dir);
signals:
    //Internal
    void moveStepper(int, bool);
    //External
    void CurrentPosition(int, bool);
    void CurrentStatus(int);
public:
    Stepper_Control_Master(QMutex *mutex, QWaitCondition *WaitCond);
    ~Stepper_Control_Master();

};

#endif // STEPPER_CONTROL_H
