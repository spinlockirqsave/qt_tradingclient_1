/* 
 * File:   IB_events.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on Aug 21, 2013, 2:30 AM
 */


#include <IBAdditions/IB_events.h>

namespace IBAdditions{

std::string ibTickTypeToStdString(IB::TickType tickType){
    switch (tickType){
        case IB::BID_SIZE:
            return "BID_SIZE";
            break;
        case IB::BID:
            return "BID";
            break;
        case IB::ASK:
            return "ASK";
            break;
        case IB::ASK_SIZE:
            return "ASK_SIZE";
            break;
        case IB::LAST:
            return "LAST";
            break;
        case IB::LAST_SIZE:
            return "LAST_SIZE";
            break;
        case IB::HIGH:
            return "HIGH";
            break;
        case IB::LOW:
            return "LOW";
            break;
        case IB::VOLUME:
            return "VOLUME";
            break;
        case IB::CLOSE:
            return "CLOSE";
            break;
        default:
            return "NOT_SET";
    }
}

std::string ibAdditionsEventToStdString(IBAdditions::Event event) {
    switch (event){
        case IBAdditions::TickPrice:
            return "TickPrice";
            break;
        case IBAdditions::TickSize:
            return "TickSize";
            break;
        case IBAdditions::TickString:
            return "TickString";
            break;
        case IBAdditions::MarketDepth:
            return "MarketDepth";
            break;
        case IBAdditions::MarketDepthL2:
            return "MarketDepthL2";
            break;
            
        default:
            return "NOT_SET";
    }
}

}//namepsace IBAdditions
