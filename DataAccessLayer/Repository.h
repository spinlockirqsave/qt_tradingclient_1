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
    typedef std::map<const IBAdditions::ContractEvent, std::vector<IBAdditions::rec_ptr> > ContractEventDataMap;
    Repository(const std::vector<IBAdditions::ContractEvent>& contractEventVector);
    Repository();
    virtual ~Repository();
    
    void putRecord(const IBAdditions::ContractEvent, const IBAdditions::rec_ptr);
    
private:
    Repository(const Repository& orig);
    ContractEventDataMap contractEventDataMap_;

};
//extern Repository marketDataRepository;

#endif	/* REPOSITORY_H */

