/* 
 * File:   CointegrationImpl.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 25, 2013, 9:34 PM
 */

#ifndef COINTEGRATIONIMPL_H
#define	COINTEGRATIONIMPL_H

#include <TradingStrategies/TradingStrategyImpl.h>
#include <Shared/CommonDefs.h>
#include <DataAccessLayer/MarketData.h>
#include <Shared/Contract.h>
#include <DataAccessLayer/PosixClient.h>

#include <boost/shared_ptr.hpp>
#include <boost/foreach.hpp>

#include <map>

/** Bridge pattern: "ConcreteImplementor" */
class CointegrationImpl : public TradingStrategyImpl{
public:
    CointegrationImpl();
    CointegrationImpl(const CointegrationImpl& orig);
    virtual ~CointegrationImpl();
    
    void doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract contract, f_action_ptr ptr);
    
private:
    typedef std::map<const IB::TickerId, const IB::Contract> TickerContractMap;
    TickerContractMap oservedContracts_;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers_;
    std::vector<pMktDataObserver> tickPriceObservers_;
    std::vector<pMktDataObserver> tickStringObservers_;
    
    boost::shared_ptr<IB::PosixClient> client_;
};

#endif	/* COINTEGRATIONIMPL_H */

