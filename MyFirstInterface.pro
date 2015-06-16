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
    filename.cpp

HEADERS  += mainwindow.h \
    testselectionwidget.h \
    nameandsite.h \
    basetest.h \
    filename.h

FORMS    += mainwindow.ui \
    testselectionwidget.ui \
    nameandsite.ui \
    filename.ui
