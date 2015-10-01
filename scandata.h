#ifndef SCANDATA_H
#define SCANDATA_H
#include <QVector>
#include <QPair>
#include <tuple>


class ScanData
{
//private://For testing public
public:
    QVector<std::tuple<qreal, qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;
public:
    ScanData();
    QVector<std::tuple<qreal, qreal, qreal> > getData(void);
    QVector<std::tuple<qreal, qreal, qreal> > &setData(void);
    void clear(void);
};

#endif // SCANDATA_H
