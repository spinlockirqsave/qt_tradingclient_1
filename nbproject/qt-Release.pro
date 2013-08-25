# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU_4.7-Linux-x86
TARGET = qt_tradingclient_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui
SOURCES += GUI/ReqMktDataGUI.cpp DataAccessLayer/IB_events.cpp DataAccessLayer/MessageProcessor.cpp Statistics/TimeSeriesStatistics.cpp TradingStrategies/Cointegration.cpp main.cpp DataAccessLayer/MarketData.cpp GUI/MainWindow.cpp TradingStrategies/TradingStrategy.cpp DataAccessLayer/Repository.cpp DataAccessLayer/RepositoryOnStack.cpp GUI/qcustomplot.cpp GUI/ReqMktDepthGUI.cpp DataAccessLayer/PosixClient.cpp Statistics/Statistics.cpp GUI/CointegrationGUI.cpp DataAccessLayer/GUIMarketData.cpp
HEADERS += IBAdditions/IB_events.h GUI/ui_MainWindow.h GUI/ui_Cointegration.h GUI/GUIMarketData.h DataAccessLayer/MessageProcessor.h GUI/CointegrationGUI.h GUI/ui_ReqMktDataGUI.h DataAccessLayer/RepositoryOnStack.h Statistics/Statistics.h DataAccessLayer/ProcessMsgClass.h TradingStrategies/Cointegration.h GUI/ReqMktDepthGUI.h DataAccessLayer/MarketData.h Statistics/TimeSeriesStatistics.h GUI/ui_CointegrationGUI.h GUI/ui_reqMktDepthGUI.h DataAccessLayer/PosixClient.h GUI/MainWindow.h DataAccessLayer/Repository.h GUI/ReqMktDataGUI.h TradingStrategies/TradingStrategy.h GUI/qcustomplot.h DataAccessLayer/globals.h
FORMS += GUI/ReqMktDepthGUI.ui GUI/CointegrationGUI.ui GUI/MainWindow.ui GUI/ReqMktDataGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU_4.7-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += HAVE_CONFIG_H IB_USE_STD_STRING _GNU_SOURCE 
INCLUDEPATH += 
LIBS += -lQuantLib -ltwsapi  
