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
    void subscribeToData(IB::TickerId tickerId);
};

#endif	/* COINTEGRATION_H */

