#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "UR3Intermediator.h"
#include "connectdialog.h"
#include "chessrobot.h"
#include <QMainWindow>
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<position>Save_position;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void moduleChanged(QObject *object);

private:

    Ui::MainWindow *ui;
    UR3Intermediator* ur3;
    ConnectDialog* connectDialog;
    ChessRobot* board;
    Settings *settings;

public slots:


    void OnConnectedDialogInfo(QString ip, int port);
    void OnMoveJ();
    void OnSpeedJ();
    void OnMoveL();
    void OnSamuraiCut();
    void OnSave();

    void OnActionConnection();
    void Home();

    void OnNewJointPos(QVector<double> pose);
    void OnNewTCP(QVector<double> data, char c);
    void ConnectedToInfo(char* Ip, bool Achieved);

    void showSettings();


};

#endif // MAINWINDOW_H
