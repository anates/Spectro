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

QVector<QPair<qreal, qreal> > ScanData::getData(void)
{
    return Data;
}

QVector<QPair<qreal, qreal> > &ScanData::setData(void)
{
    return &Data;
}
