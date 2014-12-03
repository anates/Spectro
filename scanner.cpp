#include "scanner.h"
//Scanner_Worker-functions

Scanner_Worker::Scanner_Worker(QMutex *_MovingMutex, QWaitCondition *_MovingCond, counterData *data)
{
    Scanner_Worker::MovingMutex = _MovingMutex;
    Scanner_Worker::MovingCond = _MovingCond;
    Data = data;
}

void Scanner_Worker::currentCounts(int counts)
{
    Data->mutex.lock();
    Scanner_Worker::counts = Data->counts;
    Scanner_Worker::number_of_rounds = Data->number;
    Data->mutex.unlock();
}

void Scanner_Worker::runScan(int steps, int accuracy)
{
    ScanRunning = true;
    for(int i = 0; i <= steps; i++)
    {
        if(ScanRunning == false)
            break;
        Data->mutex.lock();
        if(Data->number >= accuracy)
        {
            qDebug() << "Current emitted data: Step: " << i << " and counts: " << Data->counts << " and current pos: " << ((qreal)i)/((qreal)steps)*100;
            emit currentData(qMakePair(i, Data->counts));
            emit moveStep();
            emit currentPosition(((qreal)i)/((qreal)steps)*100);
            Data->counts = 0;
            Data->number = 0;
            Data->mutex.unlock();
        }
        else
        {
            Data->WaitCond.wait(&(Data->mutex));
            Data->mutex.unlock();
            i--;
        }

    }
    emit ScanFinished();
}

void Scanner_Worker::stopScan()
{
    ScanRunning = false;//Sollte auch verbessert werden, da race condition auftreten kann
}

//Scanner_Master-functions
Scanner_Master::Scanner_Master(QMutex *MovingMutex, QWaitCondition *MovingCond, counterData *data)
{
    Scanner_Worker *newWorker = new Scanner_Worker(MovingMutex, MovingCond, data);
    newWorker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &Scanner_Master::currentCountsToWorker, newWorker, &Scanner_Worker::currentCounts);
    connect(this, &Scanner_Master::runScanWorker, newWorker, &Scanner_Worker::runScan);
    connect(this, &Scanner_Master::scanInterrupted, newWorker, &Scanner_Worker::stopScan);

    connect(newWorker, &Scanner_Worker::currentData, this, &Scanner_Master::currentData);
    connect(newWorker, &Scanner_Worker::moveStep, this, &Scanner_Master::moveStep);
    connect(newWorker, &Scanner_Worker::currentPosition, this, &Scanner_Master::currentPosition);
    connect(newWorker, &Scanner_Worker::ScanFinished, this, &Scanner_Master::scanIsFinished);
    workerThread.start();
}

Scanner_Master::~Scanner_Master()
{
    qDebug() << "Cleaning up Scanner";
    workerThread.quit();
    workerThread.wait();
    qDebug() << "Scanner cleaned!";
}

void Scanner_Master::currentData(QPair<int, int> data)
{
    emit currentDataToExt(data);
}

void Scanner_Master::moveStep()
{
    emit moveStepperToTarget(MonoPos, MonoPos + (direction == true)?1:(-1));
    MonoPos = MonoPos + (direction == true)?1:(-1);
    if(MonoPos == stoppos)
    {
        emit scanFinished();
        emit scanInterrupted();
    }
}

void Scanner_Master::currentCounts(int counts)
{
    emit currentCountsToWorker(counts);
}

void Scanner_Master::runScan(int start, int stop, int accuracy)
{
    Scanner_Master::startpos = start;
    Scanner_Master::stoppos = stop;
    Scanner_Master::accuracy = accuracy;
    Scanner_Master::MonoPos = 0;
    Scanner_Master::MonoPosOrig = 0;
    Scanner_Master::direction = ((stop - start) >= 0);
    qDebug() << "Scanner_Master starting scan now!";
    emit runScanWorker(fabs(stop-start), accuracy);
}

void Scanner_Master::interruptScan()
{
    emit scanInterrupted();
    emit moveStepperToTarget(MonoPos, MonoPosOrig);
}

void Scanner_Master::currentPosition(qreal position)
{
    emit scanCurrentPosition(position);
}

void Scanner_Master::scanIsFinished()
{
    emit scanFinished();
}
