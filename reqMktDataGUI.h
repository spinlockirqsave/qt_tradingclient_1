/* 
 * File:   GUI.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#ifndef _GUI_H
#define	_GUI_H

#include "ui_reqMktDataGUI.h"
#include "PosixClient.h"
#include "MarketData.h"
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>


void processMessages();
void endProcessMessages();
void processMessages2();
void processMessages3();

class reqMktDataGUI : public QDialog {
    Q_OBJECT
public:
    reqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr);
    virtual ~reqMktDataGUI();
public slots:
    void requestClicked();    
    void cancelClicked();
    void displayData(int tickerId, rec_ptr record_ptr);
Q_SIGNALS:
    void newMktData(int tickerId, rec_ptr record_ptr);
private:
    Ui::reqMktDataGUI widget;
    boost::shared_ptr<IB::PosixClient> client;
    
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickPriceObservers;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickStringObservers;
    
    void myTickPriceUpdate(int tickerId, rec_ptr record_ptr);
    void myTickSizeUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringUpdate(int tickerId, rec_ptr record_ptr);
    
    void marketDataFeedDelete(void);
    
    std::vector<IB::Contract> observedContracts;
};

#endif	/* _GUI_H */
