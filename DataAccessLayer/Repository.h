/* 
 * File:   Repository.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 6, 2013, 11:55 PM
 */

#ifndef REPOSITORY_H
#define	REPOSITORY_H

class Repository {
public:
    Repository();
    virtual ~Repository();
    
private:
    Repository(const Repository& orig);

};

#endif	/* REPOSITORY_H */

