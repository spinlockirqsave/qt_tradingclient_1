/* 
 * File:   TradingStrategyImpl.h
 * Author: Piotr Gregor  peter cf16 eu
 *
 * Created on August 25, 2013, 9:15 PM
 */

#ifndef TRADINGSTRATEGYIMPL_H
#define	TRADINGSTRATEGYIMPL_H

#include <Shared/CommonDefs.h>
#include <DataAccessLayer/MarketData.h>
#include <Shared/Contract.h>
#include <DataAccessLayer/PosixClient.h>
#include <TradingStrategies/TradingStrategy.h>

#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include <map>

/** Bridge pattern: "Implementor abstract base" */
class TradingStrategyImpl {
public:
    TradingStrategyImpl();
    TradingStrategyImpl(const TradingStrategyImpl& orig);
    virtual ~TradingStrategyImpl();
    
    void subscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr) {
        doSubscribeToData(event, tickerId, contract, ptr);
    }
    void start() {
        doStart();
    }
private:
    virtual void doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr)=0;
    virtual void doStart()=0;
};

#endif	/* TRADINGSTRATEGYIMPL_H */

