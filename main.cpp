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

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);

    // create and show your widgets here
    GUI gui;
    gui.show();
    
    
    return app.exec();
}
