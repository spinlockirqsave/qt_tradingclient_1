/* 
 * File:   Cointegration.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 3, 2013, 10:53 PM
 */

#ifndef COINTEGRATION_H
#define	COINTEGRATION_H

#include <TradingStrategies/TradingStrategy.h>
#include <TradingStrategies/CointegrationImpl.h>

/** Bridge pattern: "Refined Abstraction" */
class Cointegration : public TradingStrategy {
public:
    Cointegration(int dimension = 2);
    virtual ~Cointegration();
    
private:
    
    Cointegration(const Cointegration& orig);
    //virtual void doSubscribeToData(IBAdditions::Event event, IB::TickerId tickerId, IB::Contract, f_action_ptr ptr);
    virtual void doStart();
    virtual void tickPriceUpdate(int tickerId, rec_ptr record_ptr);
    virtual void tickSizeUpdate(int tickerId, rec_ptr record_ptr);
    virtual void tickStringUpdate(int tickerId, rec_ptr record_ptr);
    virtual void marketDepthUpdate(int tickerId, rec_ptr recor_ptr);
    virtual void marketDepthL2update(int tickerId, rec_ptr recor_ptr);
    
    virtual bool longSignal();
    virtual bool shortSignal();
    virtual bool doLongTrade();
    virtual bool doShortTrade();
    
    int dimension_;
    CointegrationImpl* pimpl;
};

#endif	/* COINTEGRATION_H */

