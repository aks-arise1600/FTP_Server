#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T11:12:29
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = ../lib/QFtpServerLib
TEMPLATE = lib

DEFINES += QFTPSERVERLIB_LIBRARY

CONFIG += static

SOURCES += \
    dataconnection.cpp \
    ftpcommand.cpp \
    ftpcontrolconnection.cpp \
    ftplistcommand.cpp \
    ftpretrcommand.cpp \
    ftpserver.cpp \
    ftpstorcommand.cpp \
    sslserver.cpp

HEADERS +=\
        qftpserverlib_global.h \
    dataconnection.h \
    ftpcommand.h \
    ftpcontrolconnection.h \
    ftplistcommand.h \
    ftpretrcommand.h \
    ftpserver.h \
    ftpstorcommand.h \
    sslserver.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    certificates.qrc
