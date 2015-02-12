/* 
 * File:   GUIMarketData.h
 * Author: Piotr Gregor  peter cf16 eu
 *
 * Created on June 16, 2013, 4:06 PM
 */

#ifndef GUIMARKETDATA_H
#define	GUIMARKETDATA_H

#include <QtCore/QObject>
#include <DataAccessLayer/MarketData.h>

typedef boost::shared_ptr<IBAdditions::Record> rec_ptr;
typedef boost::shared_ptr<IBAdditions::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickStringRecord>  tickStringRec_ptr;
typedef boost::shared_ptr<IB::Contract> contract_ptr;

class GUIMarketData : public QObject {
    Q_OBJECT
public:
    GUIMarketData();
    GUIMarketData(IBAdditions::Event processedEvent, int tickerId, IB::Contract contract):
                processedEvent_(processedEvent), tickerId_(tickerId), contract_(contract) {
        contractEvent_ = IBAdditions::ContractEvent(contract, processedEvent_);
    }
    virtual ~GUIMarketData();
    int getTickerId()const{
        return tickerId_;
    }
    void putRecord(boost::shared_ptr<IBAdditions::Record> record){
        record_=record;
        marketDataRepository.putRecord(contractEvent_,record_);
    }
    boost::shared_ptr<IBAdditions::Record> getRecord()const{
        return record_;
    }
    IBAdditions::Event getEvent()const{
        return processedEvent_;
    }    
    void notifyObservers(){
        emit newRecord(tickerId_, record_);
    }
    void saveRecord(void){
        // new rec_ptr is created inside vector and pointer owned by record_
        // is copied into it
        data_.push_back(record_);
    }
    signals:
    void newRecord(int tickerId, rec_ptr record);
    
private:
    GUIMarketData(const GUIMarketData& orig);
    rec_ptr record_;
    
    // this GUIMarketData object can handle this event
    // any observer can subscribe to this
    IBAdditions::Event processedEvent_;
    int tickerId_;
    IB::Contract contract_;
    IBAdditions::ContractEvent contractEvent_;
    
    // vector of shared pointers ensures that the allocated object inside of
    // shared_ptr is safely transferred into the vector (ref counting mechanism asserts this)
    std::vector<rec_ptr> data_;
};

typedef boost::shared_ptr<GUIMarketData> pGUIMktData;
typedef boost::function<void (int tickerId, rec_ptr record)> f_action_ptr;


#endif	/* GUIMARKETDATA_H */

