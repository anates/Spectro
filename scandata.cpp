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

QVector<std::tuple<qreal, qreal, qreal> > ScanData::getData(void)
{
    return Data;
}

QVector<std::tuple<qreal, qreal, qreal> > &ScanData::setData(void)
{
    return Data;
}

