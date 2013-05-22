/* 
 * File:   GUI.h
 * Author: root
 *
 * Created on May 22, 2013, 8:36 PM
 */

#ifndef _GUI_H
#define	_GUI_H

#include "ui_GUI.h"
#include "PosixClient.h"
class IB::PosixClient;

class GUI : public QDialog {
    Q_OBJECT
public:
    GUI();
    virtual ~GUI();
public slots:
    void connectClicked();    
 
private:
    Ui::GUI widget;
    IB::PosixClient client;
    const char* host;
    unsigned int port;
    int clientId;
};

#endif	/* _GUI_H */
