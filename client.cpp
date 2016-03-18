//#include <QtWidgets>
#include <QtNetwork>
#include "client.h"

Client::Client(QString purpose) : networkSession(0)
{
    Client::purpose = purpose;
    tcpSocket = new QTcpSocket;
    Client::blockSize = 0;
    //connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::ReadAllData);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Client::NewDataAvailable);
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
    //qDebug() << "Connecting to Host on port " << port << ' ' << (quint16)port;
    tcpSocket->connectToHost(ipAddr, port);
    emit this->connectionResult((tcpSocket->state() == QAbstractSocket::UnconnectedState)?false:true);
}

void Client::disconnectFromServer()
{
    tcpSocket->disconnectFromHost();
    emit this->isDisconnect((tcpSocket->state() == QAbstractSocket::UnconnectedState)?true:false);
}

void Client::getInfo()
{

}

void Client::NewDataAvailable(void)
{
    //qDebug() << "New package arrived";
}

void Client::readData()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_0);
    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() < blockSize)
    {
        //qDebug() << tcpSocket->bytesAvailable() << ' ' << blockSize;
        return;
    }
    in >> data;
    //qDebug() << "In-status after read: " << in.status();
    Q_ASSERT(in.status() == QDataStream::Ok);
    blockSize = 0;
    //qDebug() << "Client got new data!";
    //qDebug() << data.first << " " << " " << data.second.first << " " << data.second.second.toInt();
    emit this->gotData(data);

}

QPair<QString, QPair<QString, QVariant> > Client::topair(QByteArray &data)
{
    QPair<QString, QPair<QString, QVariant> > pair;
    QDataStream stream(&data, QIODevice::ReadOnly);
    stream >> pair;
    return pair;
}

void Client::ReadAllData()
{
//    qDebug() << "Got new data!";
//    QByteArray buffer;
//    int counter = 0;
//    while(tcpSocket->bytesAvailable())
//    {
//        char *dataS = new char[3];
//        dataS[2] = '\0';
//        int dataSize = 57;
//        qDebug() << tcpSocket->read(dataS, 2*sizeof(char));
//        qDebug() << "Data size read from incoming is " << dataS;
//        dataSize = atoi(dataS);
//        buffer = tcpSocket->read(dataSize);
//        qDebug() << "Current filling stand of buffer is: " << buffer.size();
//        qDebug() << "Is my buffer empty?" << buffer.isEmpty();
//        while(buffer.size() < dataSize) // only part of the message has been received
//        {
//            qDebug() << "Waiting for data!";
//            counter++;
//            tcpSocket->waitForReadyRead(); // alternatively, store the buffer and wait for the next readyRead()
//            buffer.append(tcpSocket->read(dataSize - buffer.size())); // append the remaining bytes of the message
//            if(counter == 1000)
//                break;
//            qDebug() << QString(buffer);
//        }
//        delete dataS;
//        qDebug() << "Data is here";

//    }
//    QPair<QString, QPair<QString, QVariant> > ret_arr = this->topair(buffer);
//    emit this->gotData(ret_arr);

    QDataStream in(tcpSocket);
    QPair<QString, QPair<QString, QVariant> > tmp_data;
    //qDebug() << "I got new data!\n";
    //qDebug() << data.first << " " << " " << data.second.first << " " << data.second.second.toInt();
    blockSize = 0;
    in.setVersion(QDataStream::Qt_5_0);
    if (blockSize == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }
    if (tcpSocket->bytesAvailable() < blockSize)
    {
        //qDebug() << "Too few blocks available: " << QString::number(tcpSocket->bytesAvailable()) << ' ' << blockSize;
        //qDebug() << "Client got new data!";
        in >> tmp_data;
        //qDebug() << tmp_data.first << " " << " " << tmp_data.second.first << " " << tmp_data.second.second.toInt();
        //qDebug() << tmp_data;

        //return;
    }
    else
        in >> tmp_data;
    data = tmp_data;
    //qDebug() << "Current Block input size is: " << blockSize;
    blockSize = 0;
    //qDebug() << "ClientX got new data!";
    //qDebug() << data.first << " " << " " << data.second.first << " " << data.second.second.toInt();
    //qDebug() << "Emitting signal!";
    emit this->gotData(data);
    //qDebug() << "Signal emitted!";
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
        qDebug() << "The connection was refused by the peer. \n Make sure the server is running, and check that the host name and port settings are correct.";
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
