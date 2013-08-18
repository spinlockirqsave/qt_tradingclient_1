/* 
 * File:   TradingStrategy.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 3, 2013, 12:21 AM
 */

#include "TradingStrategy.h"

TradingStrategy::TradingStrategy() {
}

TradingStrategy::TradingStrategy(const TradingStrategy& orig) {
}

TradingStrategy::~TradingStrategy() {
}

void TradingStrategy::doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, 
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

