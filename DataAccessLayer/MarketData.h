/* 
 * File:   MarketData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 26, 2013, 7:06 PM
 */
#include <IBAdditions/IB_events.h>
#include <DataAccessLayer/Repository.h>

#ifndef MARKETDATA_H
#define	MARKETDATA_H

#include <ql/patterns/observable.hpp>
#include <Shared/Contract.h>
#include <boost/function.hpp>

extern Repository marketDataRepository;

typedef boost::shared_ptr<IBAdditions::Record> rec_ptr;
typedef boost::shared_ptr<IBAdditions::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickStringRecord>  tickStringRec_ptr;
typedef boost::shared_ptr<IBAdditions::MktDepthRecord>  mktDepthRec_ptr;
typedef boost::shared_ptr<IBAdditions::MktDepthL2Record>  mktDepthL2Rec_ptr;

// This is a class which allows non GUI objects to subscribe
// to market data being returned from tickSize, tickPrice, tickString
// and other PosixClient callbacks when corresponding reqMktData request
// has been sent to be processed by PosixClient instance. This class
// and MarketDataObserver class use Observer Pattern implemented with 
// help from QuantLib::Observable and QuantLib::Observer.
class MarketData : public QuantLib::Observable {
public:
    //MarketData();
    MarketData(IBAdditions::Event processedEvent, int tickerId, IB::Contract contract):
    processedEvent(processedEvent), tickerId(tickerId), contract_(contract) {
        contractEvent_ = IBAdditions::ContractEvent(contract, processedEvent);
    }
    virtual ~MarketData();
    int getTickerId()const{ return tickerId; }
    void putRecord(boost::shared_ptr<IBAdditions::Record> record){
        record_=record;
        marketDataRepository.putRecord(contractEvent_,record_);
    }
    boost::shared_ptr<IBAdditions::Record> getRecord() const {
        return record_;
    }
    IBAdditions::Event getEvent()const{
        return processedEvent;
    }    
private:
    MarketData(const MarketData& orig);
    boost::shared_ptr<IBAdditions::Record> record_;
    
    // this MarketData object can handle this event
    IBAdditions::Event processedEvent;
    int tickerId;
    IB::Contract contract_;
    IBAdditions::ContractEvent contractEvent_;
};

typedef boost::shared_ptr<MarketData> pMktDataObservable;
typedef boost::function<void (int tickerId, boost::shared_ptr<IBAdditions::Record> record)> f_action_ptr;

// one MarketDataObserver may observe one tickerId and for one event
// if you want to be notified when many events happened (i.e. TickSize and TickPrice)
// you can subscribe to appropriate MarketData instance
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
    // will be notified about incoming IBAdditions::Record
    void update(){
        if (observable->getEvent() == observedEvent_) {
            //const IBAdditions::Record& data=observable->tickPriceData.back();
            boost::shared_ptr<IBAdditions::Record> data = observable->getRecord();

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

