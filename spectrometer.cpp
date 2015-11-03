#include "spectrometer.h"
#include <sstream>

//Spectrometer functions
Spectrometer::Spectrometer(QMutex *mutex, QWaitCondition *WaitCond)
{
    //qDebug() << "Spectrometer: " << thread() << QThread::currentThread();
    MovingMutex = mutex;
    MovingCond = WaitCond;

    counterData *Data = new counterData;
    Data->mutex.lock();
    Data->mutex.unlock();

    stepperControl = new Stepper_Control_Master(MovingMutex, MovingCond);
    scannerControl = new Scanner_Master(MovingMutex, MovingCond, Data);
    dpcControl = new DPC_Master(Data);

    connect(this, &Spectrometer::moveStepperToTarget, stepperControl, &Stepper_Control_Master::moveStepMotor);
    connect(stepperControl, &Stepper_Control_Master::CurrentPosition, this, &Spectrometer::stepperMoved);

    connect(this, &Spectrometer::switchPolarizer, &polarizerControl, &polarizer_control_master::setPolarizers);
    connect(&polarizerControl, &polarizer_control_master::switchingSuccess, this, &Spectrometer::switchingSuccess);

    connect(dpcControl, &DPC_Master::currentCount, this, &Spectrometer::currentCounts);
    connect(dpcControl, &DPC_Master::currentCount, scannerControl, &Scanner_Master::currentCounts);

    connect(this, &Spectrometer::scanNow, scannerControl, &Scanner_Master::runScan);
    connect(this, &Spectrometer::interruptScan, scannerControl, &Scanner_Master::interruptScan);
    connect(scannerControl, &Scanner_Master::currentDataToExt, this, &Spectrometer::currentData);
    //connect(scannerControl, &Scanner_Master::moveStepperToTarget, this, &Spectrometer::updatePosition);
    connect(scannerControl, &Scanner_Master::moveStepperToTarget, this, &Spectrometer::moveToTarget);
    //connect(&scannerControl, &Scanner_Master::moveStepperToTarget, stepperControl, &Stepper_Control_Master::moveStepMotor);
    connect(scannerControl, &Scanner_Master::scanFinished, this, &Spectrometer::scanFinished);
    connect(scannerControl, &Scanner_Master::scanCurrentPosition, this, &Spectrometer::currentScanPosition);
}

Spectrometer::~Spectrometer()
{
    delete stepperControl;
}

void Spectrometer::currentScanPosition(qreal position)
{
    emit ScanPos(position);
}

void Spectrometer::scanFinished()
{
    emit scanFinish();
}

void Spectrometer::runScan(int start, int stop, int accuracy)
{
    qDebug() << "Scanning now!";
    emit scanNow(start, stop, accuracy);
}

void Spectrometer::stepperMoved(int steps, bool dir)
{
//    QString debug = " (Spectrometer::stepperMoved): Stepper moved for " + QString::number(steps) + " in direction " + QString::number(dir);
//    qDebug() << debug;
    emit currentPosition(steps, dir);
}

void Spectrometer::switchingSuccess(Polarizer pol)
{
    emit switchingSucceed(pol);
}

void Spectrometer::currentCounts(int counts)
{
    emit DPCCounts(counts);
}

void Spectrometer::currentData(QPair<int, int> data)
{
    emit Data(data);
}

void Spectrometer::updatePosition(int steps, bool dir)
{
//    QString debug = " (Spectrometer::updatePosition): Stepper moved for " + QString::number(steps) + " in direction " + QString::number(dir);
//    qDebug() << debug;
    emit currentPosition(steps, dir);
}

void Spectrometer::switchPol(Polarizer pol)
{
    emit switchPolarizer(pol);
}

void Spectrometer::moveToTarget(int steps, bool dir)
{
//    bool dir = (target - currentMonoPos) >= 0;
//    int steps = fabs(currentMonoPos - target);
    //qDebug() << "Movement from Spectrometer for " << steps << " steps in " << dir << " direction from thread " << thread() << "!";
    emit moveStepperToTarget(steps, dir);
    MovingMutex->lock();
    //qDebug() << "Locking WaitMutex!";
    //qDebug() << "Waiting for signal!";
    MovingCond->wait(MovingMutex);
    MovingMutex->unlock();
    //qDebug() << "Unlocked";
}



//Spectrometer_Control-functions

Spectrometer_Control::Spectrometer_Control(QMutex *mutex, QWaitCondition *WaitForEngine, QString ipAddr, quint32 port)
{
    Spectrometer_Control::MovingMutex = mutex;
    Spectrometer_Control::MovingCond = WaitForEngine;
    this->multiAqu = 1;
    this->numAqu = 1;
    this->currCounts = 0;
    moving = false;
//    Spectrometer_Control::CountCond = WaitCond;
//    Spectrometer_Control::CountMutex = cmutex;
    for(int i = 0; i < 3; i++)
        polarizerSetting.push_back(false);
    Spectrometer_Control::MonoPos = 0;
    this->SR_controller = NULL;
    if(ipAddr.isEmpty())
    {
        newSpectrometer = new Spectrometer(MovingMutex, MovingCond);
        newSpectrometer->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, newSpectrometer, &QObject::deleteLater);

        connect(newSpectrometer, &Spectrometer::Data, this, &Spectrometer_Control::scanData);
        //Temporarily disabled
        //connect(newSpectrometer, &Spectrometer::DPCCounts, this, &Spectrometer_Control::currentCounts);
        //Temporarily disabled
        connect(newSpectrometer, &Spectrometer::currentPosition, this, &Spectrometer_Control::updateCurrentPosition);
        connect(newSpectrometer, &Spectrometer::switchingSucceed, this, &Spectrometer_Control::updatePolarizers);
        //connect(newSpectrometer, &Spectrometer::scanFinish, this, &Spectrometer_Control::scanFinish);
        connect(newSpectrometer, &Spectrometer::ScanPos, this, &Spectrometer_Control::scanPosition);

        connect(this, &Spectrometer_Control::switchPolarizer, newSpectrometer, &Spectrometer::switchPol);
        connect(this, &Spectrometer_Control::moveStepperToTarget, newSpectrometer, &Spectrometer::moveToTarget);
        connect(this, &Spectrometer_Control::runScan, newSpectrometer, &Spectrometer::runScan);
        //connect(this, &Spectrometer_Control::initMonoPos, newSpectrometer, &Spectrometer::changePosition);

        workerThread.start();
    }
    else
    {
        Spectrometer_Control::ipAddr = ipAddr;
        Spectrometer_Control::port = port;
        remoteControl = new TXcontroller(Spectrometer_Control::ipAddr, Spectrometer_Control::port, Spectrometer_Control::MonoPos);
        connect(remoteControl, &TXcontroller::Data, this, &Spectrometer_Control::scanData);
        connect(remoteControl, &TXcontroller::stepperMoving, this, &Spectrometer_Control::stepperIsMoving);
        connect(remoteControl, &TXcontroller::DPCCounts, this, &Spectrometer_Control::currentCounts);
        connect(remoteControl, &TXcontroller::currentPosition, this, &Spectrometer_Control::updateCurrentPosition);
        connect(remoteControl, &TXcontroller::switchingSucceed, this, &Spectrometer_Control::updatePolarizers);
        //connect(remoteControl, &TXcontroller::scanFinish, this, &Spectrometer_Control::scanFinish);
        connect(remoteControl, &TXcontroller::ScanPos, this, &Spectrometer_Control::scanPosition);
        connect(remoteControl, &TXcontroller::MainClientStat, this, &Spectrometer_Control::TXStatus);
        connect(remoteControl, &TXcontroller::movementFinish, this, &Spectrometer_Control::stepperStopped);
        connect(remoteControl, &TXcontroller::currentStepperStatus, this, &Spectrometer_Control::currentStepperStatus);

        connect(this, &Spectrometer_Control::switchPolarizer, remoteControl, &TXcontroller::SwitchPolarizer);
        connect(this, &Spectrometer_Control::moveStepperToTarget, remoteControl, &TXcontroller::moveToTarget);
        connect(this, &Spectrometer_Control::runScan, remoteControl, &TXcontroller::runScan);
    }
}

Spectrometer_Control::~Spectrometer_Control()
{
    qDebug() << "Cleaning up Spectrometer!";
    if(ipAddr.isEmpty())
    {
        qDebug() << "Quitting worker in SpecControl";
        workerThread.quit();
        qDebug() << "Waiting for worker in SpecControl";
        workerThread.wait(1000);
        qDebug() << "Finished in SpecControl!";
    }
    else
    {
        emit this->shutSpectrometerDown();
        delete remoteControl;
    };
    qDebug() << "Spectrometer cleaned!";
}

void Spectrometer_Control::TXStatus(bool status)
{
    emit this->TX_status(status);
}

void Spectrometer_Control::currentStepperStatus(int status)
{
    emit this->currentStatus(status);
    if(status >= 1)
        this->moving = true;
    else
        this->moving = false;
}

bool Spectrometer_Control::isMoving()
{
    return this->moving;
}

void Spectrometer_Control::scanFinish()
{
    qDebug() << "From spectrometer: Scan finished!";
    this->moving = false;
    emit scanFinished();
}

void Spectrometer_Control::scanPosition(qreal position)
{
    emit currentScanPosition(position);
}

void Spectrometer_Control::scanData(QPair<int, int> data)
{
    emit currentData(data);
}

void Spectrometer_Control::setAquisitions(int numAqu)
{
    this->numAqu = numAqu;
}

void Spectrometer_Control::currentCounts(double counts)
{
//    if(this->numAqu >= this->multiAqu)
//    {
//        this->currCounts /= this->multiAqu;
//        this->numAqu = 1;
//        emit currentCounterData(this->currCounts);
//        this->currCounts = 0;
//    }
//    else
//    {
//        this->numAqu++;
//        this->currCounts += counts;
//    }
    emit this->currentCounterData(counts);
    qDebug() << "Current counts in spectrometer: " << counts;
}

void Spectrometer_Control::updateCurrentPosition(int steps, bool dir)
{
    //qDebug() << "Updating current position with " << QString::number(steps) << " in direction " << QString::number(dir);
    if(dir == true)
        MonoPos += steps;
    else
        MonoPos -= steps;
    emit positionChanged();
    //qDebug() << "New Monopos: " << QString::number(MonoPos);
}

void Spectrometer_Control::stepperIsMoving()
{
    emit stepperMoving();
    moving = true;
}

void Spectrometer_Control::updatePolarizers(Polarizer pol)
{
    polarizerSetting[pol] = !polarizerSetting[pol];
    emit positionChanged();
}

int Spectrometer_Control::getMonoPos(void)
{
    return Spectrometer_Control::MonoPos;
}

void Spectrometer_Control::setMonoPos(int MonoPos)
{
    Spectrometer_Control::MonoPos = MonoPos;
}

void Spectrometer_Control::setPolarizers(Polarizer pol, bool state)
{
    if(polarizerSetting[pol] != state)
    {
        polarizerSetting[pol] = state;
        emit switchPolarizer(pol);
    };
}

void Spectrometer_Control::setPolarizers(QVector<bool> polarizers)
{
    if(polarizers.size() != 3)
    {
        return;
    }
    else
    {
        polarizerSetting[0] = polarizers[0];
        polarizerSetting[1] = polarizers[1];
        polarizerSetting[2] = polarizers[2];
    }
}

bool Spectrometer_Control::getPolarizerState(Polarizer pol)
{
    return polarizerSetting[pol];
}

QVector<bool> Spectrometer_Control::getPolarizers()
{
    return polarizerSetting;
}

void Spectrometer_Control::moveStepper(int steps, bool dir)
{
    emit stepperMoving();
    //qDebug() << "From Spectrometer_Control: Stepper should move in direction " + QString::number(dir) + " from position " + QString::number(MonoPos);
    //int newTarget = MonoPos + ((dir == true)?(steps):(-1 * steps));
    //qDebug() << "New target: " + QString::number(newTarget);
    emit moveStepperToTarget(steps, dir);
//    qDebug() << "Finally unlocked!";
}

void Spectrometer_Control::scan(int start, int stop, int accuracy)
{
    emit stepperMoving();
    //qDebug() << "Current start value is: " << QString::number(start) << " and current MonoPos value is: " << QString::number(MonoPos);
    if(start != MonoPos)
    {
        //qDebug() << "Start is not in MonoPos, moving!";
        int steps = fabs(MonoPos - start);
        bool dir = (start - MonoPos) >= 0;
//        emit moveStepperToTarget(steps, dir);
        moveStepper(steps, dir);

    }
    emit runScan(0, fabs(stop - start), accuracy);
}

void Spectrometer_Control::stepperStopped()
{
    qDebug() << "From Spectrometer: Movement stopped!";
    emit this->stepperIsStopped();
}

void Spectrometer_Control::useRemote(QString ipAddr, quint32 port)
{
    Spectrometer_Control::ipAddr = ipAddr;
    Spectrometer_Control::port = port;
    remoteControl = new TXcontroller(Spectrometer_Control::ipAddr, Spectrometer_Control::port, Spectrometer_Control::MonoPos);
    //disconnect local data
    newSpectrometer->disconnect();
//    disconnect(newSpectrometer, SLOT(switchPol(Polarizer)));
//    disconnect(newSpectrometer, SLOT(moveToTarget(int,bool)));
//    disconnect(newSpectrometer, SLOT(runScan(int,int,int)));
//    qDebug() << "Result of disconnecting currentCounts: " << disconnect(this);
//    disconnect(this, SLOT(scanData(QPair<int,int>)));
//    disconnect(this, SLOT(updateCurrentPosition(int,bool)));
//    disconnect(this, SLOT(scanFinish()));
//    disconnect(this, SLOT(scanPosition(qreal)));
//    disconnect(this, SLOT(updatePolarizers(Polarizer)));

    //connect remote
    connect(remoteControl, &TXcontroller::Data, this, &Spectrometer_Control::scanData);
    connect(remoteControl, &TXcontroller::DPCCounts, this, &Spectrometer_Control::currentCounts);
    connect(remoteControl, &TXcontroller::currentPosition, this, &Spectrometer_Control::updateCurrentPosition);
    connect(remoteControl, &TXcontroller::switchingSucceed, this, &Spectrometer_Control::updatePolarizers);
    //connect(remoteControl, &TXcontroller::scanFinish, this, &Spectrometer_Control::scanFinish);
    connect(remoteControl, &TXcontroller::ScanPos, this, &Spectrometer_Control::scanPosition);
    connect(remoteControl, &TXcontroller::MainClientStat, this, &Spectrometer_Control::TXStatus);
    connect(remoteControl, &TXcontroller::stepperMoving, this, &Spectrometer_Control::stepperIsMoving);
    connect(remoteControl, &TXcontroller::currentStepperStatus, this, &Spectrometer_Control::currentStepperStatus);
    connect(remoteControl, &TXcontroller::movementFinish, this, &Spectrometer_Control::stepperStopped);

    connect(this, &Spectrometer_Control::switchPolarizer, remoteControl, &TXcontroller::SwitchPolarizer);
    connect(this, &Spectrometer_Control::moveStepperToTarget, remoteControl, &TXcontroller::moveToTarget);
    connect(this, &Spectrometer_Control::runScan, remoteControl, &TXcontroller::runScan);
    connect(this, &Spectrometer_Control::shutSpectrometerDown, remoteControl, &TXcontroller::shutDown);
}



void Spectrometer_Control::response(QVector<QString> response)
{
    qDebug() << "Spectrometer-response is: " << response;
    if(QString::compare(response.first(), "1", Qt::CaseInsensitive) == 0 || QString::compare(response.first(), "2", Qt::CaseInsensitive) == 0)//To be reworked, after 'H' does not return anything
    {
        this->serial_connected = true;
        emit this->SerialIsConnected(this->serial_connected);
    }
    else
    {

           emit this->SerialData(response);
//        QByteArray buffer = response.toLatin1();
//        const char * tmp_buffer = buffer.data();
//        int buffer_int;
//        std::stringstream str;
//        str << tmp_buffer;
//        str >> buffer_int;
//        //qDebug() << "Current counts: " << buffer_int;
//        this->currentCounts(buffer_int);
    }
}

void Spectrometer_Control::initSerial(const QString &portName, int waitTimeout, int BaudRate, int numStopBits, bool parity, bool useParity, bool useEchoMode)
{
    this->SR_controller = new serial_controller(portName, waitTimeout, BaudRate, numStopBits, parity, useParity, useEchoMode);
    qDebug() << disconnect(this->newSpectrometer, SIGNAL(DPCCounts(int)));
    connect(this->SR_controller, &serial_controller::response, this, &Spectrometer_Control::response);
    connect(this->SR_controller, &serial_controller::CountValue, this, &Spectrometer_Control::currentCounts);
    this->SR_controller->transaction("H", 0);
}

void Spectrometer_Control::lockin_value(QString value, int firstValue, int secondValue)
{
    this->SR_controller->transaction((firstValue == -1?value:((secondValue == -1)?value + " " + QString::number(firstValue):value + " " + QString::number(firstValue) + " " + QString::number(secondValue))), 0);
}

void Spectrometer_Control::get_analog_value()
{
    this->SR_controller->transaction("Q1", this->serial_waiting_time);
}
