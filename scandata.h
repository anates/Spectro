#ifndef SCANDATA_H
#define SCANDATA_H
#include <QVector>
#include <QPair>



class ScanData
{
//private://For testing public
public:
    QVector<QPair<qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;
public:
    ScanData();
    QVector<QPair<qreal, qreal> > getData(void);
    QVector<QPair<qreal, qreal> > &setData(void);
    void clear(void);
};

#endif // SCANDATA_H
