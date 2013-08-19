/* 
 * File:   Repository.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 6, 2013, 11:55 PM
 */

#include <math.h>

#include "Repository.h"


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

void Repository::putRecord(const IBAdditions::ContractEvent ce, const IBAdditions::rec_ptr rptr){
    contractEventDataMap_[ce].push_back(rptr);
}

