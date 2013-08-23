/* 
 * File:   Repository.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 6, 2013, 11:55 PM
 */

#include <math.h>
#include <stdio.h>
#include "Repository.h"

/**
 * 
 * @param contractEventVector
 */
Repository::Repository(const std::vector<IBAdditions::ContractEvent>& contractEventVector) {
    BOOST_FOREACH(const IBAdditions::ContractEvent ce, contractEventVector){
        contractEventDataMap_.insert(std::pair<IBAdditions::ContractEvent, 
                std::vector<IBAdditions::rec_ptr> >(ce, std::vector<IBAdditions::rec_ptr>()));
    }
}

Repository::Repository(){
}

Repository::Repository(const Repository& orig) {
}

Repository::~Repository() {
}

/**
 * 
 * @param ce key to the map, IB::Contract and IBAdditions::Event
 * @param rptr record to be stored into repository
 * TODO: lock mutex here before push_back into Repository
 * and wake up waiting threads
 */
void Repository::putRecord(const IBAdditions::ContractEvent ce, const IBAdditions::rec_ptr rptr){
    printf("[Repository] vector size is; %d\n", contractEventDataMap_[ce].size());
    contractEventDataMap_[ce].push_back(rptr);
    printf("[Repository] vector size is; %d\n", contractEventDataMap_[ce].size());
}

