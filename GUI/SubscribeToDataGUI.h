/* 
 * File:   SubscribeToData.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on September 10, 2013, 2:30 AM
 */

#ifndef SUBSCRIBETODATAGUI_H
#define	SUBSCRIBETODATAGUI_H

#include "ui_SubscribeToDataGUI.h"
#include <DataModelLayer/TickerDisplayModel.h>
#include <DataAccessLayer/Repository.h>

#include <QtWidgets/QDialog>

extern Repository marketDataRepository;


class SubscribeToDataGUI  : public QDialog {
    Q_OBJECT
public:
    explicit SubscribeToDataGUI(QWidget* parent = 0);
    SubscribeToDataGUI(const SubscribeToDataGUI& orig);
    virtual ~SubscribeToDataGUI();

    Q_SIGNALS:
    
public slots:
    
private:
    Ui::SubscribeToDataGUI widget_;
    std::auto_ptr<TickerDisplayModel> model_;
    std::vector<IBAdditions::ContractEvent> availableTickers_;

};

#endif	/* SUBSCRIBETODATAGUI_H */

