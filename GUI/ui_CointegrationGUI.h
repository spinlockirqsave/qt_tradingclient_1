/********************************************************************************
** Form generated from reading UI file 'CointegrationGUI.ui'
**
** Created: Sun Aug 25 17:26:46 2013
**      by: Qt User Interface Compiler version 4.8.3
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
#include <QtWidgets/QDialog>

#include <GUI/qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_CointegrationGUI
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

    void setupUi(QWidget *CointegrationGUI)
    {
        if (CointegrationGUI->objectName().isEmpty())
            CointegrationGUI->setObjectName(QString::fromUtf8("CointegrationGUI"));
        CointegrationGUI->resize(522, 593);
        CointegrationGUI->setStyleSheet(QString::fromUtf8("background-color: rgb(59, 63, 85);"));
        gridLayout_3 = new QGridLayout(CointegrationGUI);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(CointegrationGUI);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMinimumSize(QSize(0, 400));
        splitter->addWidget(listWidget);
        widget = new QCustomPlot(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 200));
        QPalette palette;
        QBrush brush(QColor(59, 63, 85, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(234, 234, 234, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(159, 158, 158, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        widget->setPalette(palette);
        splitter->addWidget(widget);

        gridLayout_3->addWidget(splitter, 0, 1, 2, 1);

        groupBox_strategyInstructions = new QGroupBox(CointegrationGUI);
        groupBox_strategyInstructions->setObjectName(QString::fromUtf8("groupBox_strategyInstructions"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_strategyInstructions->sizePolicy().hasHeightForWidth());
        groupBox_strategyInstructions->setSizePolicy(sizePolicy2);
        groupBox_strategyInstructions->setMaximumSize(QSize(200, 16777215));
        groupBox_strategyInstructions->setBaseSize(QSize(200, 0));
        groupBox_strategyInstructions->setStyleSheet(QString::fromUtf8("color:white;"));
        pushButton_subscribe = new QPushButton(groupBox_strategyInstructions);
        pushButton_subscribe->setObjectName(QString::fromUtf8("pushButton_subscribe"));
        pushButton_subscribe->setGeometry(QRect(10, 30, 161, 27));
        pushButton_subscribe->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(40, 46, 59);"));
        pushButton_start = new QPushButton(groupBox_strategyInstructions);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(10, 60, 99, 27));
        pushButton_start->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(79, 79, 79);"));
        pushButton_pause = new QPushButton(groupBox_strategyInstructions);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setGeometry(QRect(10, 90, 99, 27));
        pushButton_pause->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(79, 79, 79);"));
        pushButton_stop = new QPushButton(groupBox_strategyInstructions);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(10, 120, 99, 27));
        pushButton_stop->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(79, 79, 79);"));

        gridLayout_3->addWidget(groupBox_strategyInstructions, 0, 0, 2, 1);


        retranslateUi(CointegrationGUI);

        QMetaObject::connectSlotsByName(CointegrationGUI);
    } // setupUi

    void retranslateUi(QWidget *CointegrationGUI)
    {
        CointegrationGUI->setWindowTitle(QApplication::translate("CointegrationGUI", "Cointegration", 0));
#ifndef QT_NO_WHATSTHIS
        CointegrationGUI->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        groupBox_strategyInstructions->setTitle(QApplication::translate("CointegrationGUI", "strategy instructions", 0));
        pushButton_subscribe->setText(QApplication::translate("CointegrationGUI", "subscribe to data", 0));
        pushButton_start->setText(QApplication::translate("CointegrationGUI", "start", 0));
        pushButton_pause->setText(QApplication::translate("CointegrationGUI", "pause", 0));
        pushButton_stop->setText(QApplication::translate("CointegrationGUI", "stop", 0));
    } // retranslateUi

};

namespace Ui {
    class CointegrationGUI: public Ui_CointegrationGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COINTEGRATIONGUI_H
