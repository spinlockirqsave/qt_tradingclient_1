/* 
 * File:   Cointegration.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 3, 2013, 10:53 PM
 */

#ifndef COINTEGRATION_H
#define	COINTEGRATION_H

#include <TradingStrategies/TradingStrategy.h>


class Cointegration : TradingStrategy {
public:
    Cointegration();
    Cointegration(const Cointegration& orig);
    virtual ~Cointegration();
private:
    virtual void doSubscribeToData(IB::TickerId tickerId);
    virtual void doStart();
    virtual void tickPriceUpdate(int tickerId, rec_ptr record_ptr);
    virtual void tickSizeUpdate(int tickerId, rec_ptr record_ptr);
    virtual void tickStringUpdate(int tickerId, rec_ptr record_ptr);
    void marketDepthUpdate(int tickerId, rec_ptr recor_ptr);
    void marketDepthL2update(int tickerId, rec_ptr recor_ptr);    
};

#endif	/* COINTEGRATION_H */

