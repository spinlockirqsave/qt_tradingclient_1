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
#include <DataAccessLayer/PosixClient.h>
#include <GUI/ReqMktDataGUI.h>
#include <GUI/ReqMktDepthGUI.h>
#include <DataAccessLayer/Repository.h>

class cf16tradingclient_1 : public QMainWindow {
    Q_OBJECT
public:
    cf16tradingclient_1(boost::shared_ptr<IB::PosixClient>, Repository&);
    virtual ~cf16tradingclient_1();
    
public slots:
    void connectClicked();
    void disconnectClicked();
    void actionReqMktDataClicked();
    void actionReqMktDepthClicked();
    
private:
    Ui::cf16tradingclient_1 widget;
    boost::shared_ptr<IB::PosixClient> client_;
    const char* host_;
    unsigned int port_;
    int clientId_;
    boost::shared_ptr<ReqMktDataGUI> reqMDGUI_ptr_;
    ReqMktDataGUI* ptr_;
    ReqMktDepthGUI* ptr2_;
    
    Repository& mktDataRepository_;
};


#endif	/* MAINWINDOW_H */

