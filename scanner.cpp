#include "scanner.h"
//Scanner_Worker-functions

void Scanner_Worker::currentCounts(int counts)
{
    Scanner_Worker::counts += counts;
    Scanner_Worker::number_of_rounds++;//Muss noch verbessert werden, das hier ist eine Notloesung
}

void Scanner_Worker::runScan(int steps, int accuracy)
{
    ScanRunning = true;
    for(int i = 0; i < steps; i++)
    {
        if(ScanRunning == false)
            break;
        while(number_of_rounds < accuracy && ScanRunning == true)
            usleep(7000);
        emit currentData(qMakePair(i, counts));
        emit moveStep();
        emit currentPosition(((qreal)i)/((qreal)steps)*100);
        counts = 0;
        number_of_rounds = 0;
    }
    emit ScanFinished();
}

void Scanner_Worker::stopScan()
{
    ScanRunning = false;//Sollte auch verbessert werden, da race condition auftreten kann
}

//Scanner_Master-functions
Scanner_Master::Scanner_Master()
{
    Scanner_Worker *newWorker = new Scanner_Worker;
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

//void Scanner_Master::init(int start_pos, int stop_pos, int _accuracy, int _MonoPosOrig, bool _direction)
//{

//    Scanner_Master::doScan = true;
//    Scanner_Master::startpos = start_pos;
//    Scanner_Master::stoppos = stop_pos;
//    Scanner_Master::accuracy = _accuracy;
//    Scanner_Master::MonoPos = _MonoPosOrig;
//    Scanner_Master::MonoPosOrig = _MonoPosOrig;
//    Scanner_Master::direction = _direction;
//    //qDebug() << "Scanner has been initialized with Monopos: " << scanner::MonoPos << " and " << scanner::startpos;
//    emit moveToPosition(Scanner_Master::MonoPos, Scanner_Master::startpos);
//    //qDebug() << "Returning to main thread";
//}

//void Scanner_Master::runScan()
//{
//    doScan = true;
//    Scanner_Master::scan();
//}

//void Scanner_Master::run()
//{
//    qDebug() << "Scanner: " << thread() << currentThread();
//    while(stopScanDevice == false)
//    {
//        msleep(50);
//        if(Scanner_Master::doScan)
//            scan();
//    }
//}

//void Scanner_Master::scan()
//{
//    //qreal MonoPos = scanner::MonoPos;
//    //qDebug() << "From scanner::run(): " << thread() << currentThread();//Sei speed als Verweildauer pro Punkt definiert
//    qreal currentCount = 0;
//    qreal length = fabs(scanner::startpos - scanner::stoppos);
//    for(int i = 0; i < length; i++)
//    {
//        if(doScan == false)
//        {
//            Scanner_Master::resetScanner();
//            break;
//        };
//        //For debug disabled//Not anymore
//        if(direction)
//            emit Scanner_Master::moveStepUp();
//        else
//            emit Scanner_Master::moveStepDown();
//        for(int j = 0; j < ((accuracy <= 1 )? 1 : accuracy); j++)
//            currentCount += Read_DPC();
//        usleep(50000);//For Debug
//        emit Scanner_Master::currentStatus(((qreal)(i)/length)*100);
//        emit Scanner_Master::currentValue(i + scanner::startpos, currentCount);
//        currentCount = 0;
//        //qDebug() << "Current count: " << ((qreal)(i)/length)*100;
//    }
//    //qDebug() << "Scan Finished";
//    doScan = false;
//    emit scanFinished();
//}

//void Scanner_Master::resetScanner(void)
//{
//    emit moveToPosition(Scanner_Master::MonoPos, Scanner_Master::MonoPosOrig);
//    emit scanInterrupted();
//}

//void Scanner_Master::cancelScan(void)
//{
//    Scanner_Master::doScan = false;
//}

//void Scanner_Master::stopScanner(void)
//{
//    stopScanDevice = true;
//}
