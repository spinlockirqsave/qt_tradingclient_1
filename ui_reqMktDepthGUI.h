/********************************************************************************
** Form generated from reading UI file 'ReqMktDepthGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQMKTDEPTHGUI_H
#define UI_REQMKTDEPTHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reqMktDepthGUI
{
public:
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_Id;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Id;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_dataFeed;
    QLineEdit *lineEdit_Expiry;
    QCheckBox *checkBox_Snapshot;
    QLineEdit *lineEdit_Strike;
    QLabel *label_Strike;
    QLineEdit *lineEdit_LocalSymbol;
    QLineEdit *lineEdit_PrimaryExchange;
    QLineEdit *lineEdit_Multiplier;
    QLineEdit *lineEdit_Type;
    QLabel *label_Expiry;
    QLabel *label_Type;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_Right;
    QLabel *label_Multiplier;
    QLabel *label_Currency;
    QLineEdit *lineEdit_genericTickTags;
    QLabel *label_IncludeExpired;
    QLabel *label_Snapshot;
    QLabel *label_LocalSymbol;
    QLineEdit *lineEdit_ContractIdt;
    QLineEdit *lineEdit_Currency;
    QLabel *label_GenericTickTags;
    QLabel *label_PrimaryExchange;
    QLineEdit *lineEdit_Symbol;
    QLabel *label_ContractId;
    QLabel *label_Right;
    QLineEdit *lineEdit_Exchange;
    QLabel *label_Symbol;
    QLineEdit *lineEdit_IncludeExpired;
    QLabel *label_Exchange;
    QLabel *label_MaxNumberOfRows;
    QLineEdit *lineEdit_MaxNumberOfRows;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *requestButton;
    QPushButton *guiRequestButton;

    void setupUi(QDialog *reqMktDepthGUI)
    {
        if (reqMktDepthGUI->objectName().isEmpty())
            reqMktDepthGUI->setObjectName(QStringLiteral("reqMktDepthGUI"));
        reqMktDepthGUI->setEnabled(true);
        reqMktDepthGUI->resize(645, 597);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        reqMktDepthGUI->setFont(font);
        reqMktDepthGUI->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        groupBox_4 = new QGroupBox(reqMktDepthGUI);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(9, 9, 557, 63));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_Id = new QLabel(groupBox_4);
        label_Id->setObjectName(QStringLiteral("label_Id"));

        gridLayout_4->addWidget(label_Id, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(360, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);

        lineEdit_Id = new QLineEdit(groupBox_4);
        lineEdit_Id->setObjectName(QStringLiteral("lineEdit_Id"));
        lineEdit_Id->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout_4->addWidget(lineEdit_Id, 0, 1, 1, 1);

        groupBox = new QGroupBox(reqMktDepthGUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 78, 619, 454));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit_dataFeed = new QTextEdit(groupBox);
        textEdit_dataFeed->setObjectName(QStringLiteral("textEdit_dataFeed"));
        textEdit_dataFeed->setMinimumSize(QSize(360, 0));
        textEdit_dataFeed->setStyleSheet(QStringLiteral("color: rgb(197, 197, 197);"));

        gridLayout->addWidget(textEdit_dataFeed, 0, 4, 15, 2);

        lineEdit_Expiry = new QLineEdit(groupBox);
        lineEdit_Expiry->setObjectName(QStringLiteral("lineEdit_Expiry"));
        lineEdit_Expiry->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Expiry, 3, 1, 1, 3);

        checkBox_Snapshot = new QCheckBox(groupBox);
        checkBox_Snapshot->setObjectName(QStringLiteral("checkBox_Snapshot"));

        gridLayout->addWidget(checkBox_Snapshot, 14, 2, 1, 2);

        lineEdit_Strike = new QLineEdit(groupBox);
        lineEdit_Strike->setObjectName(QStringLiteral("lineEdit_Strike"));
        lineEdit_Strike->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Strike, 4, 1, 1, 3);

        label_Strike = new QLabel(groupBox);
        label_Strike->setObjectName(QStringLiteral("label_Strike"));

        gridLayout->addWidget(label_Strike, 4, 0, 1, 1);

        lineEdit_LocalSymbol = new QLineEdit(groupBox);
        lineEdit_LocalSymbol->setObjectName(QStringLiteral("lineEdit_LocalSymbol"));
        lineEdit_LocalSymbol->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_LocalSymbol, 10, 1, 1, 3);

        lineEdit_PrimaryExchange = new QLineEdit(groupBox);
        lineEdit_PrimaryExchange->setObjectName(QStringLiteral("lineEdit_PrimaryExchange"));
        lineEdit_PrimaryExchange->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_PrimaryExchange, 8, 3, 1, 1);

        lineEdit_Multiplier = new QLineEdit(groupBox);
        lineEdit_Multiplier->setObjectName(QStringLiteral("lineEdit_Multiplier"));
        lineEdit_Multiplier->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Multiplier, 6, 1, 1, 3);

        lineEdit_Type = new QLineEdit(groupBox);
        lineEdit_Type->setObjectName(QStringLiteral("lineEdit_Type"));
        lineEdit_Type->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Type, 2, 2, 1, 2);

        label_Expiry = new QLabel(groupBox);
        label_Expiry->setObjectName(QStringLiteral("label_Expiry"));

        gridLayout->addWidget(label_Expiry, 3, 0, 1, 1);

        label_Type = new QLabel(groupBox);
        label_Type->setObjectName(QStringLiteral("label_Type"));

        gridLayout->addWidget(label_Type, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 4, 1, 1);

        lineEdit_Right = new QLineEdit(groupBox);
        lineEdit_Right->setObjectName(QStringLiteral("lineEdit_Right"));
        lineEdit_Right->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Right, 5, 1, 1, 3);

        label_Multiplier = new QLabel(groupBox);
        label_Multiplier->setObjectName(QStringLiteral("label_Multiplier"));

        gridLayout->addWidget(label_Multiplier, 6, 0, 1, 1);

        label_Currency = new QLabel(groupBox);
        label_Currency->setObjectName(QStringLiteral("label_Currency"));

        gridLayout->addWidget(label_Currency, 9, 0, 1, 1);

        lineEdit_genericTickTags = new QLineEdit(groupBox);
        lineEdit_genericTickTags->setObjectName(QStringLiteral("lineEdit_genericTickTags"));
        lineEdit_genericTickTags->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_genericTickTags, 12, 1, 1, 3);

        label_IncludeExpired = new QLabel(groupBox);
        label_IncludeExpired->setObjectName(QStringLiteral("label_IncludeExpired"));

        gridLayout->addWidget(label_IncludeExpired, 11, 0, 1, 1);

        label_Snapshot = new QLabel(groupBox);
        label_Snapshot->setObjectName(QStringLiteral("label_Snapshot"));

        gridLayout->addWidget(label_Snapshot, 14, 0, 1, 1);

        label_LocalSymbol = new QLabel(groupBox);
        label_LocalSymbol->setObjectName(QStringLiteral("label_LocalSymbol"));

        gridLayout->addWidget(label_LocalSymbol, 10, 0, 1, 1);

        lineEdit_ContractIdt = new QLineEdit(groupBox);
        lineEdit_ContractIdt->setObjectName(QStringLiteral("lineEdit_ContractIdt"));
        lineEdit_ContractIdt->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_ContractIdt, 0, 2, 1, 2);

        lineEdit_Currency = new QLineEdit(groupBox);
        lineEdit_Currency->setObjectName(QStringLiteral("lineEdit_Currency"));
        lineEdit_Currency->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Currency, 9, 1, 1, 3);

        label_GenericTickTags = new QLabel(groupBox);
        label_GenericTickTags->setObjectName(QStringLiteral("label_GenericTickTags"));

        gridLayout->addWidget(label_GenericTickTags, 12, 0, 1, 1);

        label_PrimaryExchange = new QLabel(groupBox);
        label_PrimaryExchange->setObjectName(QStringLiteral("label_PrimaryExchange"));

        gridLayout->addWidget(label_PrimaryExchange, 8, 0, 1, 3);

        lineEdit_Symbol = new QLineEdit(groupBox);
        lineEdit_Symbol->setObjectName(QStringLiteral("lineEdit_Symbol"));
        lineEdit_Symbol->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Symbol, 1, 2, 1, 2);

        label_ContractId = new QLabel(groupBox);
        label_ContractId->setObjectName(QStringLiteral("label_ContractId"));

        gridLayout->addWidget(label_ContractId, 0, 0, 1, 2);

        label_Right = new QLabel(groupBox);
        label_Right->setObjectName(QStringLiteral("label_Right"));

        gridLayout->addWidget(label_Right, 5, 0, 1, 1);

        lineEdit_Exchange = new QLineEdit(groupBox);
        lineEdit_Exchange->setObjectName(QStringLiteral("lineEdit_Exchange"));
        lineEdit_Exchange->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_Exchange, 7, 1, 1, 3);

        label_Symbol = new QLabel(groupBox);
        label_Symbol->setObjectName(QStringLiteral("label_Symbol"));

        gridLayout->addWidget(label_Symbol, 1, 0, 1, 1);

        lineEdit_IncludeExpired = new QLineEdit(groupBox);
        lineEdit_IncludeExpired->setObjectName(QStringLiteral("lineEdit_IncludeExpired"));
        lineEdit_IncludeExpired->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(lineEdit_IncludeExpired, 11, 1, 1, 3);

        label_Exchange = new QLabel(groupBox);
        label_Exchange->setObjectName(QStringLiteral("label_Exchange"));

        gridLayout->addWidget(label_Exchange, 7, 0, 1, 1);

        label_MaxNumberOfRows = new QLabel(groupBox);
        label_MaxNumberOfRows->setObjectName(QStringLiteral("label_MaxNumberOfRows"));

        gridLayout->addWidget(label_MaxNumberOfRows, 13, 0, 1, 1);

        lineEdit_MaxNumberOfRows = new QLineEdit(groupBox);
        lineEdit_MaxNumberOfRows->setObjectName(QStringLiteral("lineEdit_MaxNumberOfRows"));

        gridLayout->addWidget(lineEdit_MaxNumberOfRows, 13, 1, 1, 3);

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
        lineEdit_ContractIdt->raise();
        checkBox_Snapshot->raise();
        textEdit_dataFeed->raise();
        lineEdit_MaxNumberOfRows->raise();
        label_MaxNumberOfRows->raise();
        layoutWidget = new QWidget(reqMktDepthGUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 538, 611, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        requestButton = new QPushButton(layoutWidget);
        requestButton->setObjectName(QStringLiteral("requestButton"));

        horizontalLayout->addWidget(requestButton);

        guiRequestButton = new QPushButton(layoutWidget);
        guiRequestButton->setObjectName(QStringLiteral("guiRequestButton"));

        horizontalLayout->addWidget(guiRequestButton);


        retranslateUi(reqMktDepthGUI);

        QMetaObject::connectSlotsByName(reqMktDepthGUI);
    } // setupUi

    void retranslateUi(QDialog *reqMktDepthGUI)
    {
        reqMktDepthGUI->setWindowTitle(QApplication::translate("reqMktDepthGUI", "reqMktDepth", 0));
        groupBox_4->setTitle(QApplication::translate("reqMktDepthGUI", "Market Data Request Description", 0));
        label_Id->setText(QApplication::translate("reqMktDepthGUI", "Id", 0));
        groupBox->setTitle(QApplication::translate("reqMktDepthGUI", "Contract Description", 0));
        lineEdit_Expiry->setText(QString());
        checkBox_Snapshot->setText(QApplication::translate("reqMktDepthGUI", "CheckBox", 0));
        label_Strike->setText(QApplication::translate("reqMktDepthGUI", "Strike", 0));
        lineEdit_Type->setText(QString());
        label_Expiry->setText(QApplication::translate("reqMktDepthGUI", "Expiry", 0));
        label_Type->setText(QApplication::translate("reqMktDepthGUI", "Type", 0));
        label_Multiplier->setText(QApplication::translate("reqMktDepthGUI", "Multiplier", 0));
        label_Currency->setText(QApplication::translate("reqMktDepthGUI", "Currency", 0));
        label_IncludeExpired->setText(QApplication::translate("reqMktDepthGUI", "include Expired", 0));
        label_Snapshot->setText(QApplication::translate("reqMktDepthGUI", "Snapshot", 0));
        label_LocalSymbol->setText(QApplication::translate("reqMktDepthGUI", "Local Symbol", 0));
        label_GenericTickTags->setText(QApplication::translate("reqMktDepthGUI", "Generic Tick Tags", 0));
        label_PrimaryExchange->setText(QApplication::translate("reqMktDepthGUI", "Primary Exchange", 0));
        lineEdit_Symbol->setText(QString());
        label_ContractId->setText(QApplication::translate("reqMktDepthGUI", "Contract Id", 0));
        label_Right->setText(QApplication::translate("reqMktDepthGUI", "Right", 0));
        label_Symbol->setText(QApplication::translate("reqMktDepthGUI", "Symbol", 0));
        label_Exchange->setText(QApplication::translate("reqMktDepthGUI", "Exchange", 0));
        label_MaxNumberOfRows->setText(QApplication::translate("reqMktDepthGUI", "Max Number of Rows", 0));
        cancelButton->setText(QApplication::translate("reqMktDepthGUI", "Cancel", 0));
        requestButton->setText(QApplication::translate("reqMktDepthGUI", "Request", 0));
        guiRequestButton->setText(QApplication::translate("reqMktDepthGUI", "GUI Request", 0));
    } // retranslateUi

};

namespace Ui {
    class reqMktDepthGUI: public Ui_reqMktDepthGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQMKTDEPTHGUI_H
