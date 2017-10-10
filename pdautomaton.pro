#-------------------------------------------------
#
# Project created by QtCreator 2017-09-24T12:18:01
#
#-------------------------------------------------

QT       += core gui
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdautomaton
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphsvg.cpp \
    state.cpp \
    transition.cpp \
    pdautomaton.cpp

HEADERS  += mainwindow.h \
    graphsvg.h \
    state.h \
    transition.h \
    pdautomaton.h

FORMS    += mainwindow.ui

INCLUDEPATH += ./ogdf

LIBS += -L$$PWD/./ -lOGDF
PRE_TARGETDEPS += $$PWD/./libOGDF.a

LIBS += -L$$PWD/./ -lCOIN
PRE_TARGETDEPS += $$PWD/./libCOIN.a
