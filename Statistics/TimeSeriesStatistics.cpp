/* 
 * File:   TimeSeriesStatistics.cpp
 * Author: Piotr Gregor  piter cf16 eu
 * 
 * Created on August 7, 2013, 11:35 PM
 */

#include "TimeSeriesStatistics.h"


TimeSeriesStatistics::TimeSeriesStatistics(std::vector<rec_ptr>& data) 
: data_(data) {
    
}

TimeSeriesStatistics::TimeSeriesStatistics(const TimeSeriesStatistics& orig)
: data_(orig.data_) {
    
}

TimeSeriesStatistics::~TimeSeriesStatistics() {
}

