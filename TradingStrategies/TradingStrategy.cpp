/* 
 * File:   TradingStrategy.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 3, 2013, 12:21 AM
 */

#include <TradingStrategies/TradingStrategy.h>
#include <TradingStrategies/TradingStrategyImpl.h>

TradingStrategy::TradingStrategy(TradingStrategyImpl* pimpl) : pimpl_(pimpl) {
}

TradingStrategy::TradingStrategy(const TradingStrategy& orig) {
}

TradingStrategy::~TradingStrategy() {
}

void TradingStrategy::doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, 
        IB::Contract contract, f_action_ptr action_ptr){
    pimpl_->subscribeToData(event, tickerId, contract, action_ptr);
}

void TradingStrategy::doStart(){
    pimpl_->start();
}
