#ifndef LOGFILE_H
#define LOGFILE_H
#include <QString>
#include <QVector>

class LogFile
{
//private://For testing public
public:
    bool logfileSet = false;
    QString name = "";
    qreal laserIntensity = 0;
    QVector<qreal> slits = {0, 0, 0, 0};
    qreal oldSlit;
    qreal sensitivity = 0;
    qreal countNumber = 0;
public:
    LogFile();
    QString & getName();
    qreal & getIntensity();
    QVector<qreal> & getSlit();
    qreal &getOldSlit();
    qreal & getSensitivity();
    qreal & getCount();
    void clear(void);
};


#endif // LOGFILE_H
