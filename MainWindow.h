/* 
 * File:   MainWindow.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on May 24, 2013, 12:45 AM
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H


#include "ui_MainWindow.h"


class cf16tradingclient_1 : public QMainWindow {
    Q_OBJECT
public:
    cf16tradingclient_1();
    virtual ~cf16tradingclient_1();
public slots:    
 
private:
    Ui::cf16tradingclient_1 widget;
};


#endif	/* MAINWINDOW_H */

