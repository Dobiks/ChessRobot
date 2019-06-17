/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnection_Info;
    QAction *actionConnect;
    QAction *actionSettings;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label;
    QLineEdit *lineEditBase;
    QLabel *label_8;
    QLineEdit *lineEditY;
    QLabel *label_10;
    QLineEdit *lineEditX;
    QLineEdit *lineEditRX;
    QLabel *label_12;
    QLineEdit *lineEditRZ;
    QLabel *label_9;
    QLineEdit *lineEditZ;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *lineEditRY;
    QLineEdit *lineEditElbow;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEditWrist1;
    QLabel *label_5;
    QLineEdit *lineEditWrist3;
    QLineEdit *lineEditWrist2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_Connection;
    QPushButton *pushButton_MoveJ;
    QPushButton *pushButton_SpeedJ;
    QPushButton *pushButton_MoveL;
    QPushButton *pushButton_Samurai;
    QLineEdit *lineEditShoulder;
    QPushButton *pushButton_Home;
    QMenuBar *menuBar;
    QMenu *menuConnection;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(569, 399);
        actionConnection_Info = new QAction(MainWindow);
        actionConnection_Info->setObjectName(QString::fromUtf8("actionConnection_Info"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        lineEditBase = new QLineEdit(centralWidget);
        lineEditBase->setObjectName(QString::fromUtf8("lineEditBase"));

        gridLayout->addWidget(lineEditBase, 1, 3, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        lineEditY = new QLineEdit(centralWidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));

        gridLayout->addWidget(lineEditY, 2, 1, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        lineEditX = new QLineEdit(centralWidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));

        gridLayout->addWidget(lineEditX, 1, 1, 1, 1);

        lineEditRX = new QLineEdit(centralWidget);
        lineEditRX->setObjectName(QString::fromUtf8("lineEditRX"));

        gridLayout->addWidget(lineEditRX, 4, 1, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 5, 0, 1, 1);

        lineEditRZ = new QLineEdit(centralWidget);
        lineEditRZ->setObjectName(QString::fromUtf8("lineEditRZ"));

        gridLayout->addWidget(lineEditRZ, 6, 1, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        lineEditZ = new QLineEdit(centralWidget);
        lineEditZ->setObjectName(QString::fromUtf8("lineEditZ"));

        gridLayout->addWidget(lineEditZ, 3, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        lineEditRY = new QLineEdit(centralWidget);
        lineEditRY->setObjectName(QString::fromUtf8("lineEditRY"));

        gridLayout->addWidget(lineEditRY, 5, 1, 1, 1);

        lineEditElbow = new QLineEdit(centralWidget);
        lineEditElbow->setObjectName(QString::fromUtf8("lineEditElbow"));

        gridLayout->addWidget(lineEditElbow, 3, 3, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 2, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 2, 1, 1);

        lineEditWrist1 = new QLineEdit(centralWidget);
        lineEditWrist1->setObjectName(QString::fromUtf8("lineEditWrist1"));

        gridLayout->addWidget(lineEditWrist1, 4, 3, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 2, 1, 1);

        lineEditWrist3 = new QLineEdit(centralWidget);
        lineEditWrist3->setObjectName(QString::fromUtf8("lineEditWrist3"));

        gridLayout->addWidget(lineEditWrist3, 6, 3, 1, 1);

        lineEditWrist2 = new QLineEdit(centralWidget);
        lineEditWrist2->setObjectName(QString::fromUtf8("lineEditWrist2"));

        gridLayout->addWidget(lineEditWrist2, 5, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 10, 3, 1, 1);

        lineEdit_Connection = new QLineEdit(centralWidget);
        lineEdit_Connection->setObjectName(QString::fromUtf8("lineEdit_Connection"));
        lineEdit_Connection->setEnabled(false);

        gridLayout->addWidget(lineEdit_Connection, 0, 1, 1, 3);

        pushButton_MoveJ = new QPushButton(centralWidget);
        pushButton_MoveJ->setObjectName(QString::fromUtf8("pushButton_MoveJ"));

        gridLayout->addWidget(pushButton_MoveJ, 7, 1, 1, 1);

        pushButton_SpeedJ = new QPushButton(centralWidget);
        pushButton_SpeedJ->setObjectName(QString::fromUtf8("pushButton_SpeedJ"));

        gridLayout->addWidget(pushButton_SpeedJ, 7, 3, 1, 1);

        pushButton_MoveL = new QPushButton(centralWidget);
        pushButton_MoveL->setObjectName(QString::fromUtf8("pushButton_MoveL"));

        gridLayout->addWidget(pushButton_MoveL, 8, 1, 1, 1);

        pushButton_Samurai = new QPushButton(centralWidget);
        pushButton_Samurai->setObjectName(QString::fromUtf8("pushButton_Samurai"));

        gridLayout->addWidget(pushButton_Samurai, 8, 3, 1, 1);

        lineEditShoulder = new QLineEdit(centralWidget);
        lineEditShoulder->setObjectName(QString::fromUtf8("lineEditShoulder"));

        gridLayout->addWidget(lineEditShoulder, 2, 3, 1, 1);

        pushButton_Home = new QPushButton(centralWidget);
        pushButton_Home->setObjectName(QString::fromUtf8("pushButton_Home"));

        gridLayout->addWidget(pushButton_Home, 9, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 21));
        menuConnection = new QMenu(menuBar);
        menuConnection->setObjectName(QString::fromUtf8("menuConnection"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConnection->menuAction());
        menuConnection->addAction(actionConnect);
        menuConnection->addAction(actionSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UR3 Data", nullptr));
        actionConnection_Info->setText(QApplication::translate("MainWindow", "Connection Info", nullptr));
#ifndef QT_NO_SHORTCUT
        actionConnection_Info->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Elbow", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "X", nullptr));
        label->setText(QApplication::translate("MainWindow", "Base", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "RX", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "RY", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Shoulder", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "RZ", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Wrist 1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Wrist 3", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Wrist 2", nullptr));
        lineEdit_Connection->setText(QString());
        pushButton_MoveJ->setText(QApplication::translate("MainWindow", "MoveJ", nullptr));
        pushButton_SpeedJ->setText(QApplication::translate("MainWindow", "SpeedJ", nullptr));
        pushButton_MoveL->setText(QApplication::translate("MainWindow", "MoveL", nullptr));
        pushButton_Samurai->setText(QApplication::translate("MainWindow", "Samurai Cut", nullptr));
        pushButton_Home->setText(QApplication::translate("MainWindow", "Home", nullptr));
        menuConnection->setTitle(QApplication::translate("MainWindow", "Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
