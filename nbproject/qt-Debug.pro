# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = qt_tradingclient_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui opengl
SOURCES += GUI/ReqMktDataGUI.cpp DataAccessLayer/MessageProcessor.cpp main.cpp DataAccessLayer/MarketData.cpp GUI/MainWindow.cpp TradingStrategies/TradingStrategy.cpp GUI/ReqMktDepthGUI.cpp DataAccessLayer/PosixClient.cpp DataAccessLayer/GUIMarketData.cpp
HEADERS += IBAdditions/IB_events.h GUI/ui_MainWindow.h GUI/GUIMarketData.h DataAccessLayer/MessageProcessor.h GUI/ui_ReqMktDataGUI.h DataAccessLayer/ProcessMsgClass.h GUI/ReqMktDepthGUI.h DataAccessLayer/MarketData.h GUI/ui_reqMktDepthGUI.h DataAccessLayer/PosixClient.h GUI/MainWindow.h GUI/ReqMktDataGUI.h TradingStrategies/TradingStrategy.h
FORMS += GUI/ReqMktDepthGUI.ui GUI/MainWindow.ui GUI/ReqMktDataGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += DEBUG HAVE_CONFIG_H IB_USE_STD_STRING _GNU_SOURCE 
INCLUDEPATH += ../twsapi/PosixSocketClient/src ../twsapi/Shared ../twsapi ../twsapi/PosixSocketClient /usr/include/boost /opt/Qt5.0.1/5.0.1/gcc_64/include 
LIBS += -ltwsapi -lQuantLib -lpthread-2.15  
