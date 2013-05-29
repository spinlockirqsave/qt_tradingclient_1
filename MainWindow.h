/* 
 * File:   MainWindow.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 24, 2013, 12:45 AM
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H


#include "ui_MainWindow.h"
#include <boost/shared_ptr.hpp>
#include "PosixClient.h"
#include "reqMktDataGUI.h"

class cf16tradingclient_1 : public QMainWindow {
    Q_OBJECT
public:
    cf16tradingclient_1(boost::shared_ptr<IB::PosixClient> client_ptr);
    virtual ~cf16tradingclient_1();
public slots:
    void connectClicked();
    void disconnectClicked();
    void actionReqMktDataClicked();
private:
    Ui::cf16tradingclient_1 widget;
    boost::shared_ptr<IB::PosixClient> client;
    const char* host;
    unsigned int port;
    int clientId;
    boost::shared_ptr<reqMktDataGUI> reqMDGUI_ptr;
};


#endif	/* MAINWINDOW_H */

