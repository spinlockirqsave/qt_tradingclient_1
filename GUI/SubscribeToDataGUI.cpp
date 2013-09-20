/* 
 * File:   SubscribeToData.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on September 10, 2013, 2:30 AM
 */

#include "SubscribeToDataGUI.h"

SubscribeToDataGUI::SubscribeToDataGUI(QWidget* parent) : QDialog(parent) {
    widget_.setupUi(this);
    IBAdditions::ContractEvent c;
    c.symbol = "EUR"; c.currency = "USD"; c.event_ = IBAdditions::TickPrice;
    availableTickers_.push_back(c);
    model_.reset(new TickerDisplayModel(availableTickers_));
    widget_.tableView->setModel(model_.get());
    widget_.tableView->show();
}

SubscribeToDataGUI::SubscribeToDataGUI(const SubscribeToDataGUI& orig) {
}

SubscribeToDataGUI::~SubscribeToDataGUI() {
}

