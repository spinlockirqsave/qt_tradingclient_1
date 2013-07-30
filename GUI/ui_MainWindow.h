/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cf16tradingclient_1
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionFX;
    QAction *actionIR;
    QAction *actionStocks;
    QAction *actionOptions;
    QAction *actionForwards;
    QAction *actionFutures;
    QAction *actionSwaps;
    QAction *actionBonds;
    QAction *actionCointegration;
    QAction *actionReqMktData;
    QAction *actionReqContractDetails;
    QAction *actionReqMktDataGUI;
    QAction *actionReqMktDepth;
    QAction *actionUpdatePortfolio;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListView *listView_2;
    QGroupBox *groupBox_2;
    QTableView *tableView;
    QListView *listView;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_3;
    QLabel *label_6_connected;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QMenuBar *menubar;
    QMenu *menuCf16_tradingclient_1;
    QMenu *menuStrategies;
    QMenu *menuMarket;
    QMenu *menuAction;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cf16tradingclient_1)
    {
        if (cf16tradingclient_1->objectName().isEmpty())
            cf16tradingclient_1->setObjectName(QStringLiteral("cf16tradingclient_1"));
        cf16tradingclient_1->resize(956, 888);
        cf16tradingclient_1->setStyleSheet(QLatin1String("background-color: rgb(42, 42, 42);\n"
"QMenu::item:selected {border: 1px solid dark blue;}"));
        actionOpen = new QAction(cf16tradingclient_1);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(cf16tradingclient_1);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(cf16tradingclient_1);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionFX = new QAction(cf16tradingclient_1);
        actionFX->setObjectName(QStringLiteral("actionFX"));
        actionIR = new QAction(cf16tradingclient_1);
        actionIR->setObjectName(QStringLiteral("actionIR"));
        actionStocks = new QAction(cf16tradingclient_1);
        actionStocks->setObjectName(QStringLiteral("actionStocks"));
        actionOptions = new QAction(cf16tradingclient_1);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionForwards = new QAction(cf16tradingclient_1);
        actionForwards->setObjectName(QStringLiteral("actionForwards"));
        actionFutures = new QAction(cf16tradingclient_1);
        actionFutures->setObjectName(QStringLiteral("actionFutures"));
        actionSwaps = new QAction(cf16tradingclient_1);
        actionSwaps->setObjectName(QStringLiteral("actionSwaps"));
        actionBonds = new QAction(cf16tradingclient_1);
        actionBonds->setObjectName(QStringLiteral("actionBonds"));
        actionCointegration = new QAction(cf16tradingclient_1);
        actionCointegration->setObjectName(QStringLiteral("actionCointegration"));
        actionReqMktData = new QAction(cf16tradingclient_1);
        actionReqMktData->setObjectName(QStringLiteral("actionReqMktData"));
        actionReqContractDetails = new QAction(cf16tradingclient_1);
        actionReqContractDetails->setObjectName(QStringLiteral("actionReqContractDetails"));
        actionReqMktDataGUI = new QAction(cf16tradingclient_1);
        actionReqMktDataGUI->setObjectName(QStringLiteral("actionReqMktDataGUI"));
        actionReqMktDepth = new QAction(cf16tradingclient_1);
        actionReqMktDepth->setObjectName(QStringLiteral("actionReqMktDepth"));
        actionUpdatePortfolio = new QAction(cf16tradingclient_1);
        actionUpdatePortfolio->setObjectName(QStringLiteral("actionUpdatePortfolio"));
        centralwidget = new QWidget(cf16tradingclient_1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listView_2 = new QListView(centralwidget);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        gridLayout->addWidget(listView_2, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));

        gridLayout->addWidget(groupBox_2, 2, 3, 1, 1);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 2);

        listView = new QListView(centralwidget);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 1, 0, 1, 4);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(6, 5, 301, 71));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        gridLayout_2->addWidget(lcdNumber, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 3, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        label_6_connected = new QLabel(groupBox_3);
        label_6_connected->setObjectName(QStringLiteral("label_6_connected"));
        label_6_connected->setGeometry(QRect(10, 40, 131, 17));
        connectButton = new QPushButton(groupBox_3);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(10, 80, 99, 27));
        disconnectButton = new QPushButton(groupBox_3);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setGeometry(QRect(120, 80, 99, 27));

        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        cf16tradingclient_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cf16tradingclient_1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 956, 25));
        menubar->setFocusPolicy(Qt::NoFocus);
        menubar->setContextMenuPolicy(Qt::DefaultContextMenu);
        menubar->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 255);"));
        menuCf16_tradingclient_1 = new QMenu(menubar);
        menuCf16_tradingclient_1->setObjectName(QStringLiteral("menuCf16_tradingclient_1"));
        menuCf16_tradingclient_1->setFocusPolicy(Qt::NoFocus);
        menuCf16_tradingclient_1->setStyleSheet(QStringLiteral(""));
        menuStrategies = new QMenu(menubar);
        menuStrategies->setObjectName(QStringLiteral("menuStrategies"));
        menuStrategies->setStyleSheet(QStringLiteral(""));
        menuMarket = new QMenu(menubar);
        menuMarket->setObjectName(QStringLiteral("menuMarket"));
        menuMarket->setFocusPolicy(Qt::NoFocus);
        menuMarket->setStyleSheet(QStringLiteral(""));
        menuAction = new QMenu(menubar);
        menuAction->setObjectName(QStringLiteral("menuAction"));
        cf16tradingclient_1->setMenuBar(menubar);
        statusbar = new QStatusBar(cf16tradingclient_1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cf16tradingclient_1->setStatusBar(statusbar);

        menubar->addAction(menuCf16_tradingclient_1->menuAction());
        menubar->addAction(menuStrategies->menuAction());
        menubar->addAction(menuMarket->menuAction());
        menubar->addAction(menuAction->menuAction());
        menuCf16_tradingclient_1->addAction(actionOpen);
        menuCf16_tradingclient_1->addAction(actionSave);
        menuCf16_tradingclient_1->addAction(actionSave_as);
        menuStrategies->addAction(actionCointegration);
        menuStrategies->addSeparator();
        menuMarket->addAction(actionFX);
        menuMarket->addAction(actionIR);
        menuMarket->addAction(actionStocks);
        menuMarket->addAction(actionOptions);
        menuMarket->addAction(actionForwards);
        menuMarket->addAction(actionFutures);
        menuMarket->addAction(actionSwaps);
        menuMarket->addAction(actionBonds);
        menuAction->addAction(actionReqMktData);
        menuAction->addAction(actionReqContractDetails);
        menuAction->addAction(actionReqMktDepth);
        menuAction->addAction(actionUpdatePortfolio);

        retranslateUi(cf16tradingclient_1);

        QMetaObject::connectSlotsByName(cf16tradingclient_1);
    } // setupUi

    void retranslateUi(QMainWindow *cf16tradingclient_1)
    {
        cf16tradingclient_1->setWindowTitle(QApplication::translate("cf16tradingclient_1", "cf16tradingclient_1", 0));
        actionOpen->setText(QApplication::translate("cf16tradingclient_1", "Open", 0));
        actionSave->setText(QApplication::translate("cf16tradingclient_1", "Save", 0));
        actionSave_as->setText(QApplication::translate("cf16tradingclient_1", "Save as", 0));
        actionFX->setText(QApplication::translate("cf16tradingclient_1", "FX", 0));
        actionIR->setText(QApplication::translate("cf16tradingclient_1", "IR", 0));
        actionStocks->setText(QApplication::translate("cf16tradingclient_1", "Stocks", 0));
        actionOptions->setText(QApplication::translate("cf16tradingclient_1", "Options", 0));
        actionForwards->setText(QApplication::translate("cf16tradingclient_1", "Forwards", 0));
        actionFutures->setText(QApplication::translate("cf16tradingclient_1", "Futures", 0));
        actionSwaps->setText(QApplication::translate("cf16tradingclient_1", "Swaps", 0));
        actionBonds->setText(QApplication::translate("cf16tradingclient_1", "Bonds", 0));
        actionCointegration->setText(QApplication::translate("cf16tradingclient_1", "Cointegration", 0));
        actionReqMktData->setText(QApplication::translate("cf16tradingclient_1", "ReqMktData", 0));
        actionReqContractDetails->setText(QApplication::translate("cf16tradingclient_1", "ReqContractDetails", 0));
        actionReqMktDataGUI->setText(QApplication::translate("cf16tradingclient_1", "ReqMktDataGUI", 0));
        actionReqMktDepth->setText(QApplication::translate("cf16tradingclient_1", "ReqMktDepth", 0));
        actionUpdatePortfolio->setText(QApplication::translate("cf16tradingclient_1", "UpdatePortfolio", 0));
        groupBox_2->setTitle(QApplication::translate("cf16tradingclient_1", "GroupBox", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("cf16tradingclient_1", "time", 0));
        label_3->setText(QApplication::translate("cf16tradingclient_1", "TextLabel", 0));
        label->setText(QApplication::translate("cf16tradingclient_1", "strategies running", 0));
        label_4->setText(QApplication::translate("cf16tradingclient_1", "IB time", 0));
        label_5->setText(QApplication::translate("cf16tradingclient_1", "TextLabel", 0));
        groupBox_3->setTitle(QApplication::translate("cf16tradingclient_1", "Status", 0));
        label_6_connected->setText(QApplication::translate("cf16tradingclient_1", "Not connected", 0));
        connectButton->setText(QApplication::translate("cf16tradingclient_1", "connect", 0));
        disconnectButton->setText(QApplication::translate("cf16tradingclient_1", "disconnect", 0));
        menuCf16_tradingclient_1->setTitle(QApplication::translate("cf16tradingclient_1", "cf16 tradingclient_1", 0));
        menuStrategies->setTitle(QApplication::translate("cf16tradingclient_1", "Strategies", 0));
        menuMarket->setTitle(QApplication::translate("cf16tradingclient_1", "Market", 0));
        menuAction->setTitle(QApplication::translate("cf16tradingclient_1", "Action", 0));
    } // retranslateUi

};

namespace Ui {
    class cf16tradingclient_1: public Ui_cf16tradingclient_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
