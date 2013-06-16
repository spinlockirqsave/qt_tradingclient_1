/* 
 * File:   GUIGUIMarketData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on June 16, 2013, 4:06 PM
 */

#ifndef GUIMARKETDATA_H
#define	GUIMARKETDATA_H

#include "Contract.h"
#include <boost/function.hpp>
#include "IB_events.h"
#include <list>


typedef boost::shared_ptr<IB::Record> rec_ptr;
typedef boost::shared_ptr<IB::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IB::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IB::TickStringRecord>  tickStringRec_ptr;

class GUIMarketData {
public:
    GUIMarketData();
    GUIMarketData(IB::Event processedEvent, int tickerId, IB::Contract contractDescription):
    processedEvent(processedEvent), tickerId(tickerId), contractDescription(contractDescription) {}
    virtual ~GUIMarketData();
    int getTickerId()const{ return tickerId; }
    void putRecord(boost::shared_ptr<IB::Record> record){
        record_=record;
    }
    boost::shared_ptr<IB::Record> getRecord()const{
        return record_;
    }
    IB::Event getEvent()const{
        return processedEvent;
    }    
private:
    GUIMarketData(const GUIMarketData& orig);
    boost::shared_ptr<IB::Record> record_;
    // this GUIMarketData object can handle these events
    // any observer can subscribe to one of those events
    IB::Event processedEvent;
    int tickerId;
    IB::Contract contractDescription;
};

typedef boost::shared_ptr<GUIMarketData> pGUIMktDataObservable;
typedef boost::function<void (int tickerId, boost::shared_ptr<IB::Record> record)> f_action_ptr;


// one GUIMarketDataObserver may observe one tickerId and for one event
// if you want to be notified when many events happened (i.e. TickSize and TickPrice)
// you can subscribe many GUIMarketDataObservers to one and the same GUIMarketData instance
class GUIMarketDataObserver{
public:
    GUIMarketDataObserver(pGUIMktDataObservable obs, IB::Event observedEvent, f_action_ptr ptr)
        : observable(obs), observedEvent_(observedEvent), f_ptr(ptr){
      //this->registerWith(observable);
    }
    
    // object which subscribed to data stream using this GUIMarketDataObserver
    // will be notified about incoming IB::Record
    void update(){
        if (observable->getEvent() == observedEvent_) {
            //const IB::Record& data=observable->tickPriceData.back();
            boost::shared_ptr<IB::Record> data = observable->getRecord();

            // here appropriate function of subscribing object is called:
            // myTickPriceUpdate, myTickSizeUpdate or myTickStringUpdate 
            // depending on what subscribing object has specified in 
            //f_action_ptr ptr in GUIMarketDataObserver constructor
            f_ptr(observable->getTickerId(), data);
        }
    }
    
    pGUIMktDataObservable get_pMktDataObservable(){
        return observable;
    }
private:
    pGUIMktDataObservable observable;
    f_action_ptr f_ptr;
    IB::Event observedEvent_; // the single event in which observer is interested
};

typedef boost::shared_ptr<GUIMarketDataObserver> pGUIMktDataObserver;
#endif	/* GUIMARKETDATA_H */

