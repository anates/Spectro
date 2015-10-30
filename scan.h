#ifndef SCAN_H
#define SCAN_H
#include "scandata.h"
#include "scanparams.h"
#include "logfile.h"

enum AveMode{ NoAverage, Point, Intervall };

class Scan
{
//private://For testing public, has to be reverted
public:
    ScanData values;
    QString scanName;
    ScanParams Params;
    AveMode av;
    bool isCalibrated;
    LogFile log;
    bool hasWN;
    bool readonly = false;
    bool isLoaded = false;
    double Central_WL;
public:
    Scan();
    ScanData getValues(void);
    ScanData& setValues(void);
    LogFile & getLog(void);
    void clear(void);
};



#endif // SCAN_H
