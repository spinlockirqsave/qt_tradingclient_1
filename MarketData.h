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
#include "IB_events.h"
#include <list>

typedef boost::shared_ptr<IB::Record> rec_ptr;
typedef boost::shared_ptr<IB::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IB::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IB::TickStringRecord>  tickStringRec_ptr;

class MarketData : public QuantLib::Observable {
public:
    MarketData();
    MarketData(IB::Event processedEvent, int tickerId, IB::Contract contractDescription):
    processedEvent(processedEvent), tickerId(tickerId), contractDescription(contractDescription) {}
    virtual ~MarketData();
    //std::vector<IB::TickPriceRecord> tickPriceData; //market data fed in tickPrice
    //std::vector<IB::TickSizeRecord> tickSizeData; //market data fed in tickSize
    int getTickerId(){ return tickerId; }
    void putRecord(boost::shared_ptr<IB::Record> record){
        record_=record;
    }
    boost::shared_ptr<IB::Record> getRecord(){
        return record_;
    }
    IB::Event getEvent(){
        return processedEvent;
    }    
private:
    MarketData(const MarketData& orig);
    boost::shared_ptr<IB::Record> record_;
    // this MarketData object can handle these events
    // any observer can subscribe to one of those events
    IB::Event processedEvent;
    int tickerId;
    IB::Contract contractDescription;
};

typedef boost::shared_ptr<MarketData> pMyObservable;
typedef boost::function<void (int tickerId, boost::shared_ptr<IB::Record> record)> f_action_ptr;

// one MarketDataObserver may observe one tickerId and for one event
// if you want to be notified when many events happened (i.e. TickSize and TickPrice)
// you can subscribe many MarketDataObservers to one and the same MarketData instance
class MarketDataObserver : public QuantLib::Observer{
public:
    MarketDataObserver(pMyObservable obs, IB::Event observedEvent, f_action_ptr ptr)
        : observable(obs), observedEvent_(observedEvent), f_ptr(ptr){
      this->registerWith(observable);
    }
    MarketDataObserver(const MarketDataObserver &observer)
      : Observer(observer),
        observable(observer.observable){ // faction_ptr is not copied!
    }
    
    // object which subscribed to data stream using this MarketDataObserver
    // will be notified about incoming IB::Record
    void update() {
        if (observable->getEvent() == observedEvent_) {
            //const IB::Record& data=observable->tickPriceData.back();
            boost::shared_ptr<IB::Record> data = observable->getRecord();

            // here appropriate function is called: myTickPriceUpdate,
            // myTickSizeUpdate or myTickStringUpdate depending on what
            // subscribing object specified in f_action_ptr ptr
            // in MarketDataObserver constructor
            f_ptr(observable->getTickerId(), data);
        }
    }
private:
    pMyObservable observable;
    f_action_ptr f_ptr;
    IB::Event observedEvent_; // the single event in which observer is interested
};

typedef boost::shared_ptr<MarketData>  mktData_ptr;

#endif	/* MARKETDATA_H */

