#include <QtNetwork>

#include <stdlib.h>

#include "server.h"

Server::Server(QString ipAddr, quint32 port, QString purpose)
:  tcpServer(0), networkSession(0)
{
    Server::clientConnection = NULL;
    Server::purpose = purpose;
    Server::port = port;
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        //statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    } else {
        sessionOpened();
    }

        fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
                 << tr("You've got to think about tomorrow.")
                 << tr("You will be surprised by a loud noise.")
                 << tr("You will feel hungry again in another hour.")
                 << tr("You might have mail.")
                 << tr("You cannot kill time without injuring eternity.")
                 << tr("Computers are not intelligent. They only think they are.");
        //connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendFortune()));
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(openNewConnection()));
        //connect(tcpServer, &QTcpServer::newConnection, this, &Server::openNewConnection);
}

void Server::sessionOpened()
{
    // Save the used configuration
    if (networkSession) {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any, Server::port)) {
        return;
    }
    qDebug() << "Server listening on: " << tcpServer->serverPort();
//! [0]
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

//! [1]
}

void Server::openNewConnection(void)
{
    Server::clientConnection = tcpServer->nextPendingConnection();
    QVariant ipAddr_QVar(clientConnection->peerAddress().toString());
    emit gotNewConnection(ipAddr_QVar);
}

//! [4]
void Server::sendFortune(void)
{

//! [5]
    QString data = "";
    static int counter = 0;
    if(!purpose.isEmpty() && counter == 0)
    {
        data = purpose;
        //counter++;
    }
    else
        data = fortunes.at(qrand() % fortunes.size());
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
//! [4] //! [6]
    out << (quint16)0;
    QVariant qw(data);
    out << qw;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
//! [6] //! [7]

    //Server::clientConnection = tcpServer->nextPendingConnection();
    if(Server::clientConnection != NULL)
    {
        qDebug() << "New Connection: " << Server::clientConnection->peerAddress().toString() << " on Port: " << Server::clientConnection->peerPort();
        QVariant ipAddr_QVar(Server::clientConnection->peerAddress().toString());
        qDebug() << "New qvariant: " << ipAddr_QVar;

        clientConnection->write(block);
        //connect(clientConnection, &QTcpSocket::disconnected,clientConnection, &QTcpSocket::deleteLater);
        //disconnectServer();
    }
    else
        qDebug() << "No connection!";


//! [5]
}
//! [8]

void Server::textFortune()
{
    qDebug() << "Spamming fortunes!";
    QByteArray data = fortunes[counter%7].toUtf8();
    this->counter++;
    if(Server::clientConnection != NULL)
    {
        std::string s= std::to_string(data.size());
        char const * size = s.c_str();
        for(int i = 0; i < 1; i++)
        {
            qDebug() << "Written size bytes: " << clientConnection->write(size);
            qDebug() << "Size reported in textFortune is " << size;
            clientConnection->write(data);
        }
        qDebug() << "All data written? " << clientConnection->waitForBytesWritten();
        qDebug() << "Size is: " << size;
    }
    else
        qDebug() << "No connection";
}

QByteArray Server::QPairToByteArray(QPair<QString, QPair<QString, QVariant> > data)
{
    QByteArray ret_data;
    QDataStream stream(&ret_data, QIODevice::WriteOnly);
    stream << data;
    return ret_data;
}

void Server::textData(QPair<QString, QPair<QString, QVariant> > data)
{
    QByteArray ArrayData = this->QPairToByteArray(data);
    this->counter++;
    if(Server::clientConnection != NULL)
    {
        std::string s= std::to_string(ArrayData.size());
        char const * size = s.c_str();
        qDebug() << "Written size bytes: " << clientConnection->write(size);
        qDebug() << "Size reported in textFortune is " << size;
        clientConnection->write(ArrayData);
        qDebug() << "All data written? " << clientConnection->waitForBytesWritten();
        qDebug() << "Size is: " << size;
    }
    else
        qDebug() << "No connection";
}

void Server::spamFortunes()
{
    for(int i = 0; i < 1000; i++)
    {
        qDebug() << "Current fortuneround is: " << i;
        this->textFortune();
    };
}

void Server::disconnectServer(void)
{
    Server::clientConnection->disconnectFromHost();
}


void Server::sendData(QPair<QString, QPair<QString, QVariant> > data)
{
//! [5]
    //QString data = "";
    qDebug() << "Transmitted data in send-data-function is: " + data.first + " " + data.second.first + " " + QString::number(data.second.second.toDouble());
    QPair<QString, QPair<QString, QVariant> > send_data = data;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << (quint16)0;
    out << send_data;
    qDebug() << "In-status after read: " << out.status();
    Q_ASSERT(out.status() == QDataStream::Ok);
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    qDebug() << "In-status after read: " << out.status();
    Q_ASSERT(out.status() == QDataStream::Ok);
    if(Server::clientConnection != NULL)
    {
        qDebug() << "New Connection: " << Server::clientConnection->peerAddress().toString() << " on Port: " << Server::clientConnection->peerPort();
        QVariant ipAddr_QVar(Server::clientConnection->peerAddress().toString());
        qDebug() << "New qvariant: " << ipAddr_QVar;

        clientConnection->write(block);
        qDebug() << "Block written";
    }
    else
        qDebug() << "No connection!";
}

void Server::sendFile(QVariant fileName)
{
    qDebug() << "SendFile invoked!";
    QString data = "";
    static int counter = 0;
    QByteArray block;
    QFile file;
    file.fileName() = fileName.toString();
    // If the selected file is valid, continue with the upload
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
//! [4] //! [6]
    out << (quint16)0;
    QVariant qw(data);
    if(!purpose.isEmpty() && counter == 0)
    {
        out << purpose;
        //counter++;
    }
    else
        out << file.readAll();
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    if(Server::clientConnection != NULL)
    {
        qDebug() << "New Connection: " << Server::clientConnection->peerAddress().toString() << " on Port: " << Server::clientConnection->peerPort();
        QVariant ipAddr_QVar(Server::clientConnection->peerAddress().toString());
        qDebug() << "New qvariant: " << ipAddr_QVar;

        clientConnection->write(block);
        //connect(clientConnection, &QTcpSocket::disconnected,clientConnection, &QTcpSocket::deleteLater);
        //disconnectServer();
    }
    else
        qDebug() << "No connection!";
}
//! [8]
