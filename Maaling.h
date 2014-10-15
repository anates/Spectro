//#include "Globale.h"
#include <QThread>

//int Read_DPC(void);

class ReadDPC: public QThread
{
public:
    void run();
signals:
    void currentCount(int counts);
};
