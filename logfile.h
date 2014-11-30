#ifndef LOGFILE_H
#define LOGFILE_H
#include <QString>

class LogFile
{
private:
    bool logfileSet = false;
    QString name = "";
    qreal laserIntensity = 0;
    qreal slitWidth = 0;
    qreal sensitivity = 0;
    qreal countNumber = 0;
public:
    LogFile();
    void clear(void);
};


#endif // LOGFILE_H
