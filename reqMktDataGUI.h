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

class reqMktDataGUI : public QDialog {
    Q_OBJECT
public:
    reqMktDataGUI(boost::shared_ptr<IB::PosixClient> client_ptr);
    virtual ~reqMktDataGUI();
public slots:
    void requestClicked();    
    void cancelClicked();  
private:
    Ui::reqMktDataGUI widget;
    boost::shared_ptr<IB::PosixClient> client;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickSizeObservers;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickPriceObservers;
    std::vector<boost::shared_ptr<MarketDataObserver> > tickStringObservers;
    void myTickPriceUpdate(int tickerId, rec_ptr record_ptr);
    void myTickSizeUpdate(int tickerId, rec_ptr record_ptr);
    void myTickStringUpdate(int tickerId, rec_ptr record_ptr);
};

#endif	/* _GUI_H */
