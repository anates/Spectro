#include "tx_thread.h"


TX_worker::TX_worker(QString ipAddr, quint32 port, QString purpose)
{
    TX_worker::ipAddr = ipAddr;
    TX_worker::port = port;
    //TX_thread::purpose = purpose;
    TX_worker::stayConnected = true;
    TX_worker::toDo = false;
    myClient = new Client(purpose);
    connect(this, SIGNAL(connectRX(QString,quint32)), myClient, SLOT(connectToServer(QString,quint32)));
    connect(myClient, &Client::gotData, this, &TX_worker::gotData);
    connect(myClient, &Client::noConnection, this, &TX_worker::noServer);
    connect(this, &TX_worker::killAll, myClient, &Client::disconnectFromServer);
    connect(myClient, &Client::isDisconnect, this, &TX_worker::isDisconnected);
    connect(myClient, &Client::connectionResult, this, &TX_worker::isConnected);
    TX_worker::clientPurpose = purpose;
    myServer = NULL;
}

void TX_worker::killTX(void)
{
    TX_worker::stayConnected = false;
    emit TXStopped();
}

void TX_worker::connect_to_TX(void)
{
    emit connectRX(TX_worker::ipAddr, TX_worker::port);
}

void TX_worker::gotData(QPair<QString, QPair<QString, QVariant> > data)
{
    qDebug() << "New data: " << data.first << " " << data.second.second.toInt() << " on port " << this->port;
    emit gotNewData(data);
}

void TX_worker::noServerFound(void)
{
    emit noServer();
}

void TX_worker::isConnected(bool status)
{
    emit ClientIsConnected(status);
}

void TX_worker::isDisconnected(bool status)
{
    emit ClientIsDisconnected(status);
}

//TX-master

TX_master::TX_master(QString ipAddr, quint32 port, QString purpose)
{
    TX_worker *newTX = new TX_worker(ipAddr, port, purpose);
    newTX->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newTX, &QObject::deleteLater);
    connect(newTX, &TX_worker::gotNewData, this, &TX_master::newData);
    connect(newTX, &TX_worker::noServer, this, &TX_master::noServer);
    connect(this, &TX_master::connect_to_TX, newTX, &TX_worker::connect_to_TX);
    connect(newTX, &TX_worker::ClientIsConnected, this, &TX_master::changeClientStatus);
    connect(newTX, &TX_worker::ClientIsDisconnected, this, &TX_master::changeClientStatus);
    this->clientStatus = false;
    workerThread.start();
}

TX_master::~TX_master()
{
    workerThread.quit();
    workerThread.wait();
}

void TX_master::newData(QPair<QString, QPair<QString, QVariant> > data)
{
    //qDebug() << "Got new data: " << data.first << " " << data.second.toInt() << "!";
    emit gotNewData(data);
}

void TX_master::noServer()
{
    emit wrongIP();
}

void TX_master::connectTX()
{
    emit connect_to_TX();
}

void TX_master::changeClientStatus(bool status)
{
    this->clientStatus = status;
    emit this->ClientStatus(status);
}
