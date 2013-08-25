/* 
 * File:   CointegrationImpl.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 25, 2013, 9:34 PM
 */

#ifndef COINTEGRATIONIMPL_H
#define	COINTEGRATIONIMPL_H

#include <TradingStrategies/TradingStrategyImpl.h>

/** Bridge pattern: "ConcreteImplementor" */
class CointegrationImpl : public TradingStrategyImpl{
public:
    CointegrationImpl();
    CointegrationImpl(const CointegrationImpl& orig);
    virtual ~CointegrationImpl();
private:

};

#endif	/* COINTEGRATIONIMPL_H */

