/*
 * File:   main.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 5:59 PM
 */
#include "PosixClient.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include "GUI.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);
    app.setStyleSheet("QMenu::item:selected {border: 1px solid blue;}");
    // create and show your widgets here
    cf16tradingclient_1 cf16;
    cf16.show();
    
    return app.exec();
}
