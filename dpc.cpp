#include "dpc.h"

//DPC_Worker-functions
DPC_Worker::DPC_Worker(counterData *data)
{
    Data = data;
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_32, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_33, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_34, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_35, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_36, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_37, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_38, BlackLib::input));
    A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_39, BlackLib::input));

    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_65, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_66, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_67, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_68, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_69, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_72, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_73, BlackLib::input));
    B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_74, BlackLib::input));

    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_2, BlackLib::input));
    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_3, BlackLib::input));
    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_4, BlackLib::input));
    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_5, BlackLib::input));
    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_10, BlackLib::input));
    C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_11, BlackLib::input));
//    //DPC::C[6] = new BlackLib::BlackGPIO(BlackLib::I2C_0, BlackLib::input);
//    //DPC::C[7] = new BlackLib::BlackGPIO(BlackLib::I2C_1, BlackLib::input);
    toDo = false;
    stopAqu = false;
}

DPC_Worker::~DPC_Worker()
{
}

void DPC_Worker::stopAquisition(void)
{
    qDebug() << "Aquisition should stop now!";
    stopAqu = true;
}

void DPC_Worker::aquireCounts(void)
{
    int counts = 42;
    while(stopAqu == false)
    {
        usleep(50000);//Hier muss noch die Auswertung eingebaut werden, und die genauen Pins muessen nachgesehen werden

        Data->mutex.lock();
        Data->counts += counts;
        Data->number++;
        Data->WaitCond.wakeAll();
        Data->mutex.unlock();
        emit currentCounts(counts);
    }
    qDebug() << "Aquisition stopped!";
}

//int Read_DPC(void)
//{
//    int Inhibit = 0x0, Enable = 0x4;
//    unsigned char Flag = 0, Highbytes = 0, Lowbytes = 0;

//    unsigned char Digit[4] = {0, 0, 0, 0};

//    //Port[Flagport] : = Enable;//Flagport muss angepasst werden

//    //{ Waiting till bit 7 is on high : }
//    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) > 0);
//    //{ Waiting till bit 7 is low again}
//    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) = 0);

//    //Port[Flagport] : = Inhibit;

//    //{ Read data port }
//    //Highbytes: = Port[Highport]; Ports und Auslesevorgang muss angepasst werden
//    //Lowbytes: = Port[Lowport];

//    //Port[Flagport] : = Enable;

//    //{ convert it into a decimal number }
//    //Hier muss ebenfalls noch angepasst werden
//    Digit[3] = Highbytes / 0x10;
//    Digit[2] = Highbytes % 0x10;
//    Digit[1] = Lowbytes / 0x10;
//    Digit[0] = Lowbytes % 0x10;

//    //{ Hardcoding to repair a particular data transfer error : }
//    if(Digit[3] > 7)
//        Digit[3] = 0;

//    return Digit[3] * 1000 + Digit[2] * 100 + Digit[1] * 10 + Digit[0];
//}

//DPC_Master-functions

DPC_Master::DPC_Master(counterData *data)
{
    DPC_Worker *newDPC = new DPC_Worker(data);
    newDPC->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, newDPC, &DPC_Worker::deleteLater);
    connect(this, &DPC_Master::startAquisition, newDPC, &DPC_Worker::aquireCounts);
    connect(this, &DPC_Master::stopAquisition, newDPC, &DPC_Worker::stopAquisition);
    connect(newDPC, &DPC_Worker::currentCounts, this, &DPC_Master::currentCounts);
    workerThread.start();
    emit startAquisition();
}

DPC_Master::~DPC_Master()
{
    emit stopAquisition();
    qDebug() << "Cleaning up DPC";
    workerThread.quit();
    workerThread.wait();
    qDebug() << "DPC cleaned!";
}

void DPC_Master::currentCounts(int counts)
{
    emit currentCount(counts);
}
