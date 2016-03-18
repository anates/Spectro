#ifndef CLIENT_H
#define CLIENT_H

//#include <QDialog>
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
    QPair<QString, QPair<QString, QVariant> > data;
    QNetworkSession *networkSession;
    QString purpose;

signals:
    void gotData(QPair<QString, QPair<QString, QVariant> >);
    void noConnection(void);
    void connectionResult(bool);
    void isDisconnect(bool);
public slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    void getInfo();
    void readData();
    void connectToServer(QString ipAddr, quint32 port);
    void disconnectFromServer();
private:

public:


    Client(QString purpose);
};

#endif // CLIENT_H
