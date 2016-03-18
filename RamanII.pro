#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T11:26:23
#
#-------------------------------------------------

QT       += core gui network testlib serialport widgets

TARGET = RamanII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    add_functions.cpp \
    client.cpp \
    server.cpp \
    tx_thread.cpp \
    #BlackLib.cpp \
    #BlackCore.cpp \
    #BlackGPIO.cpp \
    scandata.cpp \
    logfile.cpp \
    scanparams.cpp \
    scan.cpp \
    scanlist.cpp \
    spectrometer.cpp \
    stepper_control.cpp \
    dpc.cpp \
    scanner.cpp \
    polarizer_control.cpp \
    txcontroller.cpp \
    qsshsocket.cpp \
    serial_controller.cpp \
    logfiledialog.cpp

HEADERS  += mainwindow.h \
    add_functions.h \
    client.h \
    server.h \
    tx_thread.h \
    #BlackCore.h \
    #BlackDef.h \
    #BlackErr.h \
    #BlackGPIO.h \
    #BlackLib.h \
    scandata.h \
    logfile.h \
    scanparams.h \
    scan.h \
    scanlist.h \
    spectrometer.h \
    stepper_control.h \
    dpc.h \
    scanner.h \
    polarizer_control.h \
    txcontroller.h \
    qsshsocket.h \
    serial_controller.h \
    logfiledialog.h

FORMS    += mainwindow.ui \
    logfiledialog.ui

INCLUDEPATH += /usr/local/qwt-6.1.3/include
#Has to be changed back to -L/usr/lib/ afterwards
LIBS += -L/usr/local/qwt-6.1.3/lib/ -lqwt -lssh

QMAKE_CXXFLAGS += -std=c++11 -std=gnu++0x -O3 -fopenmp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS    = RAMANII_de.ts \
                   RAMANII_en.ts \
                   RAMANII_no.ts

CODECFORTR      = ISO-8859-5
