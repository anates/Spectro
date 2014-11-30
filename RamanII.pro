#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T11:26:23
#
#-------------------------------------------------

QT       += core gui network testlib

TARGET = RamanII
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Globale.cpp \
    COM_PROC.cpp \
    Analyse.cpp \
    add_functions.cpp \
    ../tcp_client_test/client.cpp \
    ../tcp_client_test/server.cpp \
    ../remoteController/tx_thread.cpp \
    ../BlackLib/v1_0/BlackLib.cpp \
    ../BlackLib/v2_0/BlackCore.cpp \
    ../BlackLib/v2_0/BlackGPIO.cpp \
    scandata.cpp \
    logfile.cpp \
    scanparams.cpp \
    scan.cpp \
    scanlist.cpp \
    spectrometer.cpp \
    stepper_control.cpp \
    dpc.cpp \
    scanner.cpp \
    polarizer_control.cpp

HEADERS  += mainwindow.h \
    Globale.h \
    COM_PROC.h \
    add_functions.h \
    ../tcp_client_test/client.h \
    ../tcp_client_test/server.h \
    ../remoteController/tx_thread.h \
    ../BlackLib/v2_0/BlackCore.h \
    ../BlackLib/v2_0/BlackDef.h \
    ../BlackLib/v2_0/BlackErr.h \
    ../BlackLib/v2_0/BlackGPIO.h \
    ../BlackLib/v2_0/BlackLib.h \
    scandata.h \
    logfile.h \
    scanparams.h \
    scan.h \
    scanlist.h \
    spectrometer.h \
    stepper_control.h \
    dpc.h \
    scanner.h \
    polarizer_control.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/qwt-6.1.1/include
#Has to be changed back to -L/usr/lib/ afterwards
LIBS += -L/usr/local/qwt-6.1.1/lib/ -lqwt

QMAKE_CXXFLAGS += -std=c++11 -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
