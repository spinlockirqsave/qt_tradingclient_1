/* 
 * File:   SubscribeToData.cpp
 * Author: Piotr Gregor  piter cf16 eu
 * 
 * Created on September 10, 2013, 2:30 AM
 */

#include "SubscribeToDataGUI.h"

/**
 * 
 * @param parent
 */
SubscribeToDataGUI::SubscribeToDataGUI(QWidget* parent) : QDialog(parent),
availableTickers_(marketDataRepository.availableTickers()) {
    widget_.setupUi(this);
//    IBAdditions::ContractEvent c;
//    c.symbol = "EUR"; c.currency = "USD"; c.event_ = IBAdditions::TickPrice;
//    IBAdditions::ContractEvent d;
//    d.symbol = "EUR"; d.currency = "GBP"; d.event_ = IBAdditions::TickSize;
//    availableTickers_.push_back(c);
//    availableTickers_.push_back(d);
    model_.reset(new TickerDisplayModel(availableTickers_));
    widget_.tableView->setModel(model_.get());
    widget_.tableView->show();
}

SubscribeToDataGUI::SubscribeToDataGUI(const SubscribeToDataGUI& orig) : QDialog() {
}

SubscribeToDataGUI::~SubscribeToDataGUI() {
}

