# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU_4.7-Linux-x86
TARGET = qt_tradingclient_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui opengl
SOURCES += MainWindow.cpp main.cpp PosixClient.cpp GUI.cpp
HEADERS += GUI.h PosixClient.h MainWindow.h ui_MainWindow.h ui_GUI.h
FORMS += GUI.ui MainWindow.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU_4.7-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += DEBUG HAVE_CONFIG_H IB_USE_STD_STRING _GNU_SOURCE 
INCLUDEPATH += ../twsapi/PosixSocketClient/src ../twsapi/Shared ../twsapi ../twsapi/PosixSocketClient 
LIBS += -ltwsapi  
