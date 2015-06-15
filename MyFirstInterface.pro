#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T10:20:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFirstInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testselectionwidget.cpp \
    nameandsite.cpp \
    basetest.cpp \
    sefa.cpp

HEADERS  += mainwindow.h \
    testselectionwidget.h \
    nameandsite.h \
    basetest.h \
    sefa.h

FORMS    += mainwindow.ui \
    testselectionwidget.ui \
    nameandsite.ui
