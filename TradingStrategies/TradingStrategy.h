/* 
 * File:   TradingStrategy.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 3, 2013, 12:21 AM
 */

#ifndef TRADINGSTRATEGY_H
#define	TRADINGSTRATEGY_H

#include <CommonDefs.h>
#include <DataAccessLayer/MarketData.h>
#include <Shared/Contract.h>
#include <DataAccessLayer/PosixClient.h>

#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include <map>


class TradingStrategy {
public:
    TradingStrategy();
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
    virtual void doStart()=0;
    virtual void tickPriceUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickSizeUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickStringUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void marketDepthUpdate(int tickerId, rec_ptr recor_ptr)=0;
    virtual void marketDepthL2update(int tickerId, rec_ptr recor_ptr)=0;
    
    virtual bool longSignal()=0;
    virtual bool shortSignal()=0;
    virtual bool doLongTrade()=0;
    virtual bool doShortTrade()=0;
    
protected:
    typedef std::map<const IB::TickerId, const IB::Contract> TickerContractMap;
    TickerContractMap oservedContracts_;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers;
    std::vector<pMktDataObserver> tickPriceObservers;
    std::vector<pMktDataObserver> tickStringObservers;
    
    boost::shared_ptr<IB::PosixClient> client;
};

#endif	/* TRADINGSTRATEGY_H */

