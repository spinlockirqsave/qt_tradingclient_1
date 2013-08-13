/* 
 * File:   Repository.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 6, 2013, 11:55 PM
 */

#include "Repository.h"

Repository::Repository(const std::vector<IB::Contract>& contracts) {
    BOOST_FOREACH(IB::Contract c, contracts){
        map_.insert(std::pair<IB::Contract, std::vector<double> >(c, std::vector<double>()));
    }
}

Repository::Repository(const Repository& orig) {
}

Repository::~Repository() {
}

