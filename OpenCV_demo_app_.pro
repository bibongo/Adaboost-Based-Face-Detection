#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T11:23:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = OpenCV_demo_app_
TEMPLATE = app

###---Dependency of OpenCV is included in here---###
unix {
QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig
PKGCONFIG += opencv
}


SOURCES += main.cpp\
        mainwindow.cpp \
    image_processing.cpp

HEADERS  += mainwindow.h \
    image_processing.h

FORMS    += mainwindow.ui

RESOURCES += \
    Logo_.qrc

OTHER_FILES += \
    Images/ubuntu1.jpg \
    Images/ubuntu2.jpg \
    Images/logo.png
