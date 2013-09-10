# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux-x86
TARGET = qt_tradingclient_1
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui network opengl sql svg xml webkit
SOURCES += GUI/ReqMktDataGUI.cpp DataAccessLayer/MessageProcessor.cpp Statistics/TimeSeriesStatistics.cpp TradingStrategies/Cointegration.cpp main.cpp TradingStrategies/CointegrationImpl.cpp DataAccessLayer/MarketData.cpp GUI/MainWindow.cpp IBAdditions/IB_events.cpp TradingStrategies/TradingStrategy.cpp DataAccessLayer/Repository.cpp DataAccessLayer/RepositoryOnStack.cpp GUI/qcustomplot.cpp DataAccessLayer/PosixClient.cpp GUI/ReqMktDepthGUI.cpp Statistics/Statistics.cpp GUI/CointegrationGUI.cpp TradingStrategies/TradingStrategyImpl.cpp DataAccessLayer/GUIMarketData.cpp DataModelLayer/TickerDisplayModel.cpp GUI/SubscribeToDataGUI.cpp
HEADERS += IBAdditions/IB_events.h GUI/ui_MainWindow.h GUI/ui_Cointegration.h GUI/GUIMarketData.h DataAccessLayer/MessageProcessor.h GUI/CointegrationGUI.h GUI/ui_SubscribeToDataGUI.h DataModelLayer/TickerDisplayModel.h GUI/ui_ReqMktDataGUI.h DataAccessLayer/RepositoryOnStack.h Statistics/Statistics.h DataAccessLayer/ProcessMsgClass.h TradingStrategies/Cointegration.h GUI/ReqMktDepthGUI.h DataAccessLayer/MarketData.h ui_SubscribeToDataGUI.h Statistics/TimeSeriesStatistics.h GUI/ui_CointegrationGUI.h GUI/SubscribeToDataGUI.h GUI/ui_reqMktDepthGUI.h TradingStrategies/TradingStrategyImpl.h DataAccessLayer/PosixClient.h GUI/MainWindow.h DataAccessLayer/Repository.h GUI/ReqMktDataGUI.h TradingStrategies/TradingStrategy.h TradingStrategies/CointegrationImpl.h GUI/qcustomplot.h DataAccessLayer/globals.h
FORMS += GUI/ReqMktDepthGUI.ui GUI/CointegrationGUI.ui GUI/MainWindow.ui GUI/ReqMktDataGUI.ui GUI/SubscribeToDataGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux-x86
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += DEBUG HAVE_CONFIG_H IB_USE_STD_STRING _GNU_SOURCE 
INCLUDEPATH += /opt/Qt5.0.1/5.0.1/gcc_64/include ../twsapi 
LIBS += -ltwsapi -lQuantLib -lpthread-2.15 -lQt5PrintSupport  
