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
    Raman.cpp \
    Monokrom.cpp \
    Maaling.cpp \
    Help.cpp \
    Globale.cpp \
    COM_PROC.cpp \
    Analyse.cpp

HEADERS  += mainwindow.h \
    TPDECL.h \
    Raman.h \
    Monokrom.h \
    Maaling.h \
    Help.h \
    Globale.h \
    COM_PROC.h \
    Analyse.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/qwt
LIBS += -L/usr/lib/ -lqwt
