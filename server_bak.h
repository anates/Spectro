#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
//#include <QtTest/QTest>
#include <QSignalSpy>
#include <QTcpSocket>
#include <QDebug>
//#include <QMessageBox>
#include <QNetworkInterface>
#include <typeinfo>
//#include <QSignalSpy>

class Server : public QObject
{
    Q_OBJECT
public slots:
    void sessionOpened();


    void getInfo();
    void closeServer();
    void createConnection();
    void gotAConnection(void);
    void destroyConnection();
    void sendData(QVariant data);
    void showSignals(void);
signals:
    void gotNewConnection(QString);
private:
    QTcpServer *tcpServer;
    QString ipAddr;
    quint32 port;
    QTcpSocket *clientConnection;
    quint32 BlockSize;
    bool firstTime;
    QSignalSpy * m_pSignalSpy;
//    template <typename t>
//    void getD
public:
    Server(QString ipAddr, quint32 port);
};

#endif // SERVER_H
