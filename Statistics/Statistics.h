/* 
 * File:   Statistics.h
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on August 7, 2013, 11:28 PM
 */

#ifndef STATISTICS_H
#define	STATISTICS_H

#include <ql/math/statistics/generalstatistics.hpp>


class Statistics : public QuantLib::GeneralStatistics {
public:
    Statistics();
    Statistics(const Statistics& orig);
    virtual ~Statistics();
private:

};

#endif	/* STATISTICS_H */

