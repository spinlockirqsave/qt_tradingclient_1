/* 
 * File:   MainWindow.cpp
 * Author: Piotr Gregor  peter cf16 eu
 *
 * Created on May 24, 2013, 12:45 AM
 */

#include "MainWindow.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include "ReqMktDataGUI.h"
    
cf16tradingclient_1::cf16tradingclient_1(boost::shared_ptr<IB::PosixClient> client_ptr,
        Repository& mktDataRepository): 
        host_(""),
        port_(7496),
        clientId_(1),
        client_(client_ptr),
        mktDataRepository_(mktDataRepository){
    widget.setupUi(this);
        QObject::connect(widget.connectButton, SIGNAL(clicked()), this, SLOT(connectClicked()));
        QObject::connect(widget.disconnectButton, SIGNAL(clicked()), this, SLOT(disconnectClicked()));
        QObject::connect(widget.actionReqMktData, SIGNAL(triggered()), this, SLOT(actionReqMktDataClicked()));
        QObject::connect(widget.actionReqMktDepth, SIGNAL(triggered()), this, SLOT(actionReqMktDepthClicked()));
        QObject::connect(widget.actionCointegration, SIGNAL(triggered()), this, SLOT(actionCointegrationClicked()));
}

cf16tradingclient_1::~cf16tradingclient_1() {
    if (client_->isConnected()) {
        endProcessMessages();
        client_->disconnect();
        if (!client_->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("not connected"));
        }
    }
}

//public slots
void cf16tradingclient_1::connectClicked() {
    if (!client_->isConnected()) {
        client_->connect(host_, port_, clientId_);
        if (client_->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("connected"));
            processMessages();
        }
    }
        //processMessages3();
    
}

void cf16tradingclient_1::disconnectClicked() {
    if (client_->isConnected()) {
        endProcessMessages();
        client_->disconnect();
        if (!client_->isConnected()) {
            widget.label_6_connected->setText(QStringLiteral("not connected"));
        }
    }
}

void cf16tradingclient_1::actionReqMktDataClicked(){
    //reqMDGUI_ptr=boost::shared_ptr<reqMktDataGUI>(new reqMktDataGUI(client));
    //reqMDGUI_ptr->show();
    //ptr_=new ReqMktDataGUI(client_);
    //ptr_->show();
    reqMktDataGUI_ptr_.push_back(boost::shared_ptr<ReqMktDataGUI>(new ReqMktDataGUI(client_)));
    reqMktDataGUI_ptr_.back()->show();
}

void cf16tradingclient_1::actionReqMktDepthClicked(){
    //ptr2_=new ReqMktDepthGUI(client_);
    //ptr2_->show();
    reqMktDepthGUI_ptr_.push_back(boost::shared_ptr<ReqMktDepthGUI>(new ReqMktDepthGUI(client_)));
    reqMktDepthGUI_ptr_.back()->show();
}

void cf16tradingclient_1::actionCointegrationClicked(){
    ptr3_ = new CointegrationGUI();
    ptr3_->show();
}
