#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T19:50:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = data-logger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bcellmodel.cpp \
    bcelltablemodel.cpp \
    bworker.cpp \
    bcell.cpp \
    bpartialproxymodel.cpp \
    bsortfilterproxymodel.cpp

HEADERS  += mainwindow.h \
    bcellmodel.h \
    bcelltablemodel.h \
    bworker.h \
    bcell.h \
    bpartialproxymodel.h \
    bsortfilterproxymodel.h

FORMS    += mainwindow.ui

target.path = /home/pi
INSTALLS += target
