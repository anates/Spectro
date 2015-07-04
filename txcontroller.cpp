#include "txcontroller.h"

TXcontroller::TXcontroller(QString ipAddr, quint32 port, int MonoPos)
{
    this->MonoPos = MonoPos;
    this->port = port;
    this->targetIP = ipAddr;
    MainServer = new Server(ipAddr, port + 1, "MAIN");
    mainClient = new TX_master(ipAddr, port, "MAIN");
    fileClient = new TX_master(ipAddr, port + 2, "FILE");

    //connect(this, &TXcontroller::TXdata, MainServer, &Server::sendData);
    connect(this, &TXcontroller::TXdata, MainServer, &Server::textData);
    connect(this, &TXcontroller::connectMain, mainClient, &TX_master::connectTX);
    connect(this, &TXcontroller::connectFile, fileClient, &TX_master::connectTX);
    connect(mainClient, &TX_master::ClientStatus, this, &TXcontroller::ClientStatus);
    connect(fileClient, &TX_master::ClientStatus, this, &TXcontroller::DataClientStatus);
    connect(mainClient, &TX_master::gotNewData, this, &TXcontroller::gotDataMain);
    connect(fileClient, &TX_master::gotNewData, this, &TXcontroller::gotDataFile);

    emit connectMain();
    emit connectFile();

}

TXcontroller::~TXcontroller()
{

}

void TXcontroller::SwitchPolarizer(Polarizer pol)
{
    //emit TXdata(qMakePair(QString("POL"), QVariant(pol)));???Has to be updated???
}

void TXcontroller::moveToTarget(int steps, bool dir)
{
    emit TXdata(qMakePair(QString("STP"), qMakePair(QString("M"), QVariant(steps * (dir?1:-1)))));//???Has to be updated???
}

void TXcontroller::runScan(int start, int stop, int accuracy)
{
    //Muss noch entwickelt werden
}

void TXcontroller::gotDataMain(QPair<QString, QPair<QString, QVariant> > data)
{
    qDebug() << "Got the following new data: " + data.first + " " + data.second.first + " " + data.second.second.toString();
    if(data.first == "STP")
    {
        //qDebug() << "STP " + data.second.first + " " + data.second.second.toString();
        if(data.second.first == "M" && data.second.second.toInt() == 0)
        {
            qDebug() << "STP should finish";
            emit scanFinish();
        }
        else if(data.second.first == "M" && data.second.second.toInt() == 1)
        {
            qDebug() << "STP should move";
            emit stepperMoving();
        }
        else if(data.second.first == "P")
        {
            qDebug() << "Got new position data!";
            emit currentPosition(fabs(data.second.second.toInt()), data.second.second.toInt() >= 0);
            emit scanFinish();//Hacky, könnte verbessert werden???
        }
        else if(data.second.first == "S")
        {
            qDebug() << "Current Movement Status: ";
            emit this->currentStepperStatus(data.second.second.toInt());
        }
    }
    else if(data.first == "DPC")
    {
        qDebug() << "Got new count data\n";
        emit DPCCounts(data.second.second.toInt());
    }
    else if(data.first == "SCN")
    {
        if(data.second.first == "P")
        {
            emit ScanPos(data.second.second.toDouble());
        }
        if(data.second.first == "S")
            emit scanFinish();
        if(data.second.second.type() == QVariant::Type::StringList)
        {
            int tmpPos, tmpVal;
            tmpPos = data.second.second.toStringList()[0].toInt();
            tmpVal = data.second.second.toStringList()[1].toInt();
            emit Data(qMakePair(tmpPos, tmpVal));
        }
    }
    else if(data.first == "POL")
    {
        //emit switchingSucceed(data.second.second.value<Polarizer>());???Has to be updated???
    }
}

void TXcontroller::gotNewConnection(QVariant data)
{
    emit gotConnection();
}

void TXcontroller::gotDataFile(QPair<QString, QPair<QString, QVariant> > data)
{
    //Has to be implemented
}

void TXcontroller::ClientStatus(bool status)
{
    emit this->MainClientStat(status);
}

void TXcontroller::DataClientStatus(bool status)
{
    emit this->DataClientStat(status);
}
