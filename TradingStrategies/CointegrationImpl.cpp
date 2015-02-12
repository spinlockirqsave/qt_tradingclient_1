/* 
 * File:   CointegrationImpl.cpp
 * Author: Piotr Gregor  peter cf16 eu
 * 
 * Created on August 25, 2013, 9:34 PM
 */

#include <TradingStrategies/CointegrationImpl.h>

CointegrationImpl::CointegrationImpl() {
}

CointegrationImpl::CointegrationImpl(const CointegrationImpl& orig) {
}

CointegrationImpl::~CointegrationImpl() {
}

void CointegrationImpl::doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, 
        IB::Contract contract, f_action_ptr action_ptr){
    // map MarketData to event, tickerId and contractDescription
    boost::shared_ptr<MarketData> tickMktData(new MarketData(event, tickerId, contract));
    
    // create tick event observer and push it into vector
    tickPriceObservers_.push_back(boost::shared_ptr<MarketDataObserver>(
            new MarketDataObserver(tickMktData, event, action_ptr)));
    
    // put this connection into tickerIdMarketDataMap,
    // it will be stored in appropriate tickMarketData
    // depending on IBAdditions::Event type specified in this 
    // MarketData instance
    client_->marketDataFeedInsert(tickMktData);
}

void CointegrationImpl::doStart(){
    //do start !
}


