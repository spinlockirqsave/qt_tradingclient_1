/* 
 * File:   CointegrationGUI.h
 * Author: root
 *
 * Created on August 25, 2013, 4:31 AM
 */

#ifndef COINTEGRATIONGUI_H
#define	COINTEGRATIONGUI_H

#include "ui_Cointegration.h"


class CointegrationGUI : public QDialog {
    Q_OBJECT
public:
    CointegrationGUI();
    virtual ~CointegrationGUI(){}
private:
    Ui::Cointegration widget_;

};

#endif	/* COINTEGRATIONGUI_H */

