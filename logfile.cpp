#include "logfile.h"

LogFile::LogFile()
{
    LogFile::clear();
}

void LogFile::clear(void)
{
    LogFile::countNumber = 0;
    LogFile::laserIntensity = 0;
    LogFile::logfileSet = false;
    LogFile::name = "";
    LogFile::sensitivity = 0;
    LogFile::slitWidth = 0;
}

QString & LogFile::getName()
{
    return name;
}

qreal & LogFile::getCount()
{
    return countNumber;
}

qreal & LogFile::getIntensity()
{
    return laserIntensity;
}

qreal & LogFile::getSensitivity()
{
    return sensitivity;
}

qreal & LogFile::getSlit()
{
    return slitWidth;
}
