#include "scan.h"

Scan::Scan()
{
    Scan::isLoaded = false;
    Scan::isCalibrated = false;
    Scan::log.clear();
    Scan::hasWN = false;
    Scan::Central_WL = 0;
    Scan::Params.clear();
    Scan::readonly = false;
    Scan::scanName = "";
    Scan::values.clear();
}


void Scan::clear(void)
{
    Scan::av = NoAverage;
    Scan::log.clear();
    Scan::hasWN = false;
    Scan::Central_WL = 0;
    Scan::Params.clear();
    Scan::readonly = false;
    Scan::scanName = "";
    Scan::isLoaded = false;
    Scan::values.clear();
}

ScanData Scan::getValues()
{
    return values;
}

ScanData& Scan::setValues(void)
{
    return values;
}

LogFile& Scan::getLog()
{
    return Scan::log;
}
