#include "scanner.h"

Scanner_Master::Scanner_Master()
{
}

void Scanner_Master::init(int start_pos, int stop_pos, int _accuracy, int _MonoPosOrig, bool _direction)
{

    Scanner_Master::doScan = true;
    Scanner_Master::startpos = start_pos;
    Scanner_Master::stoppos = stop_pos;
    Scanner_Master::accuracy = _accuracy;
    Scanner_Master::MonoPos = _MonoPosOrig;
    Scanner_Master::MonoPosOrig = _MonoPosOrig;
    Scanner_Master::direction = _direction;
    //qDebug() << "Scanner has been initialized with Monopos: " << scanner::MonoPos << " and " << scanner::startpos;
    emit moveToPosition(Scanner_Master::MonoPos, Scanner_Master::startpos);
    //qDebug() << "Returning to main thread";
}

void Scanner_Master::runScan()
{
    doScan = true;
    Scanner_Master::scan();
}

void Scanner_Master::run()
{
    qDebug() << "Scanner: " << thread() << currentThread();
    while(stopScanDevice == false)
    {
        msleep(50);
        if(Scanner_Master::doScan)
            scan();
    }
}

void Scanner_Master::scan()
{
    //qreal MonoPos = scanner::MonoPos;
    //qDebug() << "From scanner::run(): " << thread() << currentThread();//Sei speed als Verweildauer pro Punkt definiert
    qreal currentCount = 0;
    qreal length = fabs(scanner::startpos - scanner::stoppos);
    for(int i = 0; i < length; i++)
    {
        if(doScan == false)
        {
            Scanner_Master::resetScanner();
            break;
        };
        //For debug disabled//Not anymore
        if(direction)
            emit Scanner_Master::moveStepUp();
        else
            emit Scanner_Master::moveStepDown();
        for(int j = 0; j < ((accuracy <= 1 )? 1 : accuracy); j++)
            currentCount += Read_DPC();
        usleep(50000);//For Debug
        emit Scanner_Master::currentStatus(((qreal)(i)/length)*100);
        emit Scanner_Master::currentValue(i + scanner::startpos, currentCount);
        currentCount = 0;
        //qDebug() << "Current count: " << ((qreal)(i)/length)*100;
    }
    //qDebug() << "Scan Finished";
    doScan = false;
    emit scanFinished();
}

void Scanner_Master::resetScanner(void)
{
    emit moveToPosition(Scanner_Master::MonoPos, Scanner_Master::MonoPosOrig);
    emit scanInterrupted();
}

void Scanner_Master::cancelScan(void)
{
    Scanner_Master::doScan = false;
}

void Scanner_Master::stopScanner(void)
{
    stopScanDevice = true;
}
