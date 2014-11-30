#include "spectrometer.h"

//Spectrometer functions
Spectrometer::Spectrometer()
{
    //qDebug() << "Spectrometer: " << thread() << QThread::currentThread();
    for(int i = 0; i < 3; i++)
        polarizerSetting.push_back(false);
    Spectrometer::MonoPos = 0;

    connect(this, &Spectrometer::moveStepperToTarget, stepperControl, &Stepper_Control_Master::moveStepMotor);
    connect(stepperControl, &Stepper_Control_Master::StepMotorMoved, this, &Spectrometer::stepperMoved);

    connect(this, &Spectrometer::switchPolarizer, polarizerControl, &polarizer_control_master::setPolarizers);
    connect(polarizerControl, &polarizer_control_master::switchingSuccess, this, &Spectrometer::switchingSuccess);

    connect(dpcControl, &DPC_Master::currentCount, this, &Spectrometer::currentCounts);
    connect(dpcControl, &DPC_Master::currentCount, scannerControl, &Scanner_Master::currentCounts);

    connect(this, &Spectrometer::scanNow, scannerControl, &Scanner_Master::runScan);
    connect(this, &Spectrometer::interruptScan, scannerControl, &Scanner_Master::interruptScan);
    connect(scannerControl, &Scanner_Master::currentDataToExt, this, &Spectrometer::currentData);
    connect(scannerControl, &Scanner_Master::moveStepperToTarget, this, &Spectrometer::updatePosition);
    connect(scannerControl, &Scanner_Master::moveStepperToTarget, stepperControl, &Stepper_Control_Master::moveStepMotor);
}

void Spectrometer::setMonoPos(int MonoPos)
{
    Spectrometer::MonoPos = MonoPos;
}

void Spectrometer::runScan(int start, int stop, int accuracy)
{
    emit scanNow(start, stop, accuracy);
}

int & Spectrometer::getMonoPos(void)
{
    return Spectrometer::MonoPos;
}

void Spectrometer::setMonoSpeed(qreal MonoSpeed)
{
    Spectrometer::MonoSpeed = MonoSpeed;
}

qreal & Spectrometer::getMonoSpeed(void)
{
    return Spectrometer::MonoSpeed;
}

void Spectrometer::setMonoPosSlot(qreal MonoPos)
{
    Spectrometer::MonoPos = MonoPos;
}

void Spectrometer::setMonoSpeedSlot(qreal MonoSpeed)
{
    Spectrometer::MonoSpeed = MonoSpeed;
}


//Spectrometer-Controller functions
