/********************************************************************************
** Form generated from reading UI file 'CointegrationGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COINTEGRATIONGUI_H
#define UI_COINTEGRATIONGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Cointegration
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QListWidget *listWidget;
    QCustomPlot *widget;
    QGroupBox *groupBox_strategyInstructions;
    QPushButton *pushButton_subscribe;
    QPushButton *pushButton_start;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;

    void setupUi(QWidget *Cointegration)
    {
        if (Cointegration->objectName().isEmpty())
            Cointegration->setObjectName(QStringLiteral("Cointegration"));
        Cointegration->resize(522, 593);
        Cointegration->setStyleSheet(QStringLiteral("background-color: rgb(59, 63, 85);"));
        gridLayout_3 = new QGridLayout(Cointegration);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter = new QSplitter(Cointegration);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        splitter->addWidget(listWidget);
        widget = new QCustomPlot(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        QPalette palette;
        QBrush brush(QColor(234, 234, 234, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        widget->setPalette(palette);
        splitter->addWidget(widget);

        gridLayout_3->addWidget(splitter, 0, 1, 2, 1);

        groupBox_strategyInstructions = new QGroupBox(Cointegration);
        groupBox_strategyInstructions->setObjectName(QStringLiteral("groupBox_strategyInstructions"));
        groupBox_strategyInstructions->setStyleSheet(QStringLiteral("color:white;"));
        pushButton_subscribe = new QPushButton(groupBox_strategyInstructions);
        pushButton_subscribe->setObjectName(QStringLiteral("pushButton_subscribe"));
        pushButton_subscribe->setGeometry(QRect(10, 30, 161, 27));
        pushButton_subscribe->setStyleSheet(QLatin1String("color:white;\n"
"background-color: rgb(40, 46, 59);"));
        pushButton_start = new QPushButton(groupBox_strategyInstructions);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(10, 60, 99, 27));
        pushButton_start->setStyleSheet(QLatin1String("color:white;\n"
"background-color: rgb(79, 79, 79);"));
        pushButton_pause = new QPushButton(groupBox_strategyInstructions);
        pushButton_pause->setObjectName(QStringLiteral("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(10, 90, 99, 27));
        pushButton_pause->setStyleSheet(QLatin1String("color:white;\n"
"background-color: rgb(79, 79, 79);"));
        pushButton_stop = new QPushButton(groupBox_strategyInstructions);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(10, 120, 99, 27));
        pushButton_stop->setStyleSheet(QLatin1String("color:white;\n"
"background-color: rgb(79, 79, 79);"));

        gridLayout_3->addWidget(groupBox_strategyInstructions, 0, 0, 2, 1);


        retranslateUi(Cointegration);

        QMetaObject::connectSlotsByName(Cointegration);
    } // setupUi

    void retranslateUi(QWidget *Cointegration)
    {
        Cointegration->setWindowTitle(QApplication::translate("Cointegration", "Cointegration", 0));
#ifndef QT_NO_WHATSTHIS
        Cointegration->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_strategyInstructions->setTitle(QApplication::translate("Cointegration", "strategy instructions", 0));
        pushButton_subscribe->setText(QApplication::translate("Cointegration", "subscribe to data", 0));
        pushButton_start->setText(QApplication::translate("Cointegration", "start", 0));
        pushButton_pause->setText(QApplication::translate("Cointegration", "pause", 0));
        pushButton_stop->setText(QApplication::translate("Cointegration", "stop", 0));
    } // retranslateUi

};

namespace Ui {
    class Cointegration: public Ui_Cointegration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COINTEGRATIONGUI_H
