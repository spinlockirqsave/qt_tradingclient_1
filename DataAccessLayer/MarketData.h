/* 
 * File:   MarketData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 26, 2013, 7:06 PM
 */
#include <IBAdditions/IB_events.h>

#ifndef MARKETDATA_H
#define	MARKETDATA_H

#include <ql/patterns/observable.hpp>
#include <Shared/Contract.h>
#include <boost/function.hpp>

typedef boost::shared_ptr<IB::Record> rec_ptr;
typedef boost::shared_ptr<IBAdditions::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IB::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IB::TickStringRecord>  tickStringRec_ptr;
typedef boost::shared_ptr<IB::MktDepthRecord>  mktDepthRec_ptr;
typedef boost::shared_ptr<IB::MktDepthL2Record>  mktDepthL2Rec_ptr;

// This is a class which allows non GUI objects to subscribe
// to market data being returned from tickSize, tickPrice, tickString
// and other PosixClient callbacks when corresponding reqMktData request
// has been sent to be processed by PosixClient instance. This class
// and MarketDataObserver class use Observer Pattern implemented with 
// help from QuantLib::Observable and QuantLib::Observer.

class MarketData : public QuantLib::Observable {
public:
    MarketData();
    MarketData(IBAdditions::Event processedEvent, int tickerId, IB::Contract contractDescription):
    processedEvent(processedEvent), tickerId(tickerId), contractDescription(contractDescription) {}
    virtual ~MarketData();
    int getTickerId()const{ return tickerId; }
    void putRecord(boost::shared_ptr<IB::Record> record){
        record_=record;
    }
    boost::shared_ptr<IB::Record> getRecord()const{
        return record_;
    }
    IBAdditions::Event getEvent()const{
        return processedEvent;
    }    
private:
    MarketData(const MarketData& orig);
    boost::shared_ptr<IB::Record> record_;
    // this MarketData object can handle these events
    // any observer can subscribe to one of these events
    IBAdditions::Event processedEvent;
    int tickerId;
    IB::Contract contractDescription;
};

typedef boost::shared_ptr<MarketData> pMktDataObservable;
typedef boost::function<void (int tickerId, boost::shared_ptr<IB::Record> record)> f_action_ptr;

// one MarketDataObserver may observe one tickerId and for one event
// if you want to be notified when many events happened (i.e. TickSize and TickPrice)
// you can subscribe many MarketDataObservers to one and the same MarketData instance
class MarketDataObserver : public QuantLib::Observer{
public:
    MarketDataObserver(pMktDataObservable obs, IBAdditions::Event observedEvent, f_action_ptr ptr)
        : observable(obs), observedEvent_(observedEvent), f_ptr(ptr){
      this->registerWith(observable);
    }
    MarketDataObserver(const MarketDataObserver &observer)
      : Observer(observer),observedEvent_(observer.getEvent()),
        observable(observer.observable){ // faction_ptr is not copied!
    }
    
    IBAdditions::Event getEvent()const{
        return observedEvent_;
    }
        
    // object which subscribed to data stream using this MarketDataObserver
    // will be notified about incoming IB::Record
    void update(){
        if (observable->getEvent() == observedEvent_) {
            //const IB::Record& data=observable->tickPriceData.back();
            boost::shared_ptr<IB::Record> data = observable->getRecord();

            // here appropriate function of subscribing object is called:
            // myTickPriceUpdate, myTickSizeUpdate or myTickStringUpdate 
            // depending on what subscribing object has specified in 
            //f_action_ptr ptr in MarketDataObserver constructor
            f_ptr(observable->getTickerId(), data);
        }
    }
    
    pMktDataObservable get_pMktDataObservable(){
        return observable;
    }
private:
    pMktDataObservable observable;
    f_action_ptr f_ptr;
    IBAdditions::Event observedEvent_; // the single event in which observer is interested
};

typedef boost::shared_ptr<MarketDataObserver> pMktDataObserver;
#endif	/* MARKETDATA_H */

