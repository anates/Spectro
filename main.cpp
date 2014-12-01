#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Polarizer>();
    qRegisterMetaType<QPair<int, int> >();
    MainWindow w;
    w.show();
    
    return a.exec();
}
