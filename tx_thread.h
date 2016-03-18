#ifndef TX_THREAD_H
#define TX_THREAD_H

#include <QThread>
#include <QObject>
#include <QPair>
#include "../tcp_client_test/server.h"
#include "../tcp_client_test/client.h"

class TX_worker: public QObject
{
    Q_OBJECT
private:
    QString ipAddr;
    quint32 port;
    bool purpose; //true if TX, else RX
    Server *myServer;
    Client *myClient;
    bool stayConnected;
    QString clientPurpose;
    volatile bool toDo;
public slots:
    void gotData(QPair<QString, QPair<QString, QVariant> > data);//Intern
    void connect_to_TX(void);//Client
    void noServerFound(void);//Client
    void isConnected(bool status);//From Client
    void isDisconnected(bool status);//From Client
    void killTX(void);//All
signals:
    void gotNewData(QPair<QString, QPair<QString, QVariant> >);//Client
    void ClientIsConnected(bool);//To extern, from Client
    void ClientIsDisconnected(bool);//To extern, from Client
    void TXStopped(void);//All
    void connectRX(QString ipAddr, quint32 port);//Intern
    void killAll(void);//Intern
    void sendNewData(QVariant);//Intern
    void noServer(void);//Client

public:
    TX_worker(QString ipAddr, quint32 port, QString purpose);
    void run();
};

class TX_master: public QObject
{
    Q_OBJECT
private:
    bool clientStatus;
    QThread workerThread;
public slots:
    //From intern
    void newData(QPair<QString, QPair<QString, QVariant> > data);
    void noServer(void);
    void changeClientStatus(bool status);
    //From extern
    void connectTX(void);
signals:
    //To intern
    void connect_to_TX(void);
    //To extern
    void ClientStatus(bool);
    void gotNewData(QPair<QString, QPair<QString, QVariant> >);
    void wrongIP(void);
public:
    TX_master(QString ipAddr, quint32 port, QString purpose);
    ~TX_master();
};

#endif // TX_THREAD_H
