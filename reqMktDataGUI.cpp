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
#include <ql/patterns/observable.hpp>
    
reqMktDataGUI::reqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr):client(client_ptr){
    widget.setupUi(this);
    QObject::connect(widget.requestButton, SIGNAL(clicked()), this, SLOT(requestClicked()));
    QObject::connect(widget.cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    QObject::connect(widget.guiRequestButton, SIGNAL(clicked()), this, SLOT(guiRequestClicked()));
    this->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(this,SIGNAL(newMktData(int,rec_ptr)),this,SLOT(displayData(int,rec_ptr)));
}

reqMktDataGUI::~reqMktDataGUI() {
   #ifdef DEBUG 
        printf( "I am dead!\n");
   #endif
}

void reqMktDataGUI::myTickPriceUpdate(int tickerId, rec_ptr record_ptr){
    try{
        //const IB::TickPriceRecord* tickPriceRecord = dynamic_cast<const IB::TickPriceRecord*>(record.get());
        tickPriceRec_ptr tickPriceRecord_ptr(boost::dynamic_pointer_cast<IB::TickPriceRecord>(record_ptr));
        #ifdef DEBUG 
           printf( "myTickPriceUpdate! Id: %d, price: %f, tickType: %d\n",tickerId,tickPriceRecord_ptr->price_,tickPriceRecord_ptr->tickType_);
        #endif
//        QString qs=QString("myTickPriceUpdate! Id: %1, price: %2, tickType: %3").arg(tickerId).arg(tickPriceRecord_ptr->price_).arg(tickPriceRecord_ptr->tickType_);
//        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
           printf( "myTickPriceUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}
void reqMktDataGUI::myTickSizeUpdate(int tickerId, rec_ptr record_ptr){
    try{
        tickSizeRec_ptr tickSizeRecord_ptr(boost::dynamic_pointer_cast<IB::TickSizeRecord>(record_ptr));
    #ifdef DEBUG 
        printf( "myTickSizeUpdate! Id: %d, size: %d, tickType: %d\n",tickerId,tickSizeRecord_ptr->size_,tickSizeRecord_ptr->tickType_);
    #endif
//        QString qs=QString("myTickSizeUpdate! Id: %1, size: %2, tickType: %3").arg(tickerId).arg(tickSizeRecord_ptr->size_).arg(tickSizeRecord_ptr->tickType_);
//        widget.textEdit_dataFeed->append(qs);
        //widget.textEdit_dataFeed->append("myTickSizeUpdate something...");
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
            printf( "myTickSizeUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}
void reqMktDataGUI::myTickStringUpdate(int tickerId, rec_ptr record_ptr){
        try{
        tickStringRec_ptr tickStringRecord_ptr(boost::dynamic_pointer_cast<IB::TickStringRecord>(record_ptr));
    #ifdef DEBUG 
        printf( "myTickStringUpdate! Id: %d, string: %s, tickType: %d\n",tickerId,tickStringRecord_ptr->string.c_str(),tickStringRecord_ptr->tickType_);
    #endif
//        QString qs=QString("myTickStringUpdate! Id: %1, string: ").arg(tickerId)+QString::fromStdString(tickStringRecord_ptr->string);
//        qs+=QString(" tickType: %1").arg(tickStringRecord_ptr->tickType_);
//        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
            printf( "myTickStringUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}

void reqMktDataGUI::myTickSizeGUIupdate(int tickerId, rec_ptr record_ptr){
    try{
        tickSizeRec_ptr tickSizeRecord_ptr(boost::dynamic_pointer_cast<IB::TickSizeRecord>(record_ptr));
    #ifdef DEBUG 
        printf( "myTickSizeGUIUpdate! Id: %d, size: %d, tickType: %d\n",tickerId,tickSizeRecord_ptr->size_,tickSizeRecord_ptr->tickType_);
    #endif
//        QString qs=QString("myTickSizeUpdate! Id: %1, size: %2, tickType: %3").arg(tickerId).arg(tickSizeRecord_ptr->size_).arg(tickSizeRecord_ptr->tickType_);
//        widget.textEdit_dataFeed->append(qs);
        //widget.textEdit_dataFeed->append("myTickSizeUpdate something...");
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
            printf( "myTickSizeGUIUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}
//public slots
void reqMktDataGUI::requestClicked(){
    
    IB::Contract contract;
    contract.symbol = widget.lineEdit_Symbol->text().toStdString();
    contract.secType = widget.lineEdit_Type->text().toStdString();
    contract.exchange = widget.lineEdit_Exchange->text().toStdString();
    contract.currency = widget.lineEdit_Currency->text().toStdString();
        
    
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickPriceMktData(new MarketData(IB::TickPrice,widget.lineEdit_Id->text().toInt(),contract));
    // create tickPrice event observer and push it into vector stored in this GUI form
    tickPriceObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickPriceMktData,IB::TickPrice,boost::bind(&reqMktDataGUI::myTickPriceUpdate,this,_1,_2))));
    // put this connection into marketDataFeed map, it will be stored in tickPriceMarketDataFeed
    client->marketDataFeedInsert(tickPriceMktData);
    
    
    // also register for tickSize updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickSizeMktData(new MarketData(IB::TickSize,widget.lineEdit_Id->text().toInt(),contract));    
    // create tickSize event observer and push it into vector stored in this GUI form
    tickSizeObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickSizeMktData,IB::TickSize,boost::bind(&reqMktDataGUI::myTickSizeUpdate,this,_1,_2))));
    // put this connection into marketDataFeed map, it will be stored in tickSizeMarketDataFeed
    client->marketDataFeedInsert(tickSizeMktData);
    
    
    // and register also for tickString updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickStringMktData(new MarketData(IB::TickString,widget.lineEdit_Id->text().toInt(),contract));    
    // create tickString event observer and push it into vector stored in this GUI form
    tickStringObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickStringMktData,IB::TickString,boost::bind(&reqMktDataGUI::myTickStringUpdate,this,_1,_2))));
    // put this connection into marketDataFeed map, it will be stored in tickStringMarketDataFeed
    client->marketDataFeedInsert(tickStringMktData);    
    
    
    client->reqMktData(widget.lineEdit_Symbol->text().toStdString(), widget.lineEdit_Type->text().toStdString(),
        widget.lineEdit_Exchange->text().toStdString(), widget.lineEdit_Currency->text().toStdString(), 
            widget.lineEdit_Id->text().toInt(), widget.lineEdit_genericTickTags->text().toStdString(), 
            widget.checkBox_Snapshot->isChecked());
    observedContracts.push_back(contract);
//    int i=0;
//    while(i<30000000){
//        client->processMessages();
//        i++;
//    }

   //processMessages();
}  

void reqMktDataGUI::cancelClicked(){
    marketDataFeedDelete();
    endProcessMessages();
} 

void reqMktDataGUI::marketDataFeedDelete(void){
    BOOST_FOREACH( pMktDataObserver o, tickSizeObservers )
    {
        client->cancelMktData(o->get_pMktDataObservable()->getTickerId());
        o->unregisterWithAll();
    } 
    BOOST_FOREACH( pMktDataObserver o, tickPriceObservers )
    {
        client->cancelMktData(o->get_pMktDataObservable()->getTickerId());
        o->unregisterWithAll();
    }
    BOOST_FOREACH( pMktDataObserver o, tickStringObservers )
    {
        client->cancelMktData(o->get_pMktDataObservable()->getTickerId());
        o->unregisterWithAll();
    }
}

void reqMktDataGUI::displayData(int tickerId, rec_ptr record_ptr){
    printf( "displayData: for tickerId: %d\n",tickerId);
    widget.textEdit_dataFeed->append("myTickSizeUpdate something...");
}

void reqMktDataGUI::guiRequestClicked(){
    IB::Contract contract;
    contract.symbol = widget.lineEdit_Symbol->text().toStdString();
    contract.secType = widget.lineEdit_Type->text().toStdString();
    contract.exchange = widget.lineEdit_Exchange->text().toStdString();
    contract.currency = widget.lineEdit_Currency->text().toStdString();
    
    
    // register for tickSize updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<GUIMarketData> tickSizeGUIMktData(new GUIMarketData(IB::TickSize,widget.lineEdit_Id->text().toInt(),contract));    
    // connect slot to signal
    QObject::connect(tickSizeGUIMktData.get(), SIGNAL(newRecord(int, rec_ptr)), this, SLOT(myTickSizeGUIupdate(int, rec_ptr)), Qt::QueuedConnection);
    
    // put this connection into marketDataFeed map, it will be stored in tickSizeMarketDataFeed
    client->guiMarketDataFeedInsert(tickSizeGUIMktData);   
   
    
    client->reqMktData(widget.lineEdit_Symbol->text().toStdString(), widget.lineEdit_Type->text().toStdString(),
        widget.lineEdit_Exchange->text().toStdString(), widget.lineEdit_Currency->text().toStdString(), 
            widget.lineEdit_Id->text().toInt(), widget.lineEdit_genericTickTags->text().toStdString(), 
            widget.checkBox_Snapshot->isChecked());
    observedContracts.push_back(contract);
}
