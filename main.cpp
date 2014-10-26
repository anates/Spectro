#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Polarizer>();
    MainWindow w;
    w.show();
    
    return a.exec();
}
