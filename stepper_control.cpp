#include "stepper_control.h"
//Stepper_Control_Worker-functions
Stepper_Control_Worker::Stepper_Control_Worker(QMutex *mutex, QWaitCondition *cond)
{
    waitMutex = mutex;
    WaitCond = cond;
#ifdef LOCAL
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_86, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_87, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_88, BlackLib::output));
    Stepper_Control_Worker::STP.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_89, BlackLib::output));
#endif
}

Stepper_Control_Worker::~Stepper_Control_Worker()
{

}

void Stepper_Control_Worker::moveStepper(int steps, bool dir)
{
    waitMutex->lock();
    //qDebug() << "Motor moved from down below!";
#ifdef LOCAL
    Stepper_Control_Worker::STP[1]->setValue((dir == true)?BlackLib::high:BlackLib::low);
    usleep(50000);
    Stepper_Control_Worker::STP[0]->setValue(BlackLib::low);
    usleep(50000);
    int stepsize = steps/100;
    int num_of_steps = 0;
    for(int i = 0; i < steps; i++)
    {
        Stepper_Control_Worker::STP[0]->setValue(BlackLib::high);
        usleep(50000);
        Stepper_Control_Worker::STP[0]->setValue(BlackLib::low);
        if(i%stepsize == 0)
        {
            emit this->currentStatus(num_of_steps);
            num_of_steps++;
        }
    }
    WaitCond->wakeAll();
    waitMutex->unlock();
    emit StepperMoved(steps, dir);
#endif
}

//Stepper_Control_Master-functions
Stepper_Control_Master::Stepper_Control_Master(QMutex *mutex, QWaitCondition *WaitCond)
{
    Stepper_Control_Worker *newWorker = new Stepper_Control_Worker(mutex, WaitCond);
    newWorker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &Stepper_Control_Master::moveStepper, newWorker, &Stepper_Control_Worker::moveStepper);
    connect(newWorker, &Stepper_Control_Worker::StepperMoved, this, &Stepper_Control_Master::StepMotorMoved);
    connect(newWorker, &Stepper_Control_Worker::currentStatus, this, &Stepper_Control_Master::Status);
    workerThread.start();
}

Stepper_Control_Master::~Stepper_Control_Master()
{
    //qDebug() << "Clearing up Stepper_control";
    workerThread.quit();
    workerThread.wait();
    //qDebug() << "Stepper_Control cleared!";
}

void Stepper_Control_Master::moveStepMotor(int steps, bool dir)
{
    //qDebug() << "Motor should move from Stepper_control_master in thread " << thread();
    emit moveStepper(steps, dir);
}

void Stepper_Control_Master::StepMotorMoved(int steps, bool dir)
{
    //qDebug() << "Stepper moved!";
    emit CurrentPosition(steps, dir);
}

void Stepper_Control_Master::Status(int status)
{
    emit this->CurrentStatus(status);
}
