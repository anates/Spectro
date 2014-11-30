#ifndef DPC_H
#define DPC_H
#include <QThread>
#include <vector>
#include <memory>

#include "../BlackLib/v2_0/BlackLib.h"

class DPC_Worker:public QObject
{
    Q_OBJECT
};


class DPC_Master:public QObject
{
    Q_OBJECT
private:
    bool runThread;
    std::vector<std::unique_ptr<BlackLib::BlackGPIO> > A, B, C;
public:
    DPC_Master();
    ~DPC_Master();
public slots:
    void cancelThread(void);
signals:
    void currentCount(int);
};

#endif // DPC_H
