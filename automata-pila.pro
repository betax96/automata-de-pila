#-------------------------------------------------
#
# Project created by QtCreator 2017-09-24T12:18:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = automata-pila
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    estado.cpp \
    transicion.cpp

HEADERS  += mainwindow.h \
    estado.h \
    transicion.h

FORMS    += mainwindow.ui
