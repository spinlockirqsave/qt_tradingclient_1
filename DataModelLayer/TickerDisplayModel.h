/* 
 * File:   TickerDisplayModel.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on September 5, 2013, 8:24 PM
 */

#ifndef TICKERDISPLAYMODEL_H
#define	TICKERDISPLAYMODEL_H

#include <QtGui/QStandardItemModel>

class TickerDisplayModel : public QStandardItemModel {
public:
    TickerDisplayModel();
    TickerDisplayModel(const TickerDisplayModel& orig);
    virtual ~TickerDisplayModel();
private:

};

#endif	/* TICKERDISPLAYMODEL_H */

