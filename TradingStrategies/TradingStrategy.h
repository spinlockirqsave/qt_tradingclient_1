/* 
 * File:   TradingStrategy.h
 * Author: Piotr Gregor  peter cf16 eu
 *
 * Created on August 3, 2013, 12:21 AM
 */

#ifndef TRADINGSTRATEGY_H
#define	TRADINGSTRATEGY_H

//#include <Shared/CommonDefs.h>
//#include <DataAccessLayer/MarketData.h>
//#include <Shared/Contract.h>
#include <DataAccessLayer/PosixClient.h>

#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include <map>

/** Bridge pattern: "Implementor" */
class TradingStrategyImpl;


/** Bridge pattern: "Abstraction" */
/**
 * @param pimpl pointer to implementation
 * 
 *  Here the interface base class “has” a pointer
 *  to the implementation base class, and each class
 *  in the interface hierarchy is responsible for
 *  populating the base class pointer with the correct
 *  concrete trading strategy implementation class. 
 *  Then all requests are simply delegated by the
 *  interface class to the encapsulated implementation
 */

//struct IBAdditions::Event;
//class IB::TickerId; 
class IB::Contract;

class TradingStrategy {
public:
    TradingStrategy(TradingStrategyImpl* pimpl);
    TradingStrategy(const TradingStrategy& orig);
    virtual ~TradingStrategy();
    
    // Template Method Pattern
    void subscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr){
        doSubscribeToData(event, tickerId, contract, ptr);
    }
    
    void start(){
        doStart();
    }
    
private:
    virtual void doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr);
    virtual void doStart();
    virtual void tickPriceUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickSizeUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickStringUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void marketDepthUpdate(int tickerId, rec_ptr recor_ptr)=0;
    virtual void marketDepthL2update(int tickerId, rec_ptr recor_ptr)=0;
    
    virtual bool longSignal()=0;
    virtual bool shortSignal()=0;
    virtual bool doLongTrade()=0;
    virtual bool doShortTrade()=0;
    
    TradingStrategyImpl* pimpl_;
    
protected:
    
};

#endif	/* TRADINGSTRATEGY_H */

