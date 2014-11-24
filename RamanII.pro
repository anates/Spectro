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
    TPDECL.cpp \
    Monokrom.cpp \
    Maaling.cpp \
    Globale.cpp \
    COM_PROC.cpp \
    Analyse.cpp \
    add_functions.cpp \
    Raman_old.cpp \
    Raman.cpp \
    ../tcp_client_test/client.cpp \
    ../tcp_client_test/server.cpp \
    ../remoteController/tx_thread.cpp

HEADERS  += mainwindow.h \
    Raman.h \
    Monokrom.h \
    Maaling.h \
    Globale.h \
    COM_PROC.h \
    add_functions.h \
    ../tcp_client_test/client.h \
    ../tcp_client_test/server.h \
    ../remoteController/tx_thread.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/qwt-6.1.1/include
#Has to be changed back to -L/usr/lib/ afterwards
LIBS += -L/usr/local/qwt-6.1.1/lib/ -lqwt

QMAKE_CXXFLAGS += -std=c++11 -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
