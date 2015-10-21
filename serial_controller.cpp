#include "serial_controller.h"

serial_controller_worker::serial_controller_worker(const QString &portname, int waitTimeout, int BaudRate)
{
    this->portName = portname;
    this->waitTimeout = waitTimeout;
    this->baudrate = BaudRate;
    this->serial = new QSerialPort(this);
    this->serial->setPortName(this->portName);
    this->serial->setBaudRate(this->baudrate);
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
    this->serial->close();
}

void serial_controller_worker::process_data()
{
    bool newData = false;
    bool run = false;
    this->mutex.lock();
    newData = this->sendNewData;
    run = this->recvLoop;
    this->mutex.unlock();
    if(run == false)
    {
        qDebug() << "Run is false, returning!";
        return;
    }
    else
    {
        if(newData == true)
        {
            qDebug() << "TransAction started!";
            QByteArray requestData = request.toLocal8Bit();
            qDebug() << "Writing data: " << requestData;
            serial->write(requestData);
            qDebug() << "Data written";
            if(serial->waitForBytesWritten(waitTimeout))
            {
                if(serial->waitForReadyRead(waitTimeout))
                {
                    qDebug() << "Waiting for data!";
                    QByteArray responseData = serial->readAll();
                    while(serial->waitForReadyRead(10))
                        responseData += serial->readAll();
                    QString response(responseData);
                    QByteArray response_arr = response.toLocal8Bit();
                    qDebug() << "Response is: " << response_arr.toHex();
                    emit this->response(response);
                }
                else
                {
                    qDebug() << "Wait read response timeout";
                    emit this->timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
                }
            }
            else
            {
                qDebug() << "Wait write request timeout!";
                emit this->timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));
            }
            mutex.lock();
            this->sendNewData = false;
            mutex.unlock();
        }
//        else
//        {
//            if(serial.waitForReadyRead(waitTimeout))
//            {
//                qDebug() << "Waiting for data!";
//                QByteArray responseData = serial.readAll();
//                while(serial.waitForReadyRead(10))
//                    responseData += serial.readAll();
//                QString response(responseData);
//                QByteArray response_arr = response.toLocal8Bit();
//                qDebug() << "Response is: " << response_arr.toHex();
//                emit this->response(response);
//            }
//            else
//            {
//                qDebug() << "Wait read response timeout";
//                emit this->timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
//            }
//        }
        QThread::msleep(10);
//        this->process_data();
    }

}

void serial_controller_worker::transaction(const QString &request)
{
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
        mutex.lock();
        qDebug() << "Got new request, transmitting!";
        this->sendNewData = true;
        this->recvLoop = true;
        this->request = request;
        mutex.unlock();
        this->process_data();
}


//Serial_controller functions
serial_controller::serial_controller(const QString &portName, int waitTimeout, int BaudRate)
{
    serial_controller_worker *newWorker = new serial_controller_worker(portName, waitTimeout, BaudRate);
    newWorker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newWorker, &QObject::deleteLater);
    connect(this, &serial_controller::newTransaction, newWorker, &serial_controller_worker::transaction);
    connect(newWorker, &serial_controller_worker::response, this, &serial_controller::response_slot);
    workerThread.start();
//    this->portName = portName;
//    this->waitTimeout = waitTimeout;
//    this->baudrate = BaudRate;
//    this->serial.setPortName(this->portName);
//    this->serial.setBaudRate(this->baudrate);
//    if (!serial.open(QIODevice::ReadWrite))
//    {
//        emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial.error()));
//        return;
//    }
}

serial_controller::~serial_controller()
{
    workerThread.quit();
    workerThread.wait();
}

void serial_controller::transaction(const QString &request)
{
    qDebug() << "Sent new transaction request " << request << " to worker!";
    emit this->newTransaction(request);
}



void serial_controller::response_slot(QString response)
{
    emit this->response(response);
}

