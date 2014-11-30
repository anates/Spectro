#ifndef SCAN_H
#define SCAN_H
#include "scandata.h"
#include "scanparams.h"
#include "logfile.h"

enum AveMode{ NoAverage, Point, Intervall };

class Scan
{
private:
    ScanData values;
    QString scanName;
    ScanParams Params;
    AveMode av;
    bool isCalibrated;
    LogFile log;
    bool readonly = false;
    bool isLoaded = false;
public:
    Scan();
    void clear(void);
};



#endif // SCAN_H
