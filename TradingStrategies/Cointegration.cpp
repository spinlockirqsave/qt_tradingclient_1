/* 
 * File:   Cointegration.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 3, 2013, 10:53 PM
 */

#include "Cointegration.h"

Cointegration::Cointegration(int dimension):dimension_(dimension) {
}

Cointegration::Cointegration(const Cointegration& orig) : TradingStrategy(orig) {
}

Cointegration::~Cointegration() {
}

void Cointegration::doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, 
        IB::Contract contract, f_action_ptr action_ptr){
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickMktData(new MarketData(event, tickerId, contract));
    
    // create tick event observer and push it into vector
    tickPriceObservers.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickMktData, event, action_ptr)));
    
    // put this connection into tickerIdMarketDataMap,
    // it will be stored in appropriate tickMarketData
    // depending on IBAdditions::Event type specified in this 
    // MarketData instance
    client->marketDataFeedInsert(tickMktData);
}

void Cointegration::doStart(){
    
}

void Cointegration::tickPriceUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::tickSizeUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::tickStringUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::marketDepthUpdate(int tickerId, rec_ptr recor_ptr){
    
}

void Cointegration::marketDepthL2update(int tickerId, rec_ptr recor_ptr){
    
}

bool Cointegration::longSignal(){
    
}

bool Cointegration::shortSignal(){
    
}

bool Cointegration::doLongTrade(){
    
}

bool Cointegration::doShortTrade(){
    
}