/* 
 * File:   TickerDisplayModel.h
 * Author: Piotr Gregor  piter cf16 eu
 *
 * Created on September 5, 2013, 8:24 PM
 */

#ifndef TICKERDISPLAYMODEL_H
#define	TICKERDISPLAYMODEL_H

#include <IBAdditions/IB_events.h>

#include <QtCore/QAbstractTableModel>
#include <QtGui/QStandardItem>
#include <QtCore/QtCore>

#include <vector>
#include <map>

/**
 * model which allows display 
 * of available data streams as tickers
 */
class TickerDisplayModel : public QAbstractTableModel {
    
Q_OBJECT

 public:
     
     /**
      * methods handling Qt model
      */
     TickerDisplayModel(std::vector<IBAdditions::ContractEvent>& availableTickers, QObject *parent = 0);
     int rowCount(const QModelIndex &parent = QModelIndex()) const ;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;
     QVariant headerData(int section, Qt::Orientation orientation, int role) const;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
     bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
     Qt::ItemFlags flags(const QModelIndex & index) const;
     
     /**
      * returns tickers which user checked
      */
     std::vector<IBAdditions::ContractEvent> selectedTickers();
     
     struct Ticker{
         std::string symbol_;
         std::string currency_;
         IBAdditions::Event event_;
         int state_;
         Ticker(){}
         Ticker(std::string symbol, std::string currency, IBAdditions::Event event)
                 : symbol_(symbol), currency_(currency), event_(event), state_(Qt::Unchecked) {}
     };
     
 private:
     
     int m_;
     int n_;
     /**
      * 
      * @param what's in repository? 
      */
     std::vector<IBAdditions::ContractEvent>& availableTickers_;
     
     /**
      * mapping
      */
     mutable std::map<int, Ticker> tickerMap_;
     
 signals:
     void editCompleted(const QString &);
};

#endif	/* TICKERDISPLAYMODEL_H */

