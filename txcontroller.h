#ifndef TXCONTROLLER_H
#define TXCONTROLLER_H
#include <QObject>
#include <polarizer_control.h>
#include "../tcp_client_test/server.h"
#include "../remoteController/tx_thread.h"

class TXcontroller:public QObject
{
    Q_OBJECT
private:
    QString targetIP;
    quint32 port;
    int MonoPos = 0;
    QVector<bool> polarizerSetting;
    TX_master *mainClient, *MovementClient, *DataClient;
    Server *MainServer;
signals:
    //to mainClient
    void connectMain(void);
    //to MovementClient
    void connectFile(void);
    //to mainClient
    void connectData(void);
    //to MainServer
    void TXdata(QPair<QString, QPair<QString, QVariant> > data);
    //to extern
    void Data(QPair<int, int> data);
    void DPCCounts(int counts);
    void scanFinish(void);

    void ScanPos(qreal position);
    void MainClientStat(bool);
    void DataClientStat(bool);
    void MovClientStat(bool);
    //From stepper
    void currentPosition(int steps, bool dir);
    void stepperMoving(void);
    void movementFinish(void);
    void currentStepperStatus(int status);
    //from polarizercontrol
    void switchingSucceed(Polarizer pol);
    //To extern from TX
    void gotConnection(void);
    void gotNewFile(void);
public slots:
    //from mainClient
    void gotDataMain(QPair<QString, QPair<QString, QVariant> > data);
    void ClientStatus(bool status);
    //from MovementClient
    void gotDataFile(QPair<QString, QPair<QString, QVariant> > data);
    void MovClientStatus(bool status);
    //from DataClient
    void gotDataData(QPair<QString, QPair<QString, QVariant> > data);
    void DataClientStatus(bool status);
    //from MainServer
    void gotNewConnection(QVariant data);
    //From extern
    void SwitchPolarizer(Polarizer pol);
    void moveToTarget(int steps, bool dir);
    void runScan(int start, int stop, int accuracy);
    void shutDown(void);
public:
    TXcontroller(QString ipAddr, quint32 port, int MonoPos);
    ~TXcontroller();

};

#endif // TXCONTROLLER_H
