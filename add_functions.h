#ifndef ADD_FUNCTIONS_H
#define ADD_FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <fstream>
#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <sstream>

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
    QVector<bool> polSettings;
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

void read_unformatted_file(ScanData &Data, const QString &fileName);
void write_unformatted_file(const QMap<double, double> &Data, QString fileName);
void splitToDoubles(QPair<double, double> &valuePair, QString input);
void vectorToMap(const QVector<QPair<qreal, qreal> > &indata, QMap<qreal, qreal> &outdata);

#endif // ADD_FUNCTIONS_H
