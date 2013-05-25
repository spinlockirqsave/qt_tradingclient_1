/********************************************************************************
** Form generated from reading UI file 'reqMktDataGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQMKTDATAGUI_H
#define UI_REQMKTDATAGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_reqMktDataGUI
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_43;
    QLineEdit *lineEdit_43;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_7;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_8;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_13;
    QLabel *label_9;
    QLineEdit *lineEdit_13;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_14;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_9;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *lineEdit_12;
    QLabel *label_11;
    QPushButton *cancelButton;
    QPushButton *requestButton;

    void setupUi(QDialog *reqMktDataGUI)
    {
        if (reqMktDataGUI->objectName().isEmpty())
            reqMktDataGUI->setObjectName(QStringLiteral("reqMktDataGUI"));
        reqMktDataGUI->setEnabled(true);
        reqMktDataGUI->resize(301, 640);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        reqMktDataGUI->setFont(font);
        reqMktDataGUI->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(reqMktDataGUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_4 = new QGroupBox(reqMktDataGUI);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_43 = new QLabel(groupBox_4);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_4->addWidget(label_43, 0, 0, 1, 1);

        lineEdit_43 = new QLineEdit(groupBox_4);
        lineEdit_43->setObjectName(QStringLiteral("lineEdit_43"));

        gridLayout_4->addWidget(lineEdit_43, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox = new QGroupBox(reqMktDataGUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 6, 1, 1, 3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 3);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 13, 2, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 2, 1, 2);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 5, 1, 1, 3);

        lineEdit_10 = new QLineEdit(groupBox);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 9, 1, 1, 3);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 7, 1, 1, 3);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 3);

        lineEdit_13 = new QLineEdit(groupBox);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 12, 1, 1, 3);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 13, 0, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 10, 1, 1, 3);

        lineEdit_9 = new QLineEdit(groupBox);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 8, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 11, 1, 1, 3);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        lineEdit_7->raise();
        lineEdit_8->raise();
        label_9->raise();
        lineEdit_9->raise();
        label_10->raise();
        label_11->raise();
        label_14->raise();
        label_12->raise();
        label_13->raise();
        lineEdit_10->raise();
        lineEdit_11->raise();
        lineEdit_12->raise();
        lineEdit_13->raise();
        label_8->raise();
        lineEdit->raise();
        checkBox->raise();

        verticalLayout->addWidget(groupBox);

        cancelButton = new QPushButton(reqMktDataGUI);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        requestButton = new QPushButton(reqMktDataGUI);
        requestButton->setObjectName(QStringLiteral("requestButton"));

        verticalLayout->addWidget(requestButton);


        retranslateUi(reqMktDataGUI);

        QMetaObject::connectSlotsByName(reqMktDataGUI);
    } // setupUi

    void retranslateUi(QDialog *reqMktDataGUI)
    {
        reqMktDataGUI->setWindowTitle(QApplication::translate("reqMktDataGUI", "reqMktData", 0));
        groupBox_4->setTitle(QApplication::translate("reqMktDataGUI", "Market Data Request Description", 0));
        label_43->setText(QApplication::translate("reqMktDataGUI", "Id", 0));
        groupBox->setTitle(QApplication::translate("reqMktDataGUI", "Contract Description", 0));
        label_6->setText(QApplication::translate("reqMktDataGUI", "Multiplier", 0));
        label_3->setText(QApplication::translate("reqMktDataGUI", "Expiry", 0));
        label_4->setText(QApplication::translate("reqMktDataGUI", "Strike", 0));
        checkBox->setText(QApplication::translate("reqMktDataGUI", "CheckBox", 0));
        label_2->setText(QApplication::translate("reqMktDataGUI", "Type", 0));
        label_7->setText(QApplication::translate("reqMktDataGUI", "Exchange", 0));
        label->setText(QApplication::translate("reqMktDataGUI", "Symbol", 0));
        label_13->setText(QApplication::translate("reqMktDataGUI", "Generic Tick Tags", 0));
        label_9->setText(QApplication::translate("reqMktDataGUI", "Primary Exchange", 0));
        label_12->setText(QApplication::translate("reqMktDataGUI", "include Expired", 0));
        label_10->setText(QApplication::translate("reqMktDataGUI", "Currency", 0));
        label_14->setText(QApplication::translate("reqMktDataGUI", "Snapshot", 0));
        label_8->setText(QApplication::translate("reqMktDataGUI", "Contract Id", 0));
        label_5->setText(QApplication::translate("reqMktDataGUI", "Right", 0));
        label_11->setText(QApplication::translate("reqMktDataGUI", "Local Symbol", 0));
        cancelButton->setText(QApplication::translate("reqMktDataGUI", "Cancel", 0));
        requestButton->setText(QApplication::translate("reqMktDataGUI", "Request", 0));
    } // retranslateUi

};

namespace Ui {
    class reqMktDataGUI: public Ui_reqMktDataGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQMKTDATAGUI_H
