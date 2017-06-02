#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T20:49:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Widget
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    camera.cpp \
    errorhandler.cpp \
    finitestatemachine.cpp

HEADERS  += mainwindow.h \
    settings.h \
    camera.h \
    errorhandler.h \
    finitestatemachine.h

FORMS    += mainwindow.ui

#FLYCAPTURE
INCLUDEPATH += -I../../include -I/usr/include/flycapture
LIBS      = -L../../lib -lflycapture

#OPENCV
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
PKGCONFIG += opencv
CONFIG += link_pkgconfig

