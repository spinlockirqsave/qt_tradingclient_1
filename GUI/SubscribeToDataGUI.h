/* 
 * File:   SubscribeToData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on September 10, 2013, 2:30 AM
 */

#ifndef SUBSCRIBETODATAGUI_H
#define	SUBSCRIBETODATAGUI_H

#include "ui_SubscribeToDataGUI.h"
#include <QtWidgets/QDialog>

class SubscribeToDataGUI  : public QDialog {
    Q_OBJECT
public:
    SubscribeToDataGUI(QWidget* parent = 0);
    SubscribeToDataGUI(const SubscribeToDataGUI& orig);
    virtual ~SubscribeToDataGUI();

    Q_SIGNALS:
    
public slots:
    
private:

};

#endif	/* SUBSCRIBETODATAGUI_H */

