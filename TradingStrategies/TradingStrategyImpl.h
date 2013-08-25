/* 
 * File:   TradingStrategyImpl.h
 * Author: Piotr Gregor  postmaster@cf16.eu
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

/** Bridge pattern: "Implementor" */
class TradingStrategyImpl {
public:
    TradingStrategyImpl();
    TradingStrategyImpl(const TradingStrategyImpl& orig);
    virtual ~TradingStrategyImpl();
    
    virtual void doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr)=0;
private:

};

#endif	/* TRADINGSTRATEGYIMPL_H */

