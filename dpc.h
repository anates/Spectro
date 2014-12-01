#ifndef DPC_H
#define DPC_H
#include <QThread>
#include <QDebug>
#include <vector>
#include <unistd.h>
#include <memory>

#include "../BlackLib/v2_0/BlackLib.h"



class DPC_Worker:public QObject
{
    Q_OBJECT
private:
    std::vector<std::unique_ptr<BlackLib::BlackGPIO> > A, B, C;
    volatile bool toDo;
    volatile bool stopAqu;
public slots:
    void stopAquisition(void);
    void aquireCounts(void);
signals:
    void currentCounts(int);
public:
    DPC_Worker();
    ~DPC_Worker();
};


class DPC_Master:public QObject
{
    Q_OBJECT
    QThread workerThread;
private:
    bool runThread;
public slots:
    void currentCounts(int counts);
signals:
    //Internal
    void stopAquisition(void);
    void startAquisition(void);
    //External
    void currentCount(int);
public:
    DPC_Master();
    ~DPC_Master();

};

#endif // DPC_H
