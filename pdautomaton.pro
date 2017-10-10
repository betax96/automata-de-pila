#-------------------------------------------------
#
# Project created by QtCreator 2017-09-24T12:18:01
#
#-------------------------------------------------

QT       += core gui
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = automata-pila
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    estado.cpp \
    transicion.cpp \
    automatapila.cpp \
    graphsvg.cpp

HEADERS  += mainwindow.h \
    estado.h \
    transicion.h \
    automatapila.h \
    graphsvg.h

FORMS    += mainwindow.ui

INCLUDEPATH += ./ogdf

LIBS += -L$$PWD/./ -lOGDF
PRE_TARGETDEPS += $$PWD/./libOGDF.a
