/*
 * File:   GUI.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#include "reqMktDataGUI.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <typeinfo>
    
reqMktDataGUI::reqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr):client(client_ptr){
    widget.setupUi(this);
    QObject::connect(widget.requestButton, SIGNAL(clicked()), this, SLOT(requestClicked()));
    QObject::connect(widget.cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    this->setAttribute(Qt::WA_DeleteOnClose);
}

reqMktDataGUI::~reqMktDataGUI() {
    printf( "I am dead!\n");
}

void reqMktDataGUI::myTickPriceUpdate(int tickerId, rec_ptr record_ptr){
    try{
        //const IB::TickPriceRecord* tickPriceRecord = dynamic_cast<const IB::TickPriceRecord*>(record.get());
        tickPriceRec_ptr tickPriceRecord_ptr(boost::dynamic_pointer_cast<IB::TickPriceRecord>(record_ptr));
        printf( "myTickPriceUpdate! for tickerId: %d, with price: %d\n",tickerId,tickPriceRecord_ptr->price_);
        QString qs=QString("myTickPriceUpdate! for tickerId: %1, price: %2").arg(tickerId).arg(tickPriceRecord_ptr->price_);
        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        printf( "myTickPriceUpdate: badCast for tickerId: %d\n",tickerId);
    }
}
void reqMktDataGUI::myTickSizeUpdate(int tickerId, rec_ptr record_ptr){
    try{
        tickSizeRec_ptr tickSizeRecord_ptr(boost::dynamic_pointer_cast<IB::TickSizeRecord>(record_ptr));
        printf( "myTickSizeUpdate! for tickerId: %d, with size: %d\n",tickerId,tickSizeRecord_ptr->size_);
        QString qs=QString("myTickSizeUpdate! for tickerId: %1, size: %2").arg(tickerId).arg(tickSizeRecord_ptr->size_);
        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        printf( "myTickSizeUpdate: badCast for tickerId: %d\n",tickerId);
    }
}
void reqMktDataGUI::myTickStringUpdate(int tickerId, rec_ptr record_ptr){

}
//public slots
void reqMktDataGUI::requestClicked(){
    IB::Contract contract;
    	contract.symbol = widget.lineEdit_Symbol->text().toStdString();
	contract.secType = widget.lineEdit_Type->text().toStdString();
	contract.exchange = widget.lineEdit_Exchange->text().toStdString();
	contract.currency = widget.lineEdit_Currency->text().toStdString();
        
    IB::Event processedEvent = IB::TickPrice;
    //availableEventList.push_back(IB::TickSize);
    //availableEventList.push_back(IB::TickString);
    boost::shared_ptr<MarketData> md(new MarketData(processedEvent,widget.lineEdit_Id->text().toInt(),contract));
    tickPriceObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(md,IB::TickPrice,boost::bind(&reqMktDataGUI::myTickPriceUpdate,this,_1,_2))));
//    observers.push_back(boost::shared_ptr<MarketDataObserver>(
//            new MarketDataObserver(md,IB::TickSize,boost::bind(&reqMktDataGUI::myTickSizeUpdate,this,_1,_2))));    
    client->marketDataFeedInsert(md);
    
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
