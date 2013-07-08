/* 
 * File:   GUIMarketData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on June 16, 2013, 4:06 PM
 */

#ifndef GUIMARKETDATA_H
#define	GUIMARKETDATA_H

#include <QtCore/QObject>
#include "MarketData.h"

typedef boost::shared_ptr<IB::Record> rec_ptr;
typedef boost::shared_ptr<IB::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IB::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IB::TickStringRecord>  tickStringRec_ptr;
typedef boost::shared_ptr<IB::Contract> contract_ptr;

class GUIMarketData : public QObject {
    Q_OBJECT
public:
    GUIMarketData();
    GUIMarketData(const int processedEvent, int tickerId, contract_ptr contractDescription):
                processedEvent(processedEvent), tickerId(tickerId), contractDescription(contractDescription) {}
    virtual ~GUIMarketData();
    int getTickerId()const{ return tickerId; }
    void putRecord(boost::shared_ptr<IB::Record> record){
        record_=record;
    }
    boost::shared_ptr<IB::Record> getRecord()const{
        return record_;
    }
    int getEvent()const{
        return processedEvent;
    }    
    void notifyObservers(){
        emit newRecord(tickerId, record_);
    }
    void saveRecord(void){
        // new rec_ptr is created inside vector and pointer owned by record_
        // is copied into it
        data.push_back(record_);
    }
    signals:
    void newRecord(int tickerId, rec_ptr record);
    
private:
    GUIMarketData(const GUIMarketData& orig);
    rec_ptr record_;
    
    // this GUIMarketData object can handle these events
    // any observer can subscribe to one of those events
    const int processedEvent;
    int tickerId;
    contract_ptr contractDescription;
    
    // vector of shared pointers ensures that the allocated object inside of
    // shared_ptr is safely transferred into the vector (ref counting mechanism asserts this)
    std::vector<rec_ptr> data;
};

typedef boost::shared_ptr<GUIMarketData> pGUIMktData;
typedef boost::function<void (int tickerId, rec_ptr record)> f_action_ptr;


#endif	/* GUIMARKETDATA_H */

