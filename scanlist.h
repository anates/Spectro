#ifndef SCANLIST_H
#define SCANLIST_H
#include <scan.h>
#include <QObject>

class ScanList: public QObject
{
    Q_OBJECT
private:
    QVector<Scan> Scans;
    QVector<QString> ScanNames;
    QString fileName;
    QVector<QString> scanFileNames;
    qint32 currentScan;
public:
    ScanList();
    void addScan(Scan newScan);
    void dropScan(void);
    int getScanNumbers(void);
    int getCurrentScanNumber(void);
    Scan &getCurrentScan(void);
    Scan getNextScan(void);
    Scan getLastScan(void);
    Scan & getScan(quint32 ScanNumber);
    void setFileName(QString fileName);
    void setCurrentScan(int ScanNumber);
    QString getFileName(void);
    QVector<QString> getFileNames(void);
    void addFileName(QString fileName);
    void deleteFileName(QString fileName);
};


#endif // SCANLIST_H
