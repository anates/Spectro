#include "scanlist.h"
#include <QDate>

ScanList::ScanList()
{
    //qDebug() << "ScanList: " << thread() << QThread::currentThread();
    ScanList::currentScan = 0;
    ScanList::fileName = "";
    ScanList::scanFileNames.clear();
    ScanList::Scans.clear();
    currentScan = -1;
}

void ScanList::addScan(Scan newScan)
{
    for(unsigned int i = 0; i < this->Scans.size(); i++)
    {
        if(this->Scans[i].scanName == newScan.scanName)
            newScan.scanName += QDate::currentDate().toString();
    }
    ScanList::Scans.push_back(newScan);
    currentScan++;
}

void ScanList::dropScan(void)
{
    ScanList::Scans.remove(ScanList::currentScan);
    currentScan = currentScan - 1;
}

int ScanList::getScanNumbers(void)
{
    return ScanList::Scans.size();
}

int ScanList::getCurrentScanNumber(void)
{
    return ScanList::currentScan;
}

Scan & ScanList::getCurrentScan(void)
{
    if(!Scans.isEmpty())
        return Scans[currentScan];
}

int ScanList::getLength()
{
    return this->Scans.length();
}

Scan ScanList::getNextScan(void)
{
    if(!Scans.isEmpty())
    {
        if(ScanList::currentScan + 1 == Scans.size())
        {
            currentScan = 0;
            return Scans[0];
        }
        else
        {
            currentScan += 1;
            return Scans[currentScan];
        }
    }
}

Scan ScanList::getLastScan(void)
{
    if(!Scans.isEmpty())
    {
        if(ScanList::currentScan == 0)
        {
            currentScan = Scans.size() - 1;
            return Scans[currentScan];
        }
        else
        {
            currentScan -= 1;
            return Scans[currentScan];
        }
    }
}

Scan & ScanList::getScan(quint32 ScanNumber)
{
    if(!Scans.isEmpty())
        if(ScanNumber >= 0 && ScanNumber < Scans.size())
            return Scans[ScanNumber];
}

void ScanList::setCurrentScan(int ScanNumber)
{
    ScanList::currentScan = (ScanNumber >= 0 && ScanNumber < ScanList::getScanNumbers())?ScanNumber:ScanList::currentScan;
}

void ScanList::setFileName(QString fileName)
{
    ScanList::fileName = fileName;
}

QString ScanList::getFileName(void)
{
    return ScanList::fileName;
}

QVector<QString> ScanList::getFileNames(void)
{
    return ScanList::scanFileNames;
}

void ScanList::addFileName(QString fileName)
{
    ScanList::scanFileNames.push_back(fileName);
}

void ScanList::deleteFileName(QString fileName)
{
    for(int i = 0; i < ScanList::scanFileNames.size(); i++)
    {
        if(ScanList::scanFileNames[i] == fileName)
        {
            ScanList::scanFileNames.remove(i);
            return;
        }
    }
}
