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

class Repository {
public:
    Repository(const std::vector<IB::Contract>& contracts);
    virtual ~Repository();
    
private:
    Repository(const Repository& orig);
    typedef std::map<const IB::Contract, std::vector<double> > ContractDataMap;
    ContractDataMap map_;

};

#endif	/* REPOSITORY_H */

