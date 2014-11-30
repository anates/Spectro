#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H
#include <vector>
#include <memory>
#include <QVector>
#include <QThread>

#include "../BlackLib/v2_0/BlackLib.h"

class Stepper_Control_Worker:public QObject
{
    Q_OBJECT
private:
    std::vector<std::unique_ptr<BlackLib::BlackGPIO> > STP;
public slots:
    void moveStepper(int steps, bool dir);
signals:
    void StepperMoved(int, bool);
public:
    Stepper_Control_Worker();
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
    //External
    void moveStepMotor(int CurrentPos, int newPos);
signals:
    //Internal
    void moveStepper(int, bool);
    //External
    void CurrentPosition(int, bool);
public:
    Stepper_Control_Master(int MonoPos);
    ~Stepper_Control_Master();

};

#endif // STEPPER_CONTROL_H
