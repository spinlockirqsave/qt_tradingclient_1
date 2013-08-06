/* 
 * File:   Cointegration.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 3, 2013, 10:53 PM
 */

#include "Cointegration.h"

Cointegration::Cointegration(int dimension):dimension_(dimension) {
}

Cointegration::Cointegration(const Cointegration& orig) : TradingStrategy(orig) {
}

Cointegration::~Cointegration() {
}

void Cointegration::doSubscribeToData(IB::TickerId tickerId){
    
}

void Cointegration::doStart(){
    
}

void Cointegration::tickPriceUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::tickSizeUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::tickStringUpdate(int tickerId, rec_ptr record_ptr){
    
}

void Cointegration::marketDepthUpdate(int tickerId, rec_ptr recor_ptr){
    
}

void Cointegration::marketDepthL2update(int tickerId, rec_ptr recor_ptr){
    
}

bool Cointegration::longSignal(){
    
}

bool Cointegration::shortSignal(){
    
}

bool Cointegration::doLongTrade(){
    
}

bool Cointegration::doShortTrade(){
    
}