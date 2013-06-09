#-------------------------------------------------
#
# Project created by QtCreator 2013-06-09T16:51:21
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = MediaServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    coreserver.cpp \
    func.cpp

HEADERS += \
    coreserver.h \
    func.h
