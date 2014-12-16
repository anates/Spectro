#include "txcontroller.h"

TXcontroller::TXcontroller(QString ipAddr, quint32 port, int MonoPos)
{
    this->MonoPos = MonoPos;
    this->port = port;
    this->targetIP = ipAddr;
    MainServer = new Server(ipAddr, port + 1, "MAIN");
    mainClient = new TX_master(ipAddr, port, "MAIN");
    fileClient = new TX_master(ipAddr, port + 2, "FILE");

    connect(this, &TXcontroller::TXdata, MainServer, &Server::sendData);
    connect(this, &TXcontroller::connectMain, mainClient, &TX_master::connectTX);
    connect(this, &TXcontroller::connectFile, fileClient, &TX_master::connectTX);
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
    emit TXdata(qMakePair(QString("POL"), QVariant(pol)));
}

void TXcontroller::moveToTarget(int steps, bool dir)
{
    emit TXdata(qMakePair(QString("STP"), QVariant(steps * (dir?1:-1))));
}

void TXcontroller::runScan(int start, int stop, int accuracy)
{
    //Muss noch entwickelt werden
}

void TXcontroller::gotDataMain(QPair<QString, QVariant> data)
{
    if(data.first == "STP")
    {
        if(data.second.toInt() == 1)
            emit stepperMoving();
        else if(data.second.toInt() > 1)
            emit currentPosition(fabs(data.second.toInt()), data.second.toInt() >= 0);
    }
    else if(data.first == "DPC")
    {
        emit DPCCounts(data.second.toInt());
    }
    else if(data.first == "SCN")
    {
        if(data.second.type() == QVariant::Type::Double)
        {
            emit ScanPos(data.second.toDouble());
        }
        if(data.second.type() == QVariant::Type::Int)
            emit scanFinish();
        if(data.second.type() == QVariant::Type::StringList)
        {
            int tmpPos, tmpVal;
            tmpPos = data.second.toStringList()[0].toInt();
            tmpVal = data.second.toStringList()[1].toInt();
            emit Data(qMakePair(tmpPos, tmpVal));
        }
    }
    else if(data.first == "POL")
    {
        emit switchingSucceed(data.second.value<Polarizer>());
    }
}

void TXcontroller::gotNewConnection(QVariant data)
{
    emit gotConnection();
}

void TXcontroller::gotDataFile(QPair<QString, QVariant> data)
{
    //Has to be implemented
}
