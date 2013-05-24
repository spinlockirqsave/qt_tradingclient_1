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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuCf16_tradingclient_1;
    QMenu *menuStrategies;
    QMenu *menuMarket;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cf16tradingclient_1)
    {
        if (cf16tradingclient_1->objectName().isEmpty())
            cf16tradingclient_1->setObjectName(QStringLiteral("cf16tradingclient_1"));
        cf16tradingclient_1->resize(967, 798);
        cf16tradingclient_1->setStyleSheet(QStringLiteral("background-color: rgb(42, 42, 42);"));
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
        centralwidget = new QWidget(cf16tradingclient_1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cf16tradingclient_1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cf16tradingclient_1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 967, 25));
        menubar->setFocusPolicy(Qt::NoFocus);
        menubar->setContextMenuPolicy(Qt::DefaultContextMenu);
        menubar->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 255);"));
        menuCf16_tradingclient_1 = new QMenu(menubar);
        menuCf16_tradingclient_1->setObjectName(QStringLiteral("menuCf16_tradingclient_1"));
        menuCf16_tradingclient_1->setFocusPolicy(Qt::NoFocus);
        menuCf16_tradingclient_1->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 255);\n"
"border: 1px solid rgb(0,0,200);"));
        menuStrategies = new QMenu(menubar);
        menuStrategies->setObjectName(QStringLiteral("menuStrategies"));
        menuStrategies->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 255);\n"
"border: 1px solid rgb(0,0,255);"));
        menuMarket = new QMenu(menubar);
        menuMarket->setObjectName(QStringLiteral("menuMarket"));
        menuMarket->setFocusPolicy(Qt::NoFocus);
        menuMarket->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 255);\n"
"border: 1px solid rgb(0,0,150);"));
        cf16tradingclient_1->setMenuBar(menubar);
        statusbar = new QStatusBar(cf16tradingclient_1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        cf16tradingclient_1->setStatusBar(statusbar);

        menubar->addAction(menuCf16_tradingclient_1->menuAction());
        menubar->addAction(menuStrategies->menuAction());
        menubar->addAction(menuMarket->menuAction());
        menuCf16_tradingclient_1->addAction(actionOpen);
        menuCf16_tradingclient_1->addAction(actionSave);
        menuCf16_tradingclient_1->addAction(actionSave_as);
        menuStrategies->addAction(actionCointegration);
        menuMarket->addAction(actionFX);
        menuMarket->addAction(actionIR);
        menuMarket->addAction(actionStocks);
        menuMarket->addAction(actionOptions);
        menuMarket->addAction(actionForwards);
        menuMarket->addAction(actionFutures);
        menuMarket->addAction(actionSwaps);
        menuMarket->addAction(actionBonds);

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
        menuCf16_tradingclient_1->setTitle(QApplication::translate("cf16tradingclient_1", "cf16 tradingclient_1", 0));
        menuStrategies->setTitle(QApplication::translate("cf16tradingclient_1", "Strategies", 0));
        menuMarket->setTitle(QApplication::translate("cf16tradingclient_1", "Market", 0));
    } // retranslateUi

};

namespace Ui {
    class cf16tradingclient_1: public Ui_cf16tradingclient_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
