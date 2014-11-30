#include "stepper_control.h"
//Stepper_Control_Worker-functions
Stepper_Control_Worker::Stepper_Control_Worker()
{
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_86, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_87, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_88, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_89, BlackLib::output));
}

Stepper_Control_Worker::moveStepper(int steps, bool dir)
{
    Stepper_Control_Worker::STP[1]->setValue((dir == true)?BlackLib::high:BlackLib::low);
    msleep(50);
    Stepper_Control_Worker::STP[0]->setValue(BlackLib::low);
    msleep(50);
    for(int i = 0; i < steps; i++)
    {
        Stepper_Control_Worker::STP[0]->setValue(BlackLib::high);
        msleep(50);
        Stepper_Control_Worker::STP[0]->setValue(BlackLib::low);
    }
    emit StepperMoved(steps, dir);
}

//Stepper_Control_Master-functions
Stepper_Control_Master::Stepper_Control_Master(int MonoPos)
{
    Spec_Control::MonoPos = MonoPos;
    Stepper_Control_Worker *newWorker = new Stepper_Control_Worker;
    newWorker->moveToThread(&workerThread);
    connect(workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &Stepper_Control_Master::moveStepper, newWorker, &Stepper_Control_Worker::moveStepper);
    connect(newWorker, &Stepper_Control_Worker::StepperMoved, this, &Stepper_Control_Master::StepMotorMoved);
}

Stepper_Control_Master::~Stepper_Control_Master()
{
    qDebug() << "Clearing up Spec_control";
}

void Stepper_Control_Master::moveStepMotor(int CurrentPos, int newPos)
{
    bool dir = (newPos - CurrentPos) >= 0;
    int steps = fabs(newPos - CurrentPos);
    emit moveStepper(steps, dir);
}

void Stepper_Control_Master::StepMotorMoved(int steps, bool dir)
{
    emit CurrentPosition(steps, dir);
}


