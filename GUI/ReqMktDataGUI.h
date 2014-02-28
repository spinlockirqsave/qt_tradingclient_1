/* 
 * File:   ReqMktData.h
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#ifndef _MktDataGUI_H
#define	_MktDataGUI_H

#include "ui_ReqMktDataGUI.h"
#include <DataAccessLayer/PosixClient.h>
#include <DataAccessLayer/MarketData.h>
#include <DataAccessLayer/globals.h>
#include <GUI/GUIMarketData.h>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>


void processMessages();
void endProcessMessages();
void processMessages2();
void processMessages3();

class ReqMktDataGUI : public QDialog {
    Q_OBJECT
public:
    ReqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr, QWidget* parent=0);
    virtual ~ReqMktDataGUI();
    static int totalGUIReqActive;
    
public slots:
    void requestClicked();    
    void cancelClicked();
    void guiRequestClicked();
    void displayData(int tickerId, rec_ptr record_ptr);
    void myTickSizeGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickPriceGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringGUIUpdate(int tickerId, rec_ptr record_ptr);
Q_SIGNALS:
    void newMktData(int tickerId, rec_ptr record_ptr);

private:
    Ui::reqMktDataGUI widget_;
    boost::shared_ptr<IB::PosixClient> client_;
    
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers_;
    std::vector<pMktDataObserver> tickPriceObservers_;
    std::vector<pMktDataObserver> tickStringObservers_;
    
    void myTickPriceUpdate(int tickerId, rec_ptr record_ptr);
    void myTickSizeUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringUpdate(int tickerId, rec_ptr record_ptr);
    
    void marketDataFeedDelete(void);
    void guiMarketDataFeedDelete(void);
    
    std::map<int, IB::Contract> observedContracts_;
    std::map<int, IB::Contract> guiObservedContracts_;
    bool thisGUIReqActive_;
};
typedef std::map<int, IB::Contract> tickerIdContractMap;
typedef std::map<int, boost::shared_ptr<IB::Contract> > tickerIdContractPtrMap;
typedef std::vector<boost::shared_ptr<MarketDataObserver> >::iterator vecPmktDataObsIt;

#endif	/* _GUI_H */
