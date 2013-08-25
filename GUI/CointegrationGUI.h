/* 
 * File:   CointegrationGUI.h
 * Author: root
 *
 * Created on August 25, 2013, 4:31 AM
 */

#ifndef COINTEGRATIONGUI_H
#define	COINTEGRATIONGUI_H

#include <GUI/ui_CointegrationGUI.h>
#include <TradingStrategies/Cointegration.h>

class CointegrationGUI : public QDialog {
    Q_OBJECT
public:
    CointegrationGUI();
    virtual ~CointegrationGUI(){}
private:
    Ui::CointegrationGUI widget_;
    Cointegration cointegration_;
};

#endif	/* COINTEGRATIONGUI_H */

