#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>

class QComboBox;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

class Client : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *tcpSocket;
    QString currentFortune;
    quint16 blockSize;
    QVariant data;
    QNetworkSession *networkSession;

signals:
    void gotData(QVariant);
    void noConnection(void);
private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    void getInfo();
    void readData();
    void connectToServer(QString ipAddr, quint32 port);
    void disconnectFromServer();
private:

public:


    Client();
};

#endif // CLIENT_H
