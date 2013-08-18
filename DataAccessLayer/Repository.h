/* 
 * File:   Repository.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 6, 2013, 11:55 PM
 */

#ifndef REPOSITORY_H
#define	REPOSITORY_H

#include <map>
#include <vector>
#include <Shared/Contract.h>
#include <boost/foreach.hpp>
#include <IBAdditions/IB_events.h>

class Repository {
public:
    typedef std::map<const IBAdditions::ContractEvent, std::vector<double> > ContractEventDataMap;
    Repository(const std::vector<IBAdditions::ContractEvent>& contractEventVector);
    Repository();
    virtual ~Repository();
    
private:
    Repository(const Repository& orig);
    ContractEventDataMap contractEventDataMap_;

};

#endif	/* REPOSITORY_H */

