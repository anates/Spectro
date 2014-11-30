#include "dpc.h"

int Read_DPC(void)
{
    int Inhibit = 0x0, Enable = 0x4;
    unsigned char Flag = 0, Highbytes = 0, Lowbytes = 0;

    unsigned char Digit[4] = {0, 0, 0, 0};

    //Port[Flagport] : = Enable;//Flagport muss angepasst werden

    //{ Waiting till bit 7 is on high : }
    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) > 0);
    //{ Waiting till bit 7 is low again}
    //REPEAT Flag : = PORT[Flagport] UNTIL((Flag AND $80) = 0);

    //Port[Flagport] : = Inhibit;

    //{ Read data port }
    //Highbytes: = Port[Highport]; Ports und Auslesevorgang muss angepasst werden
    //Lowbytes: = Port[Lowport];

    //Port[Flagport] : = Enable;

    //{ convert it into a decimal number }
    //Hier muss ebenfalls noch angepasst werden
    Digit[3] = Highbytes / 0x10;
    Digit[2] = Highbytes % 0x10;
    Digit[1] = Lowbytes / 0x10;
    Digit[0] = Lowbytes % 0x10;

    //{ Hardcoding to repair a particular data transfer error : }
    if(Digit[3] > 7)
        Digit[3] = 0;

    return Digit[3] * 1000 + Digit[2] * 100 + Digit[1] * 10 + Digit[0];
}

DPC_Master::DPC_Master()
{
    DPC::runThread = true;
    /*DPC::A[0] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_32, BlackLib::input));
    /*DPC::A[1] = new B*/A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_33, BlackLib::input));
    /*DPC::A[2] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_34, BlackLib::input));
    /*DPC::A[3] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_35, BlackLib::input));
    /*DPC::A[4] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_36, BlackLib::input));
    /*DPC::A[5] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_37, BlackLib::input));
    /*DPC::A[6] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_38, BlackLib::input));
    /*DPC::A[7] = new */A.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_39, BlackLib::input));

    /*DPC::B[0] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_65, BlackLib::input));
    /*DPC::B[1] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_66, BlackLib::input));
    /*DPC::B[2] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_67, BlackLib::input));
    /*DPC::B[3] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_68, BlackLib::input));
    /*DPC::B[4] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_69, BlackLib::input));
    /*DPC::B[5] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_72, BlackLib::input));
    /*DPC::B[6] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_73, BlackLib::input));
    /*DPC::B[7] = new */B.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_74, BlackLib::input));

    /*DPC::C[0] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_2, BlackLib::input));
    /*DPC::C[1] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_3, BlackLib::input));
    /*DPC::C[2] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_4, BlackLib::input));
    /*DPC::C[3] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_5, BlackLib::input));
    /*DPC::C[4] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_10, BlackLib::input));
    /*DPC::C[5] = new */C.emplace_back(new BlackLib::BlackGPIO(BlackLib::GPIO_11, BlackLib::input));
//    //DPC::C[6] = new BlackLib::BlackGPIO(BlackLib::I2C_0, BlackLib::input);
//    //DPC::C[7] = new BlackLib::BlackGPIO(BlackLib::I2C_1, BlackLib::input);
//    //qDebug() << "DPC: " << thread() << currentThread();
}

DPC_Master::~DPC_Master()
{
    qDebug() << "Clearing up DPC!";
    //delete[] *(DPC::A);
    //qDebug() << "Cleared A";
    //delete[] *DPC::B;
    //delete[] *DPC::C;
    //qDebug() << "Finished clearing up DPC!";
}

void DPC_Master::cancelThread(void)
{
    DPC::runThread = false;
}
