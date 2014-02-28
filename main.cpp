/*
 * File:   main.cpp
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on May 22, 2013, 5:59 PM
 */

#include <DataAccessLayer/globals.h>

#include <DataAccessLayer/PosixClient.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <DataAccessLayer/ProcessMsgClass.h>
#include <DataAccessLayer/Repository.h>
#include <GUI/GUIMarketData.h>
#include <GUI/MainWindow.h>
#include <GUI/ReqMktDataGUI.h>
#include <GUI/ReqMktDepthGUI.h>

#include <boost/shared_ptr.hpp>
#include <pthread.h>
#include <errno.h>


// initialize global data
boost::shared_ptr<IB::PosixClient> client;
Repository marketDataRepository;

pthread_mutex_t repoMutexes[NUM_REPOTHREADS];
pthread_cond_t repoConditions[NUM_REPOTHREADS];
pthread_attr_t repoAttr;

/**
 * initialize mutexes that protect Repository vectors
 */
void init_repoMutexes() {
    for (int i = 0; i < NUM_REPOTHREADS; i++) {
        pthread_mutex_init(&repoMutexes[i], NULL);
        pthread_cond_init(&repoConditions[i], NULL);
    }
}

void destroy_repoMutexes() {
    for (int i = 0; i < NUM_REPOTHREADS; i++) {
        pthread_mutex_destroy(&repoMutexes[i]);
        pthread_cond_destroy(&repoConditions[i]);
    }
}

// initialize static members
int ReqMktDataGUI::totalGUIReqActive = 0;
int ReqMktDepthGUI::totalGUIReqActive = 0;

#define NUM_THREADS	1
pthread_t thread[NUM_THREADS];
pthread_mutex_t continue_mutex; /* mutex used for processMessages as quit flag */
pthread_attr_t attr;
pthread_mutex_t client_mutex; /* mutex used for processMessages to avoid segmentation fault */

/* Returns 1 (true) if the mutex is unlocked, which is the
 * thread's signal to terminate. 
 */
int needQuit(pthread_mutex_t *mtx) {
    switch (pthread_mutex_trylock(mtx)) {
        case 0: /* if we got the lock, unlock and return 1 (true) */
            pthread_mutex_unlock(mtx);
            return 1;
        case EBUSY: /* return 0 (false) if the mutex was locked */
            return 0;
    }
    return 1;
}

/* Thread function containing a loop that's infinite except that it checks for
 * termination with needQuit() 
 */
void* processMessages(void* t) {
    pthread_mutex_t *mx = (pthread_mutex_t *) t;
    while (!needQuit(mx)) {
        pthread_mutex_lock(&client_mutex); // avoid segmentation fault
        client->processMessages();
        pthread_mutex_unlock(&client_mutex);
    }
    //pthread_exit(NULL);
    return NULL;
}

void processMessages() {
    //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    int rc;

    pthread_mutex_init(&continue_mutex, NULL);
    pthread_mutex_lock(&continue_mutex);

    pthread_mutex_init(&client_mutex, NULL);
    
    init_repoMutexes();

    /* Initialize and set thread detached attribute */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    printf("global::processMessages: creating thread !\n");
    rc = pthread_create(&thread[0], &attr, ::processMessages, &continue_mutex);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
}

void processMessages2() {
    client->processMessages();
}

void endProcessMessages() {
    /* unlock mxq to tell the processMessages thread to terminate, then join the thread */
    pthread_mutex_unlock(&continue_mutex);
    pthread_join(thread[0], NULL);

    destroy_repoMutexes();

    //    pthread_attr_destroy(&attr);
    //    pthread_mutex_destroy(&mxq);
    //    pthread_mutex_destroy(&mxq2);
    printf("global::endProcessMessages!\n");
}

void processMessages3() {
    ProcessMsgClass pmc(client);
    QThread t;
    pmc.moveToThread(&t);
    t.start();
    sleep(10);
}

int main(int argc, char *argv[]) {
    qRegisterMetaType<rec_ptr > ("rec_ptr");

    // initialize resources
    client.reset(new IB::PosixClient());

    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);
    app.setStyleSheet("QMenu::item:selected {border: 1px solid blue;}");

    // create QMainWindow::QWidget and show it
    cf16tradingclient_1 cf16(client, marketDataRepository);
    cf16.show();

    //pthread_exit (NULL);
    return app.exec();
}
