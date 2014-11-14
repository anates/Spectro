#-------------------------------------------------
#
# Project created by QtCreator 2014-10-03T11:26:23
#
#-------------------------------------------------

QT       += core gui

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
    Raman.cpp

HEADERS  += mainwindow.h \
    Raman.h \
    Monokrom.h \
    Maaling.h \
    Globale.h \
    COM_PROC.h \
    add_functions.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/qwt
#Has to be changed back to -L/usr/lib/ afterwards
LIBS += -L/home/roland/Downloads/qwt-6.1.1/lib/ -lqwt

QMAKE_CXXFLAGS += -std=c++11 -std=gnu++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
