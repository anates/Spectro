#include "server.h"


Server::Server(QString ipAddr, quint32 port)
{
    Server::ipAddr = ipAddr;
    Server::port = port;
    firstTime = true;
    sessionOpened();
    qDebug() << "New server created (from Server)!";
}

void Server::showSignals()
{
    exit(0);
    qCritical() << m_pSignalSpy->wait(10000);
//    for(int index = 0; index<m_pSignalSpy->size(); index++)
//    {
//        QList<QVariant> listItem = m_pSignalSpy->value(index);

//        qDebug() << "Signal Arguments: ";
//        for(int index2 = 0;index2 < listItem.size();index2++)
//        {
//            qDebug() << listItem[index2].toString().toStdString()<<" ";
//        }
//    }
}

void Server::sessionOpened()
{
    Server::tcpServer = new QTcpServer(this);
    connect(Server::tcpServer, &QTcpServer::newConnection, this, &Server::createConnection);
    connect(Server::tcpServer, &QTcpServer::newConnection, this, &Server::gotAConnection);
    qDebug() << "Connections created!";
    if(!Server::tcpServer->listen(QHostAddress::Any, (quint16)Server::port))
    {
        //QMessageBox::information(this, tr("Server"), tr("Unable to start the server: %1.").arg(Server::tcpServer->errorString()));
        Server::tcpServer->close();
        exit(0);
        return;
    }

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            Server::ipAddr = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (Server::ipAddr.isEmpty())
        Server::ipAddr = QHostAddress(QHostAddress::LocalHost).toString();

    qDebug() << Server::ipAddr;
    qDebug() << Server::tcpServer->hasPendingConnections();
//    connect(Server::tcpServer, SIGNAL(newConnection()), this, SLOT(gotAConnection()));
//    Server::m_pSignalSpy = new QSignalSpy(Server::tcpServer, SIGNAL(newConnection()));
//    connect(Server::tcpServer, SIGNAL(newConnection()), this, SLOT(showSignals()));
}

void Server::getInfo()
{
    sendData("Hello");
}

void Server::destroyConnection()
{
    Server::clientConnection->disconnectFromHost();
}

void Server::gotAConnection()
{
    qDebug() << "Got new Connection!";
    exit(0);
}

void Server::createConnection()
{
    qDebug() << "Got new connection, more info later!";
    Server::clientConnection = tcpServer->nextPendingConnection();
    qDebug() << "Got new connection from " << Server::clientConnection->peerAddress().toString();
    emit Server::gotNewConnection(Server::clientConnection->peerAddress().toString());
}

void Server::sendData(QVariant data)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << data;// << '\n' << data.type();
    qCritical() << "Sending Data!";
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));
    clientConnection->write(block);
}

void Server::closeServer()
{
    destroyConnection();
    return;
}
