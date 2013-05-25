/*
 * File:   GUI.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#include "reqMktDataGUI.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
    
reqMktDataGUI::reqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr):client(client_ptr){
    widget.setupUi(this);
    QObject::connect(widget.requestButton, SIGNAL(clicked()), this, SLOT(requestClicked()));
    QObject::connect(widget.cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    this->setAttribute(Qt::WA_DeleteOnClose);
}

reqMktDataGUI::~reqMktDataGUI() {
    printf( "I am dead!\n");
}

//public slots
void reqMktDataGUI::requestClicked(){
    //client.connect(host,port,clientId);
    //QMessageBox::information(this,"Button clicked!\n", "Warning");
}  

void reqMktDataGUI::cancelClicked(){
    this->~reqMktDataGUI();
} 
