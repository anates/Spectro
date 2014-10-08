//Sämtliche Datentypen für den Scan werden hier definiert
#include <QMap>
#include <QVector>
#include <QPair>

#define RAMAN

enum AveMode{ NoAverage, Point, Intervall };

struct ScanData
{
    QVector<QPair<qreal, qreal> > Data;
    QVector<QPair<qreal, qreal> > Maxima;
    QVector<QPair<qreal, qreal> > FWHM;
};

struct Scan
{
    ScanData values;
    QVector<bool> polSettings[3];
    QString scanName;
    qreal startPos;
    qreal finPos;
    qreal scanSpeed;
    AveMode av;
};

struct ScanList
{
    QVector<Scan> Scans;
    QString fileName;
    QVector<QString> scanFileNames;
};
