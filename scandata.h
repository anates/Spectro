#ifndef SCANDATA_H
#define SCANDATA_H
#include <QVector>
#include <QPair>



class ScanData
{
private:
    QVector<QPair<qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;
public:
    ScanData();
    void clear(void);
};

#endif // SCANDATA_H
