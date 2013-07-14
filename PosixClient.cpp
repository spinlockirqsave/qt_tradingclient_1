/*
 * File:   PosixClient.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#include "PosixClient.h"

#include "EPosixClientSocket.h"
/* In this example we just include the platform header to have select(). In real
   life you should include the needed headers from your system. */
#include "EPosixClientSocketPlatform.h"

#include "Contract.h"
#include "Order.h"

#include <time.h>
#include <sys/time.h>
#include <EClientSocketBase.h>

#if defined __INTEL_COMPILER
# pragma warning (disable:869)
#elif defined __GNUC__
# pragma GCC diagnostic ignored "-Wswitch"
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif  /* __INTEL_COMPILER */

namespace IB {

const int PING_DEADLINE = 2; // seconds
const int SLEEP_BETWEEN_PINGS = 30; // seconds

///////////////////////////////////////////////////////////
// member funcs
PosixClient::PosixClient()
	: m_pClient(new EPosixClientSocket(this))
	, m_state(ST_CONNECT)
	, m_sleepDeadline(0)
	, m_orderId(0)
{
}

PosixClient::~PosixClient()
{
}

bool PosixClient::connect(const char *host, unsigned int port, int clientId)
{
	// trying to connect
	printf( "PosixClient: connecting to %s:%u clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	bool bRes = m_pClient->eConnect2( host, port, clientId);

	if (bRes) {
		printf( "PosixClient: connected to %s:%u clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);
	}
	else
		printf( "PosixClient: cannot connect to %s:%u clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	return bRes;
}

void PosixClient::disconnect() const
{
	m_pClient->eDisconnect();

	printf ( "PosixClient::disconnect Disconnected\n");
}

bool PosixClient::isConnected() const
{
	return m_pClient->isConnected();
}

void PosixClient::processMessages()
{
	fd_set readSet, writeSet;

	struct timeval tval;
	tval.tv_usec = 0;
	tval.tv_sec = 0;

	time_t now = time(NULL);

//	switch (m_state) {
//		case ST_PLACEORDER:
//			//placeOrder_MSFT();
//                    printf("PosixClient: ST_PLACEORDER\n");
//                    //reqMktData_MSFT();
//			break;
//		case ST_PLACEORDER_ACK:
//                        printf("PosixClient: ST_PLACEORDER_ACK\n");
//                        //reqMktData_MSFT();
//			break;
//		case ST_CANCELORDER:
//                        printf("PosixClient: ST_CANCELORDER\n");
//			//cancelOrder();
//			break;
//		case ST_CANCELORDER_ACK:
//                        printf("PosixClient: ST_CANCELORDER_ACK\n");
//			break;
//                case ST_REQMKTDATA:
//                        printf("PosixClient: ST_REQMKTDATA\n");
//			//cancelOrder();
//			break;
//		case ST_REQMKTDATA_ACK:
//                        //printf("PosixClient: ST_REQMKTDATA_ACK\n");
//			break;        
//		case ST_PING:
//			printf("PosixClient: ST_PING\n");
//                        //reqCurrentTime();
//			break;
//		case ST_PING_ACK:
//                        printf("PosixClient: ST_PING_ACK\n");
//			if( m_sleepDeadline < now) {
//				disconnect();
//				return;
//			}
//			break;
//		case ST_IDLE:
//                        printf("PosixClient: ST_IDLE\n");
//			if( m_sleepDeadline < now) {
//				m_state = ST_PING;
//				return;
//			}
//			break;
//	}

	if( m_sleepDeadline > 0) {
		// initialize timeout with m_sleepDeadline - now
                printf("PosixClient::processMessages: m_sleepDeadline\n");
		tval.tv_sec = m_sleepDeadline - now;
	}

	if( m_pClient->fd() >= 0 ) {

		FD_ZERO( &readSet);
		writeSet = readSet;

		FD_SET( m_pClient->fd(), &readSet);

		if( !m_pClient->isOutBufferEmpty())
			FD_SET( m_pClient->fd(), &writeSet);

		int ret = select( m_pClient->fd() + 1, &readSet, &writeSet, NULL, &tval);

		if( ret == 0) { // timeout
                        //printf("PosixClient::processMessages: timeout\n");
			return;
		}

		if( ret < 0) {	// error
                        printf("PosixClient::processMessages: disconnect\n");
			disconnect();
			return;
		}

		if( FD_ISSET( m_pClient->fd(), &writeSet)) {
			// socket is ready for writing
                        printf("PosixClient::processMessages: onSend\n");
			m_pClient->onSend();
		}

		if( m_pClient->fd() < 0)
			return;

		if( FD_ISSET( m_pClient->fd(), &readSet)) {
			// socket is ready for reading
                        printf("PosixClient::processMessages: onReceive\n");
			m_pClient->onReceive();
		}
	}
}

//////////////////////////////////////////////////////////////////
// methods
void PosixClient::reqCurrentTime(){
	printf( "--> Requesting Current Time2\n");

	// set ping deadline to "now + n seconds"
	m_sleepDeadline = time( NULL) + PING_DEADLINE;

	m_state = ST_PING_ACK;

	m_pClient->reqCurrentTime();
}

void PosixClient::placeOrder_MSFT(){
	Contract contract;
	Order order;
	contract.symbol = "MSFT";
	contract.secType = "STK";
	contract.exchange = "SMART";
	contract.currency = "USD";
	order.action = "BUY";
	order.totalQuantity = 1000;
	order.orderType = "LMT";
	order.lmtPrice = 26.7;

	printf( "PosixClient: Placing Order %ld: %s %ld %s at %f\n", m_orderId, order.action.c_str(), order.totalQuantity, contract.symbol.c_str(), order.lmtPrice);

	m_state = ST_PLACEORDER_ACK;
	m_pClient->placeOrder( m_orderId, contract, order);
}

void PosixClient::reqMktData_MSFT(){
    	Contract contract;
	Order order;

	contract.symbol = "MSFT";
	contract.secType = "STK";
	contract.exchange = "SMART";
	contract.currency = "USD";

	printf( "PosixClient: Requesting MSFT mktData %ld: %s %ld %s at %f\n", m_orderId, order.action.c_str(), order.totalQuantity, contract.symbol.c_str(), order.lmtPrice);

	//m_state = ST_REQMKTDATA_ACK;
        IBString i="233";
	m_pClient->reqMktData( 100, contract, i, false);
}

void PosixClient::reqMktData(IBString symbol, IBString secType,
        IBString exchange, IBString currency, int tickerId, IBString genericTicks, IBString localSymbol, bool snapshot){
    	Contract contract;

	contract.symbol = symbol;
	contract.secType = secType;
	contract.exchange = exchange;//"SMART";//exchange;
	contract.currency = currency;
        contract.localSymbol = localSymbol;

	printf( "PosixClient: Requesting mktData. symbol: %s secType: %s  exchange: %s  currency: %s\n",
                contract.symbol.c_str(), contract.secType.c_str(), contract.exchange.c_str(),
                contract.currency.c_str());

	m_state = ST_REQMKTDATA_ACK;
	m_pClient->reqMktData( tickerId, contract, genericTicks, snapshot);
    }

void PosixClient::reqMktDepth(TickerId tickerId, boost::shared_ptr<Contract> contract, int numRows){
    m_pClient->reqMktDepth(tickerId, *contract, numRows);
}

    void PosixClient::marketDataFeedInsert(boost::shared_ptr<MarketData> marketData) {
        IB::Event event = marketData->getEvent();
        switch (event) {
            case IB::TickSize: 
                tickSizeMarketDataFeed.insert(std::pair<int, pMktDataObservable > (marketData->getTickerId(), marketData));
                break;
            case IB::TickPrice: 
                tickPriceMarketDataFeed.insert(std::pair<int, pMktDataObservable > (marketData->getTickerId(), marketData));
                break;
            case IB::TickString: 
                tickStringMarketDataFeed.insert(std::pair<int, pMktDataObservable > (marketData->getTickerId(), marketData));
                break;
            default:
                break;
        }
    }
    
    void PosixClient::guiMarketDataFeedInsert(boost::shared_ptr<GUIMarketData> guiMarketData) {
        IB::Event event = guiMarketData->getEvent();
        switch (event) {
            case IB::TickSize: 
                tickSizeGUIMarketDataFeed.insert(std::pair<int, pGUIMktData > (guiMarketData->getTickerId(), guiMarketData));
                break;
            case IB::TickPrice: 
                tickPriceGUIMarketDataFeed.insert(std::pair<int, pGUIMktData > (guiMarketData->getTickerId(), guiMarketData));
                break;
            case IB::TickString: 
                tickStringGUIMarketDataFeed.insert(std::pair<int, pGUIMktData > (guiMarketData->getTickerId(), guiMarketData));
                break;
            case IB::MarketDepth:
                updateMktDepthGUIMarketDataFeed.insert(std::pair<int, pGUIMktData > (guiMarketData->getTickerId(), guiMarketData));
                break;
            case IB::MarketDepthL2:
                updateMktDepthL2GUIMarketDataFeed.insert(std::pair<int, pGUIMktData > (guiMarketData->getTickerId(), guiMarketData));
                break;                
            default:
                break;
        }
    }

void PosixClient::cancelOrder()
{
	printf( "Cancelling Order %ld\n", m_orderId);

	m_state = ST_CANCELORDER_ACK;

	m_pClient->cancelOrder( m_orderId);
}

void PosixClient::cancelMktData(TickerId tickerId){
    printf( "PosixClient::cancelMktData for tickerId: %d\n",tickerId);
    m_pClient->cancelMktData(tickerId);
}

///////////////////////////////////////////////////////////////////
// events
void PosixClient::orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld)

{
	if( orderId == m_orderId) {
		if( m_state == ST_PLACEORDER_ACK && (status == "PreSubmitted" || status == "Submitted"))
			m_state = ST_CANCELORDER;

		if( m_state == ST_CANCELORDER_ACK && status == "Cancelled")
			m_state = ST_PING;

		printf( "Order: id=%ld, status=%s\n", orderId, status.c_str());
	}
}

void PosixClient::nextValidId( OrderId orderId)
{
	m_orderId = orderId;

	m_state = ST_PLACEORDER;
}

void PosixClient::currentTime( long time)
{
	if ( m_state == ST_PING_ACK) {
		time_t t = ( time_t)time;
		struct tm * timeinfo = localtime ( &t);
		printf( "The current date/time is: %s", asctime( timeinfo));

		time_t now = ::time(NULL);
		m_sleepDeadline = now + SLEEP_BETWEEN_PINGS;

		m_state = ST_IDLE;
	}
}

void PosixClient::error(const int id, const int errorCode, const IBString errorString)
{
	printf( "Error id=%d, errorCode=%d, msg=%s\n", id, errorCode, errorString.c_str());

	if( id == -1 && errorCode == 1100) // if "Connectivity between IB and TWS has been lost"
		disconnect();
}

void PosixClient::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute) {
#ifdef DEBUG
    printf("PosixClient::tickPrice \n");
#endif
    tickerIdMarketDataMap::iterator it=tickPriceMarketDataFeed.find(tickerId);
        if(it!=tickPriceMarketDataFeed.end()){
            //(*it)->tickPriceData.push_back(TickPriceRecord(field,price,canAutoExecute));
            //printf("PosixClient: putRecord \n");
            ((*it).second)->putRecord(tickPriceRec_ptr(new TickPriceRecord(field,price,canAutoExecute))); //what thread r MarketData objects?
            //printf("PosixClient: notify \n");
            ((*it).second)->notifyObservers(); // observers are in the main thread
            //printf("PosixClient: notifyOK \n");
            //TODO: start thread to store incoming data in repository
        }
    
    tickerIdGUIMarketDataMap::iterator it2=tickPriceGUIMarketDataFeed.find(tickerId);
        if(it2!=tickPriceGUIMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient::tickPrice: putRecord to GUIMarketData object \n");
            (*it2).second->putRecord(tickPriceRec_ptr(new TickPriceRecord(field,price,canAutoExecute)));
            //printf("PosixClient::tickPrice: GUIMarketData->notifyObservers \n");
            (*it2).second->notifyObservers();
            //printf("PosixClient::tickPrice: GUIMarketData notifyOK \n");
            //TODO: start thread to store incoming data in repository
            (*it2).second->saveRecord();
        }
}
void PosixClient::tickSize( TickerId tickerId, TickType field, int size) {
#ifdef DEBUG 
    printf("PosixClient::tickSize\n");
#endif
    tickerIdMarketDataMap::iterator it=tickSizeMarketDataFeed.find(tickerId);
        if(it!=tickSizeMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient::tickSize: putRecord \n");
            ((*it).second)->putRecord(tickSizeRec_ptr(new TickSizeRecord(field,size)));
            //printf("PosixClient::tickSize: notify \n");
            ((*it).second)->notifyObservers();
            //printf("PosixClient::tickSize: notifyOK \n");
            //TODO: start thread to store incoming data in repository
        }
    
    tickerIdGUIMarketDataMap::iterator it2=tickSizeGUIMarketDataFeed.find(tickerId);
        if(it2!=tickSizeGUIMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient: putRecord to GUIMarketData object \n");
            (*it2).second->putRecord(tickSizeRec_ptr(new TickSizeRecord(field,size)));
            //printf("PosixClient: GUIMarketData->notifyObservers \n");
            (*it2).second->notifyObservers();
            //printf("PosixClient: GUIMarketData notifyOK \n");
            //TODO: start thread to store incoming data in repository
            (*it2).second->saveRecord();
        }
}
void PosixClient::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
											 double optPrice, double pvDividend,
											 double gamma, double vega, double theta, double undPrice) {
    #ifdef DEBUG 
         printf("PosixClient::tickOptionComputation\n");
    #endif
}
void PosixClient::tickGeneric(TickerId tickerId, TickType tickType, double value) {
    #ifdef DEBUG 
         printf("PosixClient::tickGeneric\n");
    #endif
}
void PosixClient::tickString(TickerId tickerId, TickType field, const IBString& value) {
    #ifdef DEBUG 
    printf("PosixClient::tickString\n");
#endif
    tickerIdMarketDataMap::iterator it=tickStringMarketDataFeed.find(tickerId);
        if(it!=tickStringMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient: putRecord \n");
            ((*it).second)->putRecord(tickStringRec_ptr(new TickStringRecord(field,value)));
            //printf("PosixClient: notify \n");
            ((*it).second)->notifyObservers();
            //printf("PosixClient: notifyOK \n");
            //TODO: start thread to store incoming data in repository
        }
    
    tickerIdGUIMarketDataMap::iterator it2=tickStringGUIMarketDataFeed.find(tickerId);
        if(it2!=tickStringGUIMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient: putRecord \n");
            (*it2).second->putRecord(tickStringRec_ptr(new TickStringRecord(field,value)));
            //printf("PosixClient: notify \n");
            (*it2).second->notifyObservers();
            //printf("PosixClient: notifyOK \n");
            //TODO: start thread to store incoming data in repository
            (*it2).second->saveRecord();
        }
    //printf("tickerId: %lu, TickType: %d, value: %s\n", tickerId, tickType, value.c_str());
}
void PosixClient::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
							   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) {
    #ifdef DEBUG 
        printf("PosixClient::tickEFP\n");
    #endif
}
void PosixClient::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState& ostate) {
    #ifdef DEBUG 
    printf("PosixClient::openOrder\n");
    #endif
}
void PosixClient::openOrderEnd() {    
    #ifdef DEBUG 
    printf("PosixClient::openOrderEnd\n"); 
    #endif
}
void PosixClient::winError( const IBString &str, int lastError) {
    #ifdef DEBUG 
    printf("PosixClient::winError\n");
    #endif
}
void PosixClient::connectionClosed() {
    #ifdef DEBUG 
    printf("PosixClient::connectionClosed\n");
    #endif
}
void PosixClient::updateAccountValue(const IBString& key, const IBString& val,
										  const IBString& currency, const IBString& accountName) {
    #ifdef DEBUG 
    printf("PosixClient::updateAccountValue\n");
    #endif
}
void PosixClient::updatePortfolio(const Contract& contract, int position,
		double marketPrice, double marketValue, double averageCost,
		double unrealizedPNL, double realizedPNL, const IBString& accountName){
    #ifdef DEBUG 
    printf("PosixClient::updatePortfolio\n");
    #endif
}
void PosixClient::updateAccountTime(const IBString& timeStamp) {
    #ifdef DEBUG 
    printf("PosixClient::updateAccountTime\n");
    #endif
}
void PosixClient::accountDownloadEnd(const IBString& accountName) {
    #ifdef DEBUG 
    printf("PosixClient::accountDownloadEnd\n");
    #endif
}
void PosixClient::contractDetails( int reqId, const ContractDetails& contractDetails) {
    #ifdef DEBUG 
    printf("PosixClient::contractDetails\n");
    #endif
}
void PosixClient::bondContractDetails( int reqId, const ContractDetails& contractDetails) {
    #ifdef DEBUG 
    printf("PosixClient::bondContractDetails\n");
    #endif
}
void PosixClient::contractDetailsEnd( int reqId) {
    #ifdef DEBUG 
    printf("PosixClient::contractDetailsEnd\n");
    #endif
}
void PosixClient::execDetails( int reqId, const Contract& contract, const Execution& execution) {
    #ifdef DEBUG 
    printf("PosixClient::execDetails\n");
    #endif
}
void PosixClient::execDetailsEnd( int reqId) {
    #ifdef DEBUG 
    printf("PosixClient::execDetailsEnd\n");
    #endif
}

void PosixClient::updateMktDepth(TickerId id, int position, int operation, int side,
									  double price, int size) {
    #ifdef DEBUG 
    printf("PosixClient::updateMktDepth\n");
    #endif
    tickerIdGUIMarketDataMap::iterator it=updateMktDepthGUIMarketDataFeed.find(id);
        if(it!=updateMktDepthGUIMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient: putRecord \n");
            ((*it).second)->putRecord(rec_ptr(new MktDepthRecord(position,operation,side,price,size)));
            //printf("PosixClient: notify \n");
            ((*it).second)->notifyObservers();
            //printf("PosixClient: notifyOK \n");
            //TODO: start thread to store incoming data in repository
        }
}
void PosixClient::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
										int side, double price, int size) {
    #ifdef DEBUG 
    printf("PosixClient::updateMktDepthL2\n");
    #endif
    tickerIdGUIMarketDataMap::iterator it=updateMktDepthL2GUIMarketDataFeed.find(id);
        if(it!=updateMktDepthL2GUIMarketDataFeed.end()){
            //(*it)->tickSizeData.push_back(TickSizeRecord(field,size));
            //printf("PosixClient: putRecord \n");
            ((*it).second)->putRecord(rec_ptr(new MktDepthL2Record(position,marketMaker,operation,side,price,size)));
            //printf("PosixClient: notify \n");
            ((*it).second)->notifyObservers();
            //printf("PosixClient: notifyOK \n");
            //TODO: start thread to store incoming data in repository
        }
}

void PosixClient::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) {
    #ifdef DEBUG 
    printf("PosixClient::updateNewsBulletin\n");
    #endif
}
void PosixClient::managedAccounts( const IBString& accountsList) {
    #ifdef DEBUG 
    printf("PosixClient::managedAccounts\n");
    #endif
}
void PosixClient::receiveFA(faDataType pFaDataType, const IBString& cxml) {
    #ifdef DEBUG 
    printf("PosixClient::receiveFA\n");
    #endif
}
void PosixClient::historicalData(TickerId reqId, const IBString& date, double open, double high,
									  double low, double close, int volume, int barCount, double WAP, int hasGaps) {
    #ifdef DEBUG 
    printf("PosixClient::historicalData\n");
    #endif
}
void PosixClient::scannerParameters(const IBString &xml) {
    #ifdef DEBUG 
    printf("PosixClient::scannerParameters\n");
    #endif
}
void PosixClient::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) {
    #ifdef DEBUG 
    printf("PosixClient::scannerData\n");
    #endif
}
void PosixClient::scannerDataEnd(int reqId) {
    #ifdef DEBUG 
    printf("PosixClient::scannerDataEnd\n");
    #endif
}
void PosixClient::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
								   long volume, double wap, int count) {
    #ifdef DEBUG 
    printf("PosixClient::realtimeBar\n");
    #endif
}
void PosixClient::fundamentalData(TickerId reqId, const IBString& data) {
    #ifdef DEBUG 
    printf("PosixClient::fundamentalData\n");
    #endif
}
void PosixClient::deltaNeutralValidation(int reqId, const UnderComp& underComp) {
    #ifdef DEBUG 
    printf("PosixClient::deltaNeutralValidation\n");
    #endif
}
void PosixClient::tickSnapshotEnd(int reqId) {
    #ifdef DEBUG 
    printf("PosixClient::tickSnapshotEnd\n");
    #endif
}
void PosixClient::marketDataType(TickerId reqId, int marketDataType) {
    #ifdef DEBUG 
    printf("PosixClient::marketDataType\n");
    #endif
}

}
