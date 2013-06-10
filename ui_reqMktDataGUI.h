/********************************************************************************
** Form generated from reading UI file 'reqMktDataGUI.ui'
**
** Created: Mon Jun 10 09:39:45 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQMKTDATAGUI_H
#define UI_REQMKTDATAGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_reqMktDataGUI
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_Id;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Id;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Expiry;
    QCheckBox *checkBox_Snapshot;
    QLineEdit *lineEdit_Strike;
    QLabel *label_Strike;
    QLineEdit *lineEdit_LocalSymbol;
    QLineEdit *lineEdit_PrimaryExchange;
    QLineEdit *lineEdit_Multiplier;
    QLineEdit *lineEdit_Type;
    QLabel *label_Type;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_Right;
    QLabel *label_Multiplier;
    QLineEdit *lineEdit_genericTickTags;
    QLabel *label_IncludeExpired;
    QLabel *label_Currency;
    QLabel *label_Snapshot;
    QLineEdit *lineEdit_ContractId;
    QLineEdit *lineEdit_Currency;
    QLabel *label_LocalSymbol;
    QLineEdit *lineEdit_Symbol;
    QLabel *label_GenericTickTags;
    QLabel *label_PrimaryExchange;
    QLineEdit *lineEdit_Exchange;
    QLabel *label_ContractId;
    QLabel *label_Right;
    QLineEdit *lineEdit_IncludeExpired;
    QLabel *label_Expiry;
    QLabel *label_Symbol;
    QLabel *label_Exchange;
    QTextEdit *textEdit_dataFeed;
    QPushButton *cancelButton;
    QPushButton *requestButton;

    void setupUi(QDialog *reqMktDataGUI)
    {
        if (reqMktDataGUI->objectName().isEmpty())
            reqMktDataGUI->setObjectName(QString::fromUtf8("reqMktDataGUI"));
        reqMktDataGUI->setEnabled(true);
        reqMktDataGUI->resize(637, 640);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        reqMktDataGUI->setFont(font);
        reqMktDataGUI->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(reqMktDataGUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QGroupBox(reqMktDataGUI);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_Id = new QLabel(groupBox_4);
        label_Id->setObjectName(QString::fromUtf8("label_Id"));

        gridLayout_4->addWidget(label_Id, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(360, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        lineEdit_Id = new QLineEdit(groupBox_4);
        lineEdit_Id->setObjectName(QString::fromUtf8("lineEdit_Id"));
        lineEdit_Id->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(lineEdit_Id, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox = new QGroupBox(reqMktDataGUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_Expiry = new QLineEdit(groupBox);
        lineEdit_Expiry->setObjectName(QString::fromUtf8("lineEdit_Expiry"));
        lineEdit_Expiry->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Expiry, 3, 1, 1, 3);

        checkBox_Snapshot = new QCheckBox(groupBox);
        checkBox_Snapshot->setObjectName(QString::fromUtf8("checkBox_Snapshot"));

        gridLayout->addWidget(checkBox_Snapshot, 13, 2, 1, 2);

        lineEdit_Strike = new QLineEdit(groupBox);
        lineEdit_Strike->setObjectName(QString::fromUtf8("lineEdit_Strike"));
        lineEdit_Strike->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Strike, 4, 1, 1, 3);

        label_Strike = new QLabel(groupBox);
        label_Strike->setObjectName(QString::fromUtf8("label_Strike"));

        gridLayout->addWidget(label_Strike, 4, 0, 1, 1);

        lineEdit_LocalSymbol = new QLineEdit(groupBox);
        lineEdit_LocalSymbol->setObjectName(QString::fromUtf8("lineEdit_LocalSymbol"));
        lineEdit_LocalSymbol->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_LocalSymbol, 10, 1, 1, 3);

        lineEdit_PrimaryExchange = new QLineEdit(groupBox);
        lineEdit_PrimaryExchange->setObjectName(QString::fromUtf8("lineEdit_PrimaryExchange"));
        lineEdit_PrimaryExchange->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_PrimaryExchange, 8, 3, 1, 1);

        lineEdit_Multiplier = new QLineEdit(groupBox);
        lineEdit_Multiplier->setObjectName(QString::fromUtf8("lineEdit_Multiplier"));
        lineEdit_Multiplier->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Multiplier, 6, 1, 1, 3);

        lineEdit_Type = new QLineEdit(groupBox);
        lineEdit_Type->setObjectName(QString::fromUtf8("lineEdit_Type"));
        lineEdit_Type->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Type, 2, 2, 1, 2);

        label_Type = new QLabel(groupBox);
        label_Type->setObjectName(QString::fromUtf8("label_Type"));

        gridLayout->addWidget(label_Type, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 4, 1, 1);

        lineEdit_Right = new QLineEdit(groupBox);
        lineEdit_Right->setObjectName(QString::fromUtf8("lineEdit_Right"));
        lineEdit_Right->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Right, 5, 1, 1, 3);

        label_Multiplier = new QLabel(groupBox);
        label_Multiplier->setObjectName(QString::fromUtf8("label_Multiplier"));

        gridLayout->addWidget(label_Multiplier, 6, 0, 1, 1);

        lineEdit_genericTickTags = new QLineEdit(groupBox);
        lineEdit_genericTickTags->setObjectName(QString::fromUtf8("lineEdit_genericTickTags"));
        lineEdit_genericTickTags->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_genericTickTags, 12, 1, 1, 3);

        label_IncludeExpired = new QLabel(groupBox);
        label_IncludeExpired->setObjectName(QString::fromUtf8("label_IncludeExpired"));

        gridLayout->addWidget(label_IncludeExpired, 11, 0, 1, 1);

        label_Currency = new QLabel(groupBox);
        label_Currency->setObjectName(QString::fromUtf8("label_Currency"));

        gridLayout->addWidget(label_Currency, 9, 0, 1, 1);

        label_Snapshot = new QLabel(groupBox);
        label_Snapshot->setObjectName(QString::fromUtf8("label_Snapshot"));

        gridLayout->addWidget(label_Snapshot, 13, 0, 1, 1);

        lineEdit_ContractId = new QLineEdit(groupBox);
        lineEdit_ContractId->setObjectName(QString::fromUtf8("lineEdit_ContractId"));
        lineEdit_ContractId->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_ContractId, 0, 2, 1, 2);

        lineEdit_Currency = new QLineEdit(groupBox);
        lineEdit_Currency->setObjectName(QString::fromUtf8("lineEdit_Currency"));
        lineEdit_Currency->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Currency, 9, 1, 1, 3);

        label_LocalSymbol = new QLabel(groupBox);
        label_LocalSymbol->setObjectName(QString::fromUtf8("label_LocalSymbol"));

        gridLayout->addWidget(label_LocalSymbol, 10, 0, 1, 1);

        lineEdit_Symbol = new QLineEdit(groupBox);
        lineEdit_Symbol->setObjectName(QString::fromUtf8("lineEdit_Symbol"));
        lineEdit_Symbol->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Symbol, 1, 2, 1, 2);

        label_GenericTickTags = new QLabel(groupBox);
        label_GenericTickTags->setObjectName(QString::fromUtf8("label_GenericTickTags"));

        gridLayout->addWidget(label_GenericTickTags, 12, 0, 1, 1);

        label_PrimaryExchange = new QLabel(groupBox);
        label_PrimaryExchange->setObjectName(QString::fromUtf8("label_PrimaryExchange"));

        gridLayout->addWidget(label_PrimaryExchange, 8, 0, 1, 3);

        lineEdit_Exchange = new QLineEdit(groupBox);
        lineEdit_Exchange->setObjectName(QString::fromUtf8("lineEdit_Exchange"));
        lineEdit_Exchange->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Exchange, 7, 1, 1, 3);

        label_ContractId = new QLabel(groupBox);
        label_ContractId->setObjectName(QString::fromUtf8("label_ContractId"));

        gridLayout->addWidget(label_ContractId, 0, 0, 1, 2);

        label_Right = new QLabel(groupBox);
        label_Right->setObjectName(QString::fromUtf8("label_Right"));

        gridLayout->addWidget(label_Right, 5, 0, 1, 1);

        lineEdit_IncludeExpired = new QLineEdit(groupBox);
        lineEdit_IncludeExpired->setObjectName(QString::fromUtf8("lineEdit_IncludeExpired"));
        lineEdit_IncludeExpired->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_IncludeExpired, 11, 1, 1, 3);

        label_Expiry = new QLabel(groupBox);
        label_Expiry->setObjectName(QString::fromUtf8("label_Expiry"));

        gridLayout->addWidget(label_Expiry, 3, 0, 1, 1);

        label_Symbol = new QLabel(groupBox);
        label_Symbol->setObjectName(QString::fromUtf8("label_Symbol"));

        gridLayout->addWidget(label_Symbol, 1, 0, 1, 1);

        label_Exchange = new QLabel(groupBox);
        label_Exchange->setObjectName(QString::fromUtf8("label_Exchange"));

        gridLayout->addWidget(label_Exchange, 7, 0, 1, 1);

        textEdit_dataFeed = new QTextEdit(groupBox);
        textEdit_dataFeed->setObjectName(QString::fromUtf8("textEdit_dataFeed"));
        textEdit_dataFeed->setMinimumSize(QSize(360, 0));
        textEdit_dataFeed->setStyleSheet(QString::fromUtf8("color: rgb(197, 197, 197);"));

        gridLayout->addWidget(textEdit_dataFeed, 0, 4, 14, 2);

        label_Symbol->raise();
        label_Type->raise();
        label_Expiry->raise();
        label_Strike->raise();
        label_Right->raise();
        label_Multiplier->raise();
        label_Exchange->raise();
        lineEdit_Symbol->raise();
        lineEdit_Type->raise();
        lineEdit_Expiry->raise();
        lineEdit_Strike->raise();
        lineEdit_Right->raise();
        lineEdit_Multiplier->raise();
        lineEdit_Exchange->raise();
        label_PrimaryExchange->raise();
        lineEdit_PrimaryExchange->raise();
        label_Currency->raise();
        label_LocalSymbol->raise();
        label_Snapshot->raise();
        label_IncludeExpired->raise();
        label_GenericTickTags->raise();
        lineEdit_Currency->raise();
        lineEdit_LocalSymbol->raise();
        lineEdit_IncludeExpired->raise();
        lineEdit_genericTickTags->raise();
        label_ContractId->raise();
        lineEdit_ContractId->raise();
        checkBox_Snapshot->raise();
        textEdit_dataFeed->raise();

        verticalLayout->addWidget(groupBox);

        cancelButton = new QPushButton(reqMktDataGUI);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        requestButton = new QPushButton(reqMktDataGUI);
        requestButton->setObjectName(QString::fromUtf8("requestButton"));

        verticalLayout->addWidget(requestButton);


        retranslateUi(reqMktDataGUI);

        QMetaObject::connectSlotsByName(reqMktDataGUI);
    } // setupUi

    void retranslateUi(QDialog *reqMktDataGUI)
    {
        reqMktDataGUI->setWindowTitle(QApplication::translate("reqMktDataGUI", "reqMktData", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("reqMktDataGUI", "Market Data Request Description", 0, QApplication::UnicodeUTF8));
        label_Id->setText(QApplication::translate("reqMktDataGUI", "Id", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("reqMktDataGUI", "Contract Description", 0, QApplication::UnicodeUTF8));
        lineEdit_Expiry->setText(QString());
        checkBox_Snapshot->setText(QApplication::translate("reqMktDataGUI", "CheckBox", 0, QApplication::UnicodeUTF8));
        label_Strike->setText(QApplication::translate("reqMktDataGUI", "Strike", 0, QApplication::UnicodeUTF8));
        lineEdit_Type->setText(QString());
        label_Type->setText(QApplication::translate("reqMktDataGUI", "Type", 0, QApplication::UnicodeUTF8));
        label_Multiplier->setText(QApplication::translate("reqMktDataGUI", "Multiplier", 0, QApplication::UnicodeUTF8));
        label_IncludeExpired->setText(QApplication::translate("reqMktDataGUI", "include Expired", 0, QApplication::UnicodeUTF8));
        label_Currency->setText(QApplication::translate("reqMktDataGUI", "Currency", 0, QApplication::UnicodeUTF8));
        label_Snapshot->setText(QApplication::translate("reqMktDataGUI", "Snapshot", 0, QApplication::UnicodeUTF8));
        label_LocalSymbol->setText(QApplication::translate("reqMktDataGUI", "Local Symbol", 0, QApplication::UnicodeUTF8));
        lineEdit_Symbol->setText(QString());
        label_GenericTickTags->setText(QApplication::translate("reqMktDataGUI", "Generic Tick Tags", 0, QApplication::UnicodeUTF8));
        label_PrimaryExchange->setText(QApplication::translate("reqMktDataGUI", "Primary Exchange", 0, QApplication::UnicodeUTF8));
        label_ContractId->setText(QApplication::translate("reqMktDataGUI", "Contract Id", 0, QApplication::UnicodeUTF8));
        label_Right->setText(QApplication::translate("reqMktDataGUI", "Right", 0, QApplication::UnicodeUTF8));
        label_Expiry->setText(QApplication::translate("reqMktDataGUI", "Expiry", 0, QApplication::UnicodeUTF8));
        label_Symbol->setText(QApplication::translate("reqMktDataGUI", "Symbol", 0, QApplication::UnicodeUTF8));
        label_Exchange->setText(QApplication::translate("reqMktDataGUI", "Exchange", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("reqMktDataGUI", "Cancel", 0, QApplication::UnicodeUTF8));
        requestButton->setText(QApplication::translate("reqMktDataGUI", "Request", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class reqMktDataGUI: public Ui_reqMktDataGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQMKTDATAGUI_H
