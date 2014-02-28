/* 
 * File:   ProcessMsgClass.h
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on June 15, 2013, 4:01 PM
 */

#ifndef PROCESSMSGCLASS_H
#define	PROCESSMSGCLASS_H

#include <QtCore/QThread>
#include <QtCore/QObject>
#include "PosixClient.h"

class ProcessMsgClass : public QObject {

    Q_OBJECT
public:
    ProcessMsgClass(boost::shared_ptr<IB::PosixClient> client):client(client){}
    ~ProcessMsgClass(){}
    public Q_SLOTS :
    void start() {
        printf("ProcessMsgClass::processMessages()\n");
        while (true) {
            printf("ProcessMsgClass::processMessages()::while()\n");
            client->processMessages();
        }
    }
    private:
        boost::shared_ptr<IB::PosixClient> client;
};

#endif	/* PROCESSMSGCLASS_H */

