/* 
 * File:   MessageProcessor.cpp
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on June 17, 2013, 11:58 PM
 */


#include "MessageProcessor.h"

MessageProcessor::MessageProcessor(boost::shared_ptr<IB::PosixClient> client, QObject* parent)
     : client(client), QThread(parent){
 }

MessageProcessor::~MessageProcessor(){
    
}
