/* 
 * File:   MessageProcessor.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on June 17, 2013, 11:57 PM
 */

#ifndef MESSAGEPROCESSOR_H
#define	MESSAGEPROCESSOR_H

#include <QtCore/QThread>
#include <QtCore/QObject>
#include "PosixClient.h"

class MessageProcessor : public QThread {

    Q_OBJECT
public:
    MessageProcessor(boost::shared_ptr<IB::PosixClient> client, QObject *parent = 0);
    ~MessageProcessor();
    
    public Q_SLOTS :
    void start() {
        printf("MessageProcessor::processMessages()\n");
        while (true) {
            printf("MessageProcessor::processMessages()::while()\n");
            client->processMessages();
        }
    }
    private:
        boost::shared_ptr<IB::PosixClient> client;
};

#endif	/* MESSAGEPROCESSOR_H */

