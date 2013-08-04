/* 
 * File:   TradingStrategy.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 3, 2013, 12:21 AM
 */

#ifndef TRADINGSTRATEGY_H
#define	TRADINGSTRATEGY_H

#include <CommonDefs.h>


class TradingStrategy {
public:
    TradingStrategy();
    TradingStrategy(const TradingStrategy& orig);
    virtual ~TradingStrategy();
private:
    virtual void subscribeToData(IB::TickerId tickerId)=0;
    void start();
};

#endif	/* TRADINGSTRATEGY_H */

