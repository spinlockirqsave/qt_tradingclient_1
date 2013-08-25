/* 
 * File:   TradingStrategyImpl.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 25, 2013, 9:15 PM
 */

#ifndef TRADINGSTRATEGYIMPL_H
#define	TRADINGSTRATEGYIMPL_H

/** Bridge pattern: "Implementor" */
class TradingStrategyImpl {
public:
    TradingStrategyImpl();
    TradingStrategyImpl(const TradingStrategyImpl& orig);
    virtual ~TradingStrategyImpl();
private:

};

#endif	/* TRADINGSTRATEGYIMPL_H */

