#include "polarizer_control.h"
//polarizer_control_worker-functions
polarizer_control_worker::polarizer_control_worker()
{
    polarizer_control_worker::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_120, BlackLib::output));
    polarizer_control_worker::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_121, BlackLib::output));
    polarizer_control_worker::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_122, BlackLib::output));
    polarizer_control_worker::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_123, BlackLib::output));
    polarizer_control_worker::POL.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_117, BlackLib::output));
    //Spec_Control::POL[5] = new BlackLib::BlackGPIO(BlackLib::GPIO_115, BlackLib::output);
}

void polarizer_control_worker::switchPolarizer(Polarizer pol)
{
    //Unable to do something here because the pin settings are not fixed yet
    emit PolarizerSwitched(pol);
}

//polarizer_control_master-functions
polarizer_control_master::polarizer_control_master()
{
    polarizer_control_worker *newWorker = new polarizer_control_worker;
    newWorker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &polarizer_control_master::switchPolarizer, newWorker, &polarizer_control_worker::switchPolarizer);
    connect(newWorker, &polarizer_control_worker::PolarizerSwitched, this, &polarizer_control_master::PolarizerSwitchSuccess);
    workerThread.start();
}

void polarizer_control_master::setPolarizers(Polarizer pol)
{
    emit switchPolarizer(pol);
}

void polarizer_control_master::PolarizerSwitchSuccess(Polarizer pol)
{
    emit switchingSuccess(pol);
}
