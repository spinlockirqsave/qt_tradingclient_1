/* 
 * File:   MarketData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 26, 2013, 7:06 PM
 */

#ifndef MARKETDATA_H
#define	MARKETDATA_H

#include <ql/patterns/observable.hpp>
#include "Contract.h"
#include <boost/function.hpp>


class MarketData : public QuantLib::Observable {
public:
    MarketData();
    MarketData(IB::Contract c, int tickerId):c(c),tickerId(tickerId){}
    virtual ~MarketData();
    std::vector<IB::TickPriceRecord> tickPriceData; //market data fed in tickPrice
    std::vector<IB::TickSizeRecord> tickSizeData; //market data fed in tickSize
    IB::Contract c;
    int tickerId;
private:
    MarketData(const MarketData& orig);
};

typedef boost::shared_ptr<MarketData> pMyObservable;
typedef boost::function<void (int tickerId, const IB::Record& record)> f_action_ptr;

class MarketDataObserver : public QuantLib::Observer{
public:
    MarketDataObserver(pMyObservable obs, f_action_ptr ptr)
        : observable(obs), f_ptr(ptr){
      this->registerWith(observable);
    }
    MarketDataObserver(const MarketDataObserver &observer)
      : Observer(observer),
        observable(observer.observable){ // faction_ptr is not copied!
    }  
    void update(){
        const IB::Record& data=observable->tickPriceData.back();
        f_ptr(observable->tickerId, data);
    }
private:
    pMyObservable observable;
    f_action_ptr f_ptr;
};

#endif	/* MARKETDATA_H */

