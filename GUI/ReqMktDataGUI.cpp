/*
 * File:   ReqMktData.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#include "ReqMktDataGUI.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <typeinfo>
#include <ql/patterns/observable.hpp>
    
ReqMktDataGUI::ReqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr, QWidget* parent):client_(client_ptr),QDialog(parent),thisGUIReqActive(false){
    widget.setupUi(this);
    QObject::connect(widget.requestButton, SIGNAL(clicked()), this, SLOT(requestClicked()));
    QObject::connect(widget.cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    QObject::connect(widget.guiRequestButton, SIGNAL(clicked()), this, SLOT(guiRequestClicked()));
    this->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(this,SIGNAL(newMktData(int,rec_ptr)),this,SLOT(displayData(int,rec_ptr)));
}

ReqMktDataGUI::~ReqMktDataGUI() {
   #ifdef DEBUG 
        printf( "I am dead!\n");
   #endif
        if(thisGUIReqActive){
            cancelClicked();
        }
}

void ReqMktDataGUI::myTickPriceUpdate(int tickerId, rec_ptr record_ptr){
    try{
        //const IBAdditions::TickPriceRecord* tickPriceRecord = dynamic_cast<const IBAdditions::TickPriceRecord*>(record.get());
        tickPriceRec_ptr tickPriceRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickPriceRecord>(record_ptr));
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
void ReqMktDataGUI::myTickSizeUpdate(int tickerId, rec_ptr record_ptr){
    try{
        tickSizeRec_ptr tickSizeRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickSizeRecord>(record_ptr));
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
void ReqMktDataGUI::myTickStringUpdate(int tickerId, rec_ptr record_ptr){
        try{
        tickStringRec_ptr tickStringRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickStringRecord>(record_ptr));
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

void ReqMktDataGUI::myTickPriceGUIUpdate(int tickerId, rec_ptr record_ptr){
    try{
        //const IBAdditions::TickPriceRecord* tickPriceRecord = dynamic_cast<const IBAdditions::TickPriceRecord*>(record.get());
        tickPriceRec_ptr tickPriceRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickPriceRecord>(record_ptr));
        #ifdef DEBUG 
           printf( "myTickPriceGUIUpdate! Id: %d, price: %f, tickType: %d\n",tickerId,tickPriceRecord_ptr->price_,tickPriceRecord_ptr->tickType_);
        #endif
        QString qs=QString("TickPriceGUIUp! Id:%1, price:%2, tickType:%3").arg(tickerId).arg(tickPriceRecord_ptr->price_).arg(tickPriceRecord_ptr->tickType_);
        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
           printf( "myTickPriceGUIUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}

void ReqMktDataGUI::myTickSizeGUIUpdate(int tickerId, rec_ptr record_ptr){
    try{
        tickSizeRec_ptr tickSizeRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickSizeRecord>(record_ptr));
    #ifdef DEBUG 
        printf( "myTickSizeGUIUpdate! Id: %d, size: %d, tickType: %d\n",tickerId,tickSizeRecord_ptr->size_,tickSizeRecord_ptr->tickType_);
    #endif
        QString qs=QString("TickSizeGUIUp! Id:%1, size:%2, tickType:%3").arg(tickerId).arg(tickSizeRecord_ptr->size_).arg(tickSizeRecord_ptr->tickType_);
        widget.textEdit_dataFeed->append(qs);
        //widget.textEdit_dataFeed->append("myTickSizeGUIUpdate something...");
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
            printf( "myTickSizeGUIUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}

void ReqMktDataGUI::myTickStringGUIUpdate(int tickerId, rec_ptr record_ptr){
        try{
        tickStringRec_ptr tickStringRecord_ptr(boost::dynamic_pointer_cast<IBAdditions::TickStringRecord>(record_ptr));
    #ifdef DEBUG 
        printf( "myTickStringGUIUpdate! Id: %d, string: %s, tickType: %d\n",tickerId,tickStringRecord_ptr->string.c_str(),tickStringRecord_ptr->tickType_);
    #endif
        QString qs=QString("TickStringGUIUp! Id:%1, string:").arg(tickerId)+QString::fromStdString(tickStringRecord_ptr->string);
        qs+=QString(" tickType:%1").arg(tickStringRecord_ptr->tickType_);
        widget.textEdit_dataFeed->append(qs);
    }catch(std::bad_cast& e){
        #ifdef DEBUG 
            printf( "myTickStringGUIUpdate: badCast for tickerId: %d\n",tickerId);
        #endif
    }
}
//public slots
void ReqMktDataGUI::requestClicked(){
    
    IB::Contract contract;
    contract.symbol = widget.lineEdit_Symbol->text().toStdString();
    contract.secType = widget.lineEdit_Type->text().toStdString();
    contract.exchange = widget.lineEdit_Exchange->text().toStdString();
    contract.currency = widget.lineEdit_Currency->text().toStdString();
    contract.localSymbol = widget.lineEdit_LocalSymbol->text().toStdString();
    
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickPriceMktData(new MarketData(IBAdditions::TickPrice,widget.lineEdit_Id->text().toInt(),contract));
    // create tickPrice event observer and push it into vector stored in this GUI form
    tickPriceObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickPriceMktData,IBAdditions::TickPrice,boost::bind(&ReqMktDataGUI::myTickPriceUpdate,this,_1,_2))));
    // put this connection into tickerIdMarketDataMap, it will be stored in tickPriceMarketDataFeed
    client_->marketDataFeedInsert(tickPriceMktData);
    
    
    // also register for tickSize updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickSizeMktData(new MarketData(IBAdditions::TickSize,widget.lineEdit_Id->text().toInt(),contract));    
    // create tickSize event observer and push it into vector stored in this GUI form
    tickSizeObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickSizeMktData,IBAdditions::TickSize,boost::bind(&ReqMktDataGUI::myTickSizeUpdate,this,_1,_2))));
    // put this connection into tickerIdMarketDataMap, it will be stored in tickSizeMarketDataFeed
    client_->marketDataFeedInsert(tickSizeMktData);
    
    
    // and register also for tickString updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickStringMktData(new MarketData(IBAdditions::TickString,widget.lineEdit_Id->text().toInt(),contract));    
    // create tickString event observer and push it into vector stored in this GUI form
    tickStringObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickStringMktData,IBAdditions::TickString,boost::bind(&ReqMktDataGUI::myTickStringUpdate,this,_1,_2))));
    // put this connection into tickerIdMarketDataMap, it will be stored in tickStringMarketDataFeed
    client_->marketDataFeedInsert(tickStringMktData);    
    
    
    client_->reqMktData(widget.lineEdit_Symbol->text().toStdString(), widget.lineEdit_Type->text().toStdString(),
        widget.lineEdit_Exchange->text().toStdString(), widget.lineEdit_Currency->text().toStdString(), 
            widget.lineEdit_Id->text().toInt(), widget.lineEdit_genericTickTags->text().toStdString(), 
            widget.lineEdit_LocalSymbol->text().toStdString(), widget.checkBox_Snapshot->isChecked());
    observedContracts.insert(std::pair<int, IB::Contract>(widget.lineEdit_Id->text().toInt(),contract));
//    int i=0;
//    while(i<30000000){
//        client->processMessages();
//        i++;
//    }

   //processMessages();
}

void ReqMktDataGUI::cancelClicked() {
    if (thisGUIReqActive) {
        if(client_->isConnected()){
            guiMarketDataFeedDelete();
            marketDataFeedDelete();
        }
//        if (totalGUIReqActive == 1) {
//            endProcessMessages();
//        }
        thisGUIReqActive = false;
        totalGUIReqActive--;
    } else {
        marketDataFeedDelete();
    }
} 

void ReqMktDataGUI::marketDataFeedDelete(void){
//    for(vecPmktDataObsIt it=tickPriceObservers.begin();it!=tickPriceObservers.end();it++){
//        client_->cancelMktData((*it)->get_pMktDataObservable()->getTickerId());
//        (*it)->unregisterWithAll();
//        tickPriceObservers.erase(it);
//    }
//    
//    for(vecPmktDataObsIt it=tickSizeObservers.begin();it!=tickSizeObservers.end();it++){
//        client_->cancelMktData((*it)->get_pMktDataObservable()->getTickerId());
//        (*it)->unregisterWithAll();
//        tickSizeObservers.erase(it);
//    }
//
//    for(vecPmktDataObsIt it=tickStringObservers.begin();it!=tickStringObservers.end();it++){
//        client_->cancelMktData((*it)->get_pMktDataObservable()->getTickerId());
//        (*it)->unregisterWithAll();
//        tickStringObservers.erase(it);
//    }
    printf("\nReqMktdataGUI: canceling mkt data requests\n");
    for(tickerIdContractMap::iterator it = observedContracts.begin(); it!=observedContracts.end(); it++){
        client_->cancelMktData((*it).first);
    }
}

void ReqMktDataGUI::guiMarketDataFeedDelete(void){
    for(tickerIdContractPtrMap::iterator it=guiObservedContracts.begin();it!=guiObservedContracts.end();it++){
        client_->cancelMktData((*it).first);
    }
}

void ReqMktDataGUI::displayData(int tickerId, rec_ptr record_ptr){
    printf( "displayData: for tickerId: %d\n",tickerId);
    widget.textEdit_dataFeed->append("myTickSizeUpdate something...");
}

void ReqMktDataGUI::guiRequestClicked(){
    contract_ptr contract(new IB::Contract());
    contract->symbol = widget.lineEdit_Symbol->text().toStdString();
    contract->secType = widget.lineEdit_Type->text().toStdString();
    contract->exchange = widget.lineEdit_Exchange->text().toStdString();
    contract->currency = widget.lineEdit_Currency->text().toStdString();
    contract->localSymbol = widget.lineEdit_LocalSymbol->text().toStdString();
    
    // register for tickPrice updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<GUIMarketData> tickPriceGUIMktData(new GUIMarketData(IBAdditions::TickPrice,widget.lineEdit_Id->text().toInt(),contract));    
    // connect slot to signal
    QObject::connect(tickPriceGUIMktData.get(), SIGNAL(newRecord(int, rec_ptr)), this, SLOT(myTickPriceGUIUpdate(int, rec_ptr)), Qt::QueuedConnection);
    // put this connection into tickerIdGUIMarketDataMap, it will be stored in tickPriceGUIMarketDataFeed
    client_->guiMarketDataFeedInsert(tickPriceGUIMktData);
    
    // register for tickSize updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<GUIMarketData> tickSizeGUIMktData(new GUIMarketData(IBAdditions::TickSize,widget.lineEdit_Id->text().toInt(),contract));    
    // connect slot to signal
    QObject::connect(tickSizeGUIMktData.get(), SIGNAL(newRecord(int, rec_ptr)), this, SLOT(myTickSizeGUIUpdate(int, rec_ptr)), Qt::QueuedConnection);
    // put this connection into marketDataFeed map, it will be stored in tickSizeMarketDataFeed
    client_->guiMarketDataFeedInsert(tickSizeGUIMktData);   
    
    // register for tickString updates
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<GUIMarketData> tickStringGUIMktData(new GUIMarketData(IBAdditions::TickString,widget.lineEdit_Id->text().toInt(),contract));    
    // connect slot to signal
    QObject::connect(tickStringGUIMktData.get(), SIGNAL(newRecord(int, rec_ptr)), this, SLOT(myTickStringGUIUpdate(int, rec_ptr)), Qt::QueuedConnection);
    // put this connection into marketDataFeed map, it will be stored in tickSizeMarketDataFeed
    client_->guiMarketDataFeedInsert(tickStringGUIMktData);    
   
    //TODO: client->reqMktData has to take all parameters of contract specified in GUI
    // now we process only few of them
    client_->reqMktData(contract->symbol, contract->secType, contract->exchange, contract->currency, 
            widget.lineEdit_Id->text().toInt(), widget.lineEdit_genericTickTags->text().toStdString(), 
            contract->localSymbol, widget.checkBox_Snapshot->isChecked());
    guiObservedContracts.insert(std::pair<int, contract_ptr >(widget.lineEdit_Id->text().toInt(), contract));
    
    thisGUIReqActive=true;
    totalGUIReqActive++;
//    if(totalGUIReqActive==1){
//        processMessages();
//    }
}
