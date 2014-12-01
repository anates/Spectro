#ifndef SCANPARAMS_H
#define SCANPARAMS_H

#include <QVector>

class ScanParams
{
//private://For testing public
public:
    qreal startPos;
    qreal finPos;
    qreal scanSpeed;
    QVector<bool> polSettings;
public:
    ScanParams();
    void clear();
};


#endif // SCANPARAMS_H
