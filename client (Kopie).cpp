#include <QtWidgets>
#include <QtNetwork>
#include "client.h"

Client::Client() : networkSession(0)
{
    tcpSocket = new QTcpSocket;
    Client::blockSize = 0;
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
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
    }
}

void Client::connectToServer(QString ipAddr, quint32 port)
{
    qDebug() << "Connecting to Host on port " << port << ' ' << (quint16)port;
    tcpSocket->connectToHost(ipAddr, port);
    qDebug() << "Am I connected? " << tcpSocket->state();
}

void Client::disconnectFromServer()
{
    tcpSocket->disconnectFromHost();
}

void Client::getInfo()
{

}

void Client::readData()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() < blockSize)
    {
        qDebug() << tcpSocket->bytesAvailable() << ' ' << blockSize;
        return;
    }
    in >> data;
    blockSize = 0;
    emit Client::gotData(data);

}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug() << "The host was not found. Please check the host name and port settings.";
        emit Client::noConnection();
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug() << "The connection was refused by the peer. \n Make sure the fortune server is running, and check that the host name and port settings are correct.";
        emit Client::noConnection();
        break;
    default:
        qDebug() << "The following error occurred: " << tcpSocket->errorString() << '\n';
    }

}


void Client::sessionOpened()
{
    // Save the used configuration
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
