/* 
 * File:   CointegrationGUI.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on August 25, 2013, 4:31 AM
 */

#include "CointegrationGUI.h"

CointegrationGUI::CointegrationGUI() {
    
    widget_.setupUi(this);
    QObject::connect(widget_.pushButton_subscribe, SIGNAL(clicked()), this, SLOT(subscribeClicked()));
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void CointegrationGUI::subscribeClicked(){
    
}


