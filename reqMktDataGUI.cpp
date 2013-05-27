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

void reqMktDataGUI::myUpdate(int tickerId, IB::Record record){
    printf( "myUpdate! for tickerId: %d\n",tickerId);
}
//public slots
void reqMktDataGUI::requestClicked(){
    IB::Contract contract;
    	contract.symbol = widget.lineEdit_Symbol->text().toStdString();
	contract.secType = widget.lineEdit_Type->text().toStdString();
	contract.exchange = widget.lineEdit_Exchange->text().toStdString();
	contract.currency = widget.lineEdit_Currency->text().toStdString();
        
    boost::shared_ptr<MarketData> md(new MarketData(contract,widget.lineEdit_Id->text().toInt()));
    observers.push_back(boost::shared_ptr<MarketDataObserver>(new MarketDataObserver(md,boost::bind(&reqMktDataGUI::myUpdate,this,_1,_2))));
    client->dataRepositoryAdd(md);
    
    client->reqMktData(widget.lineEdit_Symbol->text().toStdString(), widget.lineEdit_Type->text().toStdString(),
        widget.lineEdit_Exchange->text().toStdString(), widget.lineEdit_Currency->text().toStdString(), 
            widget.lineEdit_Id->text().toInt(), widget.lineEdit_genericTickTags->text().toStdString(), 
            widget.checkBox_Snapshot->isChecked());
    int i=0;
    while(i<1000000){
        client->processMessages();
        i++;
    }
}  

void reqMktDataGUI::cancelClicked(){
    this->~reqMktDataGUI();
} 
