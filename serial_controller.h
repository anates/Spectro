#ifndef SERIAL_CONTROLLER_H
#define SERIAL_CONTROLLER_H
#include <QObject>
#include <QThread>
#include <QVector>
#include <memory>
#include <QtSerialPort/QtSerialPort>

class serial_controller_worker: public QObject
{
    Q_OBJECT
private:
    QString portName;
    QString request;
    int waitTimeout;
    QMutex mutex;
    QWaitCondition cond;
    int baudrate;
    QSerialPort *serial;
    bool quit;
    bool sendNewData = false;
    bool recvLoop = false;
public slots:
    void transaction(const QString &request);
signals:
    void response(QString s);
    void error(const QString &s);
    void timeout(const QString &s);
public:
    serial_controller_worker(const QString &portname, int waitTimeout, int BaudRate);
    ~serial_controller_worker();

    void process_data(void);
};

class serial_controller: public QObject
{
    Q_OBJECT
private:
    QThread workerThread;
    QString portName;
    QString request;
    int waitTimeout;
    QMutex mutex;
    QWaitCondition cond;
    int baudrate;
    QSerialPort serial;

public:
    serial_controller(const QString &portName, int waitTimeout, int BaudRate);
    ~serial_controller();

public slots:
    void transaction(const QString &request);
    void response_slot(QString response);
signals:
    void newTransaction(const QString &request);
    void response(QString s);
    void error(const QString &s);
    void timeout(const QString &s);
};

#endif // SERIAL_CONTROLLER_H
