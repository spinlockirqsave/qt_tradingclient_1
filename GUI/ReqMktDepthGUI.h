/* 
 * File:   GUI.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on June 28, 2013, 6:57 PM
 */

#ifndef _MktDepthGUI_H
#define	_MktDepthGUI_H

#include "ui_reqMktDepthGUI.h"
#include <DataAccessLayer/PosixClient.h>
#include <DataAccessLayer/MarketData.h>
#include <GUI/GUIMarketData.h>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <IBAdditions/IB_events.h>

void processMessages();
void endProcessMessages();
void processMessages2();
void processMessages3();

class ReqMktDepthGUI : public QDialog {
    Q_OBJECT
public:
    ReqMktDepthGUI(boost::shared_ptr<IB::PosixClient> client_ptr);
    virtual ~ReqMktDepthGUI();
    static int totalGUIReqActive;
public slots:
    void requestClicked();    
    void cancelClicked();
    void guiRequestClicked();
    void displayData(int tickerId, rec_ptr record_ptr);
    void myTickSizeGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickPriceGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringGUIUpdate(int tickerId, rec_ptr record_ptr);
    void myMarketDepthGUIUpdate(int tickerId, rec_ptr recor_ptr);
    void myMarketDepthL2GUIUpdate(int tickerId, rec_ptr recor_ptr);
Q_SIGNALS:
    void newMktDepth(int tickerId, rec_ptr record_ptr);

private:
    Ui::reqMktDepthGUI widget;
    boost::shared_ptr<IB::PosixClient> client;
    
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers;
    std::vector<pMktDataObserver> tickPriceObservers;
    std::vector<pMktDataObserver> tickStringObservers;
    
    void myTickPriceUpdate(int tickerId, rec_ptr record_ptr);
    void myTickSizeUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringUpdate(int tickerId, rec_ptr record_ptr);
    
    void marketDataFeedDelete(void);
    void guiMarketDataFeedDelete(void);
    
    std::vector<IB::Contract> observedContracts;
    std::map<int, boost::shared_ptr<IB::Contract> > guiObservedContracts;
    bool thisGUIReqActive;
};
typedef std::map<int, boost::shared_ptr<IB::Contract> > tickerIdContractPtrMap;
typedef std::vector<boost::shared_ptr<MarketDataObserver> >::iterator vecPmktDataObsIt;

#endif	/* _GUI_H */
