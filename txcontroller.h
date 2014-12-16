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
    TX_master *mainClient, *fileClient;
    Server *MainServer;
signals:
    //to mainClient
    void connectMain(void);
    //to fileClient
    void connectFile(void);
    //to MainServer
    void TXdata(QPair<QString, QVariant> data);
    //to extern
    void Data(QPair<int, int> data);
    void DPCCounts(int counts);
    void scanFinish(void);
    void ScanPos(qreal position);
    //From stepper
    void currentPosition(int steps, bool dir);
    void stepperMoving(void);
    //from polarizercontrol
    void switchingSucceed(Polarizer pol);
    //To extern from TX
    void gotConnection(void);
    void gotNewFile(void);
public slots:
    //from mainClient
    void gotDataMain(QPair<QString, QVariant> data);
    //from fileClient
    void gotDataFile(QPair<QString, QVariant> data);
    //from MainServer
    void gotNewConnection(QVariant data);
    //From extern
    void SwitchPolarizer(Polarizer pol);
    void moveToTarget(int steps, bool dir);
    void runScan(int start, int stop, int accuracy);
public:
    TXcontroller(QString ipAddr, quint32 port, int MonoPos);
    ~TXcontroller();

};

#endif // TXCONTROLLER_H
