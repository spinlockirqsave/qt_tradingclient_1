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
#include <errno.h>

#define NUM_THREADS	1
pthread_t thread[NUM_THREADS];
pthread_mutex_t mxq; /* mutex used as quit flag */

/* Returns 1 (true) if the mutex is unlocked, which is the
 * thread's signal to terminate. 
 */
int needQuit(pthread_mutex_t *mtx)
{
  switch(pthread_mutex_trylock(mtx)) {
    case 0: /* if we got the lock, unlock and return 1 (true) */
      pthread_mutex_unlock(mtx);
      return 1;
    case EBUSY: /* return 0 (false) if the mutex was locked */
      return 0;
  }
  return 1;
}

boost::shared_ptr<IB::PosixClient> client(new IB::PosixClient);

/* Thread function, containing a loop that's infinite except that it checks for
 * termination with needQuit() 
 */
void* processMessages(void* t){
    pthread_mutex_t *mx = (pthread_mutex_t *)t;
    while(!needQuit(mx)){
        client->processMessages();
    }
    return NULL;
}

void processMessages(){
    pthread_attr_t attr;
    //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    int rc;
    
    pthread_mutex_init(&mxq,NULL);
    pthread_mutex_lock(&mxq);

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    printf("global::processMessages: creating thread\n");
      rc = pthread_create(&thread[0], &attr, ::processMessages, &mxq); 
      if (rc) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
         }
}

void endProcessMessages(){
    /* unlock mxq to tell the process messages thread to terminate, then join the thread */
    pthread_mutex_unlock(&mxq); 
    pthread_join(thread[0],NULL);
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
