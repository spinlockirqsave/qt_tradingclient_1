/* 
 * File:   IB_events.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 29, 2013, 1:16 AM
 */

#ifndef IB_EVENTS_H
#define	IB_EVENTS_H

#include <Shared/Contract.h>
#include <Shared/IBString.h>
#include <boost/shared_ptr.hpp>

namespace IBAdditions {

    enum Event {
        TickPrice,
        TickSize,
        TickString,
        MarketDepth,
        MarketDepthL2
        //        const int CLIENT_VERSION = 53;
        //        const int SERVER_VERSION = 38;
        //
        //        // outgoing msg id's
        //        const int REQ_MKT_DATA = 1;
        //        const int CANCEL_MKT_DATA = 2;
        //        const int PLACE_ORDER = 3;
        //        const int CANCEL_ORDER = 4;
        //        const int REQ_OPEN_ORDERS = 5;
        //        const int REQ_ACCT_DATA = 6;
        //        const int REQ_EXECUTIONS = 7;
        //        const int REQ_IDS = 8;
        //        const int REQ_CONTRACT_DATA = 9;
        //        const int REQ_MKT_DEPTH = 10;
        //        const int CANCEL_MKT_DEPTH = 11;
        //        const int REQ_NEWS_BULLETINS = 12;
        //        const int CANCEL_NEWS_BULLETINS = 13;
        //        const int SET_SERVER_LOGLEVEL = 14;
        //        const int REQ_AUTO_OPEN_ORDERS = 15;
        //        const int REQ_ALL_OPEN_ORDERS = 16;
        //        const int REQ_MANAGED_ACCTS = 17;
        //        const int REQ_FA = 18;
        //        const int REPLACE_FA = 19;
        //        const int REQ_HISTORICAL_DATA = 20;
        //        const int EXERCISE_OPTIONS = 21;
        //        const int REQ_SCANNER_SUBSCRIPTION = 22;
        //        const int CANCEL_SCANNER_SUBSCRIPTION = 23;
        //        const int REQ_SCANNER_PARAMETERS = 24;
        //        const int CANCEL_HISTORICAL_DATA = 25;
        //        const int REQ_CURRENT_TIME = 49;
        //        const int REQ_REAL_TIME_BARS = 50;
        //        const int CANCEL_REAL_TIME_BARS = 51;
        //        const int REQ_FUNDAMENTAL_DATA = 52;
        //        const int CANCEL_FUNDAMENTAL_DATA = 53;
        //        const int REQ_CALC_IMPLIED_VOLAT = 54;
        //        const int REQ_CALC_OPTION_PRICE = 55;
        //        const int CANCEL_CALC_IMPLIED_VOLAT = 56;
        //        const int CANCEL_CALC_OPTION_PRICE = 57;
        //        const int REQ_GLOBAL_CANCEL = 58;
        //        const int REQ_MARKET_DATA_TYPE = 59;
        //
        //        //const int MIN_SERVER_VER_REAL_TIME_BARS       = 34;
        //        //const int MIN_SERVER_VER_SCALE_ORDERS         = 35;
        //        //const int MIN_SERVER_VER_SNAPSHOT_MKT_DATA    = 35;
        //        //const int MIN_SERVER_VER_SSHORT_COMBO_LEGS    = 35;
        //        //const int MIN_SERVER_VER_WHAT_IF_ORDERS       = 36;
        //        //const int MIN_SERVER_VER_CONTRACT_CONID       = 37;
        //        const int MIN_SERVER_VER_PTA_ORDERS = 39;
        //        const int MIN_SERVER_VER_FUNDAMENTAL_DATA = 40;
        //        const int MIN_SERVER_VER_UNDER_COMP = 40;
        //        const int MIN_SERVER_VER_CONTRACT_DATA_CHAIN = 40;
        //        const int MIN_SERVER_VER_SCALE_ORDERS2 = 40;
        //        const int MIN_SERVER_VER_ALGO_ORDERS = 41;
        //        const int MIN_SERVER_VER_EXECUTION_DATA_CHAIN = 42;
        //        const int MIN_SERVER_VER_NOT_HELD = 44;
        //        const int MIN_SERVER_VER_SEC_ID_TYPE = 45;
        //        const int MIN_SERVER_VER_PLACE_ORDER_CONID = 46;
        //        const int MIN_SERVER_VER_REQ_MKT_DATA_CONID = 47;
        //        const int MIN_SERVER_VER_REQ_CALC_IMPLIED_VOLAT = 49;
        //        const int MIN_SERVER_VER_REQ_CALC_OPTION_PRICE = 50;
        //        const int MIN_SERVER_VER_CANCEL_CALC_IMPLIED_VOLAT = 50;
        //        const int MIN_SERVER_VER_CANCEL_CALC_OPTION_PRICE = 50;
        //        const int MIN_SERVER_VER_SSHORTX_OLD = 51;
        //        const int MIN_SERVER_VER_SSHORTX = 52;
        //        const int MIN_SERVER_VER_REQ_GLOBAL_CANCEL = 53;
        //        const int MIN_SERVER_VER_HEDGE_ORDERS = 54;
        //        const int MIN_SERVER_VER_REQ_MARKET_DATA_TYPE = 55;
        //        const int MIN_SERVER_VER_OPT_OUT_SMART_ROUTING = 56;
        //        const int MIN_SERVER_VER_SMART_COMBO_ROUTING_PARAMS = 57;
        //        const int MIN_SERVER_VER_DELTA_NEUTRAL_CONID = 58;
        //
        //        // incoming msg id's
        //        const int TICK_PRICE = 1;
        //        const int TICK_SIZE = 2;
        //        const int ORDER_STATUS = 3;
        //        const int ERR_MSG = 4;
        //        const int OPEN_ORDER = 5;
        //        const int ACCT_VALUE = 6;
        //        const int PORTFOLIO_VALUE = 7;
        //        const int ACCT_UPDATE_TIME = 8;
        //        const int NEXT_VALID_ID = 9;
        //        const int CONTRACT_DATA = 10;
        //        const int EXECUTION_DATA = 11;
        //        const int MARKET_DEPTH = 12;
        //        const int MARKET_DEPTH_L2 = 13;
        //        const int NEWS_BULLETINS = 14;
        //        const int MANAGED_ACCTS = 15;
        //        const int RECEIVE_FA = 16;
        //        const int HISTORICAL_DATA = 17;
        //        const int BOND_CONTRACT_DATA = 18;
        //        const int SCANNER_PARAMETERS = 19;
        //        const int SCANNER_DATA = 20;
        //        const int TICK_OPTION_COMPUTATION = 21;
        //        const int TICK_GENERIC = 45;
        //        const int TICK_STRING = 46;
        //        const int TICK_EFP = 47;
        //        const int CURRENT_TIME = 49;
        //        const int REAL_TIME_BARS = 50;
        //        const int FUNDAMENTAL_DATA = 51;
        //        const int CONTRACT_DATA_END = 52;
        //        const int OPEN_ORDER_END = 53;
        //        const int ACCT_DOWNLOAD_END = 54;
        //        const int EXECUTION_DATA_END = 55;
        //        const int DELTA_NEUTRAL_VALIDATION = 56;
        //        const int TICK_SNAPSHOT_END = 57;
        //        const int MARKET_DATA_TYPE = 58;
        //
        //        // TWS New Bulletins constants
        //        const int NEWS_MSG = 1; // standard IB news bulleting message
        //        const int EXCHANGE_AVAIL_MSG = 2; // control message specifing that an exchange is available for trading
        //        const int EXCHANGE_UNAVAIL_MSG = 3; // control message specifing that an exchange is unavailable for trading
    };

    inline bool operator<(const Event& lhs, const Event& rhs) {
        return (int) lhs < (int) rhs;
    }

    struct ContractEvent : IB::Contract {
        Event event_;
        
        ContractEvent(){}
        ContractEvent(IB::Contract& c, IBAdditions::Event& e) : IB::Contract(c) {
            event_=e;
        }
        ContractEvent(const ContractEvent& ce){  
        }

        inline bool operator<(const ContractEvent & rhs) const {
            if(this->IB::Contract::operator <(rhs) == true) return true;
            if(rhs.::IB::Contract::operator <(*this) == true) return false;
            return (int)this->event_ < (int)rhs.event_;
        }
    };
    
    //Additions
class Record{
public:
    IB::TickType tickType_;
    Record(){}
    Record(IB::TickType tickType): tickType_(tickType){
        
    }
    virtual std::string getName(){return "Record";}
    virtual ~Record(){}
};

class TickPriceRecord : public Record{
public:
    std::string name;
    TickPriceRecord(IB::TickType tickType, double price, int canAutoExecute):
    Record(tickType), price_(price), canAutoExecute(canAutoExecute),name("TickPriceRecord"){
        
    }
    double price_;
    int canAutoExecute;
    std::string getName(){return name;}
};

class TickSizeRecord : public Record{
public:
    std::string name;
    TickSizeRecord(IB::TickType tickType, int size):
    Record(tickType), size_(size), name("TickSizeRecord"){
        
    }
    int size_;
    std::string getName(){return name;}    
};

class TickStringRecord : public Record{
public:
    std::string name;
    TickStringRecord(IB::TickType tickType, const std::string& string):
    Record(tickType), string(string), name("TickStringRecord"){
        
    }
    const std::string string;
    std::string getName(){return name;}    
};

class MktDepthRecord : public Record{
public:
    std::string name;
    MktDepthRecord(int position, int operation, int side, double price, int size):
    Record(IB::NOT_SET), position_(position), operation_(operation), side_(side),
    price_(price), size_(size), name("MktDepthRecord"){
        
    }
    int position_;
    int operation_;
    int side_;
    double price_;
    int size_;
    std::string getName(){return name;}    
};

class MktDepthL2Record : public Record{
public:
    std::string name;
    MktDepthL2Record(int position, IB::IBString marketMaker, int operation, int side, double price, int size):
    Record(IB::NOT_SET), position_(position), marketMaker_(marketMaker), operation_(operation), side_(side),
    price_(price), size_(size), name("MktDepthL2Record"){
        
    }
    int position_;
    IB::IBString marketMaker_;
    int operation_;
    int side_;
    double price_;
    int size_;
    std::string getName(){return name;}    
};

typedef boost::shared_ptr<IBAdditions::Record> rec_ptr;
typedef boost::shared_ptr<IBAdditions::TickPriceRecord> tickPriceRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickSizeRecord>  tickSizeRec_ptr;
typedef boost::shared_ptr<IBAdditions::TickStringRecord>  tickStringRec_ptr;
typedef boost::shared_ptr<IBAdditions::MktDepthRecord>  mktDepthRec_ptr;
typedef boost::shared_ptr<IBAdditions::MktDepthL2Record>  mktDepthL2Rec_ptr;

}

#endif	/* IB_EVENTS_H */

