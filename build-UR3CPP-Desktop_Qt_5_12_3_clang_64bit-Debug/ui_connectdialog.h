/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Adress;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Connect;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ConnectDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(ConnectDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_Adress = new QLineEdit(ConnectDialog);
        lineEdit_Adress->setObjectName(QString::fromUtf8("lineEdit_Adress"));

        verticalLayout->addWidget(lineEdit_Adress);

        label = new QLabel(ConnectDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(ConnectDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_Connect = new QPushButton(ConnectDialog);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        verticalLayout->addWidget(pushButton_Connect);


        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("ConnectDialog", "Ip Adress", nullptr));
        label->setText(QApplication::translate("ConnectDialog", "Port", nullptr));
        pushButton_Connect->setText(QApplication::translate("ConnectDialog", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
