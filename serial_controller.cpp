#include "serial_controller.h"

serial_controller_worker::serial_controller_worker(const QString &portname, int waitTimeout, int BaudRate, int numStopBits, bool parity, bool useParity)
{
    this->portName = portname;
    this->waitTimeout = waitTimeout;
    this->baudrate = BaudRate;
    this->numStopBits = numStopBits;
    this->useParity = useParity;
    this->parity = parity;
    this->serial = new QSerialPort(this);
    this->storage = "";
    this->delay_write = 0;
    connect(this->serial, &QSerialPort::readyRead, this, &serial_controller_worker::read_data);
    this->serial->setPortName(this->portName);
    this->serial->setDataBits(QSerialPort::Data8);
    this->serial->setBaudRate(this->baudrate);
    this->serial->setStopBits((this->numStopBits==2)?QSerialPort::TwoStop:QSerialPort::OneStop);
    this->serial->setParity((this->useParity?(this->parity?QSerialPort::OddParity:QSerialPort::EvenParity):QSerialPort::NoParity));
    qDebug() << "Using " << this->baudrate << " and " << this->useParity << " as parity and " << this->numStopBits << " as stopbits and " << (this->useParity?(this->parity?QSerialPort::OddParity:QSerialPort::EvenParity):QSerialPort::NoParity) << " as parity";
    if (!serial->open(QIODevice::ReadWrite))
    {
        emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial->error()));
        qDebug() << tr("Can't open %1, error code %2").arg(portName).arg(serial->error());
        return;
    }
    else
    {
        emit error(tr("Opened %1").arg(portName));
        qDebug() << tr("Opened %1").arg(portName);
    }
}

serial_controller_worker::~serial_controller_worker()
{
    if(this->serial->isOpen())
        this->serial->close();
    if(this->serial != NULL)
        delete this->serial;
}

void serial_controller_worker::read_data()
{
    //qDebug() << "Reading data";
    QByteArray data = this->serial->readAll();
    //qDebug() << "Data is: " << data;
    storage += QString::fromLatin1(data.data());
    //emit this->response(QString::fromLatin1(data.data()));
    if(data == ">")
    {
        emit this->response(storage);
        this->storage = "";
    }

}

void serial_controller_worker::process_data()
{
}

void serial_controller_worker::transaction(const QString &request, int delay)
{
//    qDebug() << "TransAction started!";
    this->delay_write = delay;
    QString request_enter = request + QString("\x00D");
    QByteArray requestData = request_enter.toLocal8Bit();
    QThread::msleep((this->delay_write)*1000);
    qDebug() << "Writing data: " << requestData;
    serial->write(requestData);
    //qDebug() << "Data written";
//    if(serial.waitForBytesWritten(waitTimeout))
//    {
//        if(serial.waitForReadyRead(waitTimeout))
//        {
//            qDebug() << "Waiting for data!";
//            QByteArray responseData = serial.readAll();
//            while(serial.waitForReadyRead(10))
//                responseData += serial.readAll();
//            QString response(responseData);
//            QByteArray response_arr = response.toLocal8Bit();
//            qDebug() << "Response is: " << response_arr.toInt();
//            emit this->response(response);
//        }
//        else
//        {
//            qDebug() << "Wait read response timeout";
//            emit this->timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
//        }
//    }
//    else
//    {
//        qDebug() << "Wait write request timeout!";
//        emit this->timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));
//    }

    //    qDebug() << "Starting transaction!";
    //    emit this->newTransaction(request);

    //    qDebug() << "TransAction started!";
    //    QByteArray requestData = request.toLocal8Bit();
    //    qDebug() << "Writing data: " << requestData;
    //    serial.write(requestData);
    //    qDebug() << "Data written";
    //    if(serial.waitForBytesWritten(waitTimeout))
    //    {
    //        if(serial.waitForReadyRead(waitTimeout))
    //        {
    //            qDebug() << "Waiting for data!";
    //            QByteArray responseData = serial.readAll();
    //            while(serial.waitForReadyRead(10))
    //                responseData += serial.readAll();
    //            QString response(responseData);
    //            QByteArray response_arr = response.toLocal8Bit();
    //            qDebug() << "Response is: " << response_arr.toHex();
    //            emit this->response(response);
    //        }
    //        else
    //        {
    //            qDebug() << "Wait read response timeout";
    //            emit this->timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
    //        }
    //    }
    //    else
    //    {
    //        qDebug() << "Wait write request timeout!";
    //        emit this->timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));
    //    }
//        mutex.lock();
//        qDebug() << "Got new request, transmitting!";
//        this->sendNewData = true;
//        this->recvLoop = true;
//        this->request = request;
//        mutex.unlock();
//        this->process_data();
//    QByteArray writData = request.toLocal8Bit();
//    this->serial->writeData(writData);
}

//Updater-class
updater::updater(int update_frequency)
{
    this->frequency = update_frequency;
}

updater::~updater()
{

}

//Serial_controller functions
serial_controller::serial_controller(const QString &portName, int waitTimeout, int BaudRate, int numStopBits, bool parity, bool useParity, bool useEchoMode)
{
    serial_controller_worker *newWorker = new serial_controller_worker(portName, waitTimeout, BaudRate, numStopBits, parity, useParity);
    newWorker->moveToThread(&workerThread);
    this->EchoMode = useEchoMode;
    connect(&workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &serial_controller::newTransaction, newWorker, &serial_controller_worker::transaction);
    connect(newWorker, &serial_controller_worker::response, this, &serial_controller::response_slot);
    workerThread.start();

//    this->portName = portName;
//    this->waitTimeout = waitTimeout;
//    this->baudrate = BaudRate;
//    this->numStopBits = numStopBits;
//    this->useParity = useParity;
//    this->parity = parity;
//    this->serial = new QSerialPort(this);
//    qDebug() << "Connect working: " << connect(this->serial, &QSerialPort::readyRead, this, &serial_controller::read_data);
//    this->serial->setPortName(this->portName);
//    this->serial->setDataBits(QSerialPort::Data8);
//    this->serial->setBaudRate(this->baudrate);
//    this->serial->setStopBits((this->numStopBits==2)?QSerialPort::TwoStop:QSerialPort::OneStop);
//    this->serial->setParity((this->useParity?(this->parity?QSerialPort::OddParity:QSerialPort::EvenParity):QSerialPort::NoParity));
//    qDebug() << "Using " << this->baudrate << " and " << this->useParity << " as parity and " << this->numStopBits << " as stopbits and " << (this->useParity?(this->parity?QSerialPort::OddParity:QSerialPort::EvenParity):QSerialPort::NoParity) << " as parity";
//    if (!serial->open(QIODevice::ReadWrite))
//    {
//        emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial->error()));
//        qDebug() << tr("Can't open %1, error code %2").arg(portName).arg(serial->error());
//        return;
//    }
//    else
//    {
//        emit error(tr("Opened %1").arg(portName));
//        qDebug() << tr("Opened %1").arg(portName);
//    }
}

serial_controller::~serial_controller()
{
    workerThread.quit();
    workerThread.wait();
//    if(this->serial->isOpen())
//        this->serial->close();
//    if(this->serial != NULL)
//        delete this->serial;
}

void serial_controller::transaction(const QString &request, int delay)
{
    qDebug() << "Sent new transaction request " << request << " to worker!";
    emit this->newTransaction(request, delay);
//    QByteArray requestData = request.toLocal8Bit();
//    qDebug() << "Writing data: " << requestData;
//    serial->write(requestData);
//    qDebug() << "Data written";
}

void serial_controller::read_data()
{
//    qDebug() << "Reading data";
//    QByteArray data = this->serial->readAll();
//    qDebug() << "Data is: " << data;
//    emit this->response(QString::fromLatin1(data.data()));
}

void serial_controller::response_slot(QString response)
{
    if(this->EchoMode)
    {
        QStringList splitList = response.split('\n', QString::SkipEmptyParts);
        QString dataString = splitList[1].remove(splitList[1].length()-1);
        QStringList splitList2 = dataString.split('E');
        if(splitList2.length() == 2)
        {
            double value = splitList2[0].toDouble();
            double mantisse = splitList2[1].toDouble();
            value *= pow(10, mantisse);
            emit this->CountValue(value);
        }
        else
        {
            QVector<QString> returnVector;
            returnVector.push_back(splitList[0]);
            returnVector.push_back(splitList[1]);
            emit this->response(returnVector);
        }
    }
    else
    {
        QStringList splitList2 = response.split('E');
        if(splitList2.length() == 2)
        {
            double value = splitList2[0].toDouble();
            double mantisse = splitList2[1].toDouble();
            value *= pow(10, mantisse);
            emit this->CountValue(value);
        }
        else
        {
            QVector<QString> returnVector;
            returnVector.push_back("E");
            returnVector.push_back(response);
            emit this->response(returnVector);
        }
    }
}

