#include "scandata.h"

ScanData::ScanData()
{
    ScanData::clear();
}

void ScanData::clear(void)
{
    ScanData::Data.clear();
    ScanData::FWHM.clear();
    ScanData::Maxima.clear();
}
