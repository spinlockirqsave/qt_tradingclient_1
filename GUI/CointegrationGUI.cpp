/* 
 * File:   CointegrationGUI.cpp
 * Author: Piotr Gregor  peter cf16 eu
 * 
 * Created on August 25, 2013, 4:31 AM
 */

#include "CointegrationGUI.h"

CointegrationGUI::CointegrationGUI() {
    
    widget_.setupUi(this);
    QObject::connect(widget_.pushButton_subscribe, SIGNAL(clicked()), this, SLOT(subscribeClicked()));
    //this->setAttribute(Qt::WA_DeleteOnClose);
}

void CointegrationGUI::subscribeClicked() {
    subscribeToDataGUI_ptr_.push_back(boost::shared_ptr<SubscribeToDataGUI>(new SubscribeToDataGUI(this)));
    subscribeToDataGUI_ptr_.back()->show();
    QObject::connect(subscribeToDataGUI_ptr_.back().get(), SIGNAL(accepted()), this, SLOT(subscribeToData()));
}

void CointegrationGUI::subscribeToData() {
    
}

