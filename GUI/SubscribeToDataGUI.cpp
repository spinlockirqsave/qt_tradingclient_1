/* 
 * File:   SubscribeToData.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on September 10, 2013, 2:30 AM
 */

#include "SubscribeToDataGUI.h"

SubscribeToDataGUI::SubscribeToDataGUI(QWidget* parent) : QDialog(parent) {
    availableTickers_ = std::vector<IBAdditions::ContractEvent>(3);
    model_.reset(new TickerDisplayModel(availableTickers_));
}

SubscribeToDataGUI::SubscribeToDataGUI(const SubscribeToDataGUI& orig) {
}

SubscribeToDataGUI::~SubscribeToDataGUI() {
}

