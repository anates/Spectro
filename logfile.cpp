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
