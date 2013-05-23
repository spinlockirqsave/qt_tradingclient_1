/*
 * File:   GUI.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 8:36 PM
 */

#include "GUI.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
GUI::GUI():host(""),port(7496),clientId(0) {
    widget.setupUi(this);
    QObject::connect(widget.pushButton_1, SIGNAL(clicked()), this, SLOT(connectClicked()));
}

GUI::~GUI() {
}

//public slots
void GUI::connectClicked(){
    client.connect(host,port,clientId);
    QMessageBox::information(this,"Button clicked!\n", "Warning");
}  
