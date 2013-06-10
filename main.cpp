/*
 * File:   main.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 22, 2013, 5:59 PM
 */
#include "PosixClient.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include "MainWindow.h"
#include "reqMktDataGUI.h"
#include <boost/shared_ptr.hpp>
#include <pthread.h>

#define NUM_THREADS	1
pthread_t thread[NUM_THREADS];
boost::shared_ptr<IB::PosixClient> client(new IB::PosixClient);

void* processMessages(void* t){
    while(true){
        client->processMessages();
    }
}

void processMessages(){
    pthread_attr_t attr;
    int rc;
    long t=0;

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    printf("global::processMessages: creating thread %ld\n", t);
      rc = pthread_create(&thread[t], &attr, ::processMessages, (void *)t); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
         }
}


int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);
    app.setStyleSheet("QMenu::item:selected {border: 1px solid blue;}");
      
    // create QMainWindow::QWidget and show it
    cf16tradingclient_1 cf16(client);    
    cf16.show();
    
    return app.exec();
}
