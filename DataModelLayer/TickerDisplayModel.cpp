/* 
 * File:   TickerDisplayModel.cpp
 * Author: Piotr Gregor  peter cf16 eu
 * 
 * Created on September 5, 2013, 8:24 PM
 */

#include "TickerDisplayModel.h"
#include "TradingStrategies/Cointegration.h"

TickerDisplayModel::TickerDisplayModel(std::vector<IBAdditions::ContractEvent>& availableTickers, QObject *parent) : 
QAbstractTableModel(parent), availableTickers_(availableTickers), m_(availableTickers.size()), n_(3) {
    int i = 0;
    std::vector<IBAdditions::ContractEvent>::const_iterator it = availableTickers_.begin();
    while (it != availableTickers.end()){
        Ticker t(it->symbol, it->currency, it->event_);
        tickerMap_.insert(std::pair<int, Ticker>(i, t));
        it++;
        i++;
    }
}

std::vector<IBAdditions::ContractEvent> TickerDisplayModel::selectedTickers() {
    std::vector<IBAdditions::ContractEvent> st;
    std::map<int, Ticker>::const_iterator it = tickerMap_.begin();
    while ( it != tickerMap_.end()) {
        if ( it->second.state_ == Qt::Checked)
            st.push_back(availableTickers_[it->first]);
        it++;
    }
}

int TickerDisplayModel::rowCount(const QModelIndex &parent) const {
    return m_;
}

int TickerDisplayModel::columnCount(const QModelIndex &parent) const {
    return n_;
}

QVariant TickerDisplayModel::data(const QModelIndex& index, int role) const {
    int row = index.row();
    int col = index.column();

     switch(role){
     case Qt::DisplayRole:
         if (col == 0) 
             return QString::fromStdString(tickerMap_[row].symbol_);
         if (col == 1) 
             return QString::fromStdString(tickerMap_[row].currency_);
         if (col == 2) 
             return QString::fromStdString(ibAdditionsEventToStdString(tickerMap_[row].event_));

         return QString("Row%1, Column%2")
                 .arg(row + 1)
                 .arg(col +1);
         break;
     case Qt::FontRole:
         if (col == 0) //change font only for column 0
         {
             QFont boldFont;
             boldFont.setBold(true);
             return boldFont;
         }
         break;
     case Qt::BackgroundRole:

         if (col == 2)  //change background only for column with event
         {
             QBrush grayBackground(Qt::gray);
             return grayBackground;
         }
         break;
     case Qt::TextAlignmentRole:

         if (col == 0 || col == 1) //change text alignment only for column 0 and 1
         {
             return Qt::AlignRight + Qt::AlignVCenter;
         }
         break;
     case Qt::CheckStateRole:

         if (col == 0) //add a checkbox to column 0
         {
             return tickerMap_[row].state_;
         }
     }
     return QVariant();
}

QVariant TickerDisplayModel::headerData(int section, Qt::Orientation orientation, int role) const {
     if (role == Qt::DisplayRole)
     {
         if (orientation == Qt::Horizontal) {
             switch (section)
             {
             case 0:
                 return QString("symbol");
             case 1:
                 return QString("currency");
             case 2:
                 return QString("event");
                     
             }
         }
     }
     return QVariant();
 }

bool TickerDisplayModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    if (index.column() == 0) 
        tickerMap_[index.row()].state_= value.toInt();
    return true;
}

Qt::ItemFlags TickerDisplayModel::flags(const QModelIndex & index) const {
    if (index.column() == 0) return Qt::ItemIsUserCheckable | Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
