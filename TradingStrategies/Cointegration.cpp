/* 
 * File:   Cointegration.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 3, 2013, 10:53 PM
 */

#include "Cointegration.h"

Cointegration::Cointegration() {
}

Cointegration::Cointegration(const Cointegration& orig) : TradingStrategy(orig) {
}

Cointegration::~Cointegration() {
}

void Cointegration::subscribeToData(IB::TickerId tickerId){
    
}
