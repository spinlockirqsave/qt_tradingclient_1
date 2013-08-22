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

/**
 * in memory database implementation
 */
class Repository {
public:
    typedef std::map<const IBAdditions::ContractEvent, std::vector<IBAdditions::rec_ptr> > ContractEventDataMap;
    Repository(const std::vector<IBAdditions::ContractEvent>& contractEventVector);
    Repository();
    virtual ~Repository();
    
    /**
     * insert record into repository
     * @param ce key to the map, IB::Contract and IBAdditions::Event
     * @param rptr record to be stored into repository
     */
    void putRecord(const IBAdditions::ContractEvent ce, const IBAdditions::rec_ptr rptr);
    
    /**
     * get corresponding vector based on ContactEvent key
     * @param contractEvent
     * @return reference to vector of records
     */
    std::vector<IBAdditions::rec_ptr>& operator[](const IBAdditions::ContractEvent& contractEvent){
        return contractEventDataMap_[contractEvent];
    }
    
    /**
     * 
     * @return 
     */
    int contractEventCount(){
        return contractEventDataMap_.size();
    }
private:
    Repository(const Repository& orig);
    ContractEventDataMap contractEventDataMap_;

};
//extern Repository marketDataRepository;

#endif	/* REPOSITORY_H */

