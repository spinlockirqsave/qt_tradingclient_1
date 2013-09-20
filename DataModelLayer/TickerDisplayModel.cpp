/* 
 * File:   TickerDisplayModel.cpp
 * Author: Piotr Gregor  postmaster@cf16.eu
 * 
 * Created on September 5, 2013, 8:24 PM
 */

#include "TickerDisplayModel.h"

TickerDisplayModel::TickerDisplayModel(std::vector<IBAdditions::ContractEvent> availableTickers, QObject *parent) : 
QAbstractTableModel(parent), availableTickers_(availableTickers), m_(availableTickers.size()+1), n_(4) {
    
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
         if (row == 0 && col == 1) return QString("<--left");
         if (row == 1 && col == 1) return QString("right-->");

         return QString("Row%1, Column%2")
                 .arg(row + 1)
                 .arg(col +1);
         break;
     case Qt::FontRole:
         if (row == 0 && col == 0) //change font only for cell(0,0)
         {
             QFont boldFont;
             boldFont.setBold(true);
             return boldFont;
         }
         break;
     case Qt::BackgroundRole:

         if (row == 1 && col == 2)  //change background only for cell(1,2)
         {
             QBrush redBackground(Qt::red);
             return redBackground;
         }
         break;
     case Qt::TextAlignmentRole:

         if (row == 1 && col == 1) //change text alignment only for cell(1,1)
         {
             return Qt::AlignRight + Qt::AlignVCenter;
         }
         break;
     case Qt::CheckStateRole:

         if (row == 1 && col == 0) //add a checkbox to cell(1,0)
         {
             return Qt::Checked;
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
                 return QString("first");
             case 1:
                 return QString("second");
             case 2:
                 return QString("third");
             }
         }
     }
     return QVariant();
 }

bool TickerDisplayModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    return true;
}

Qt::ItemFlags TickerDisplayModel::flags(const QModelIndex & index) const {
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
