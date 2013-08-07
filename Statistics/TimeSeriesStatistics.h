/* 
 * File:   TimeSeriesStatistics.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 7, 2013, 11:35 PM
 */

#ifndef TIMESERIESSTATISTICS_H
#define	TIMESERIESSTATISTICS_H

#include <DataAccessLayer/MarketData.h>

class TimeSeriesStatistics {
public:
    TimeSeriesStatistics(std::vector<rec_ptr>& data);
    TimeSeriesStatistics(const TimeSeriesStatistics& orig);
    virtual ~TimeSeriesStatistics();
    
private:
    std::vector<rec_ptr>& data_;
};

#endif	/* TIMESERIESSTATISTICS_H */

