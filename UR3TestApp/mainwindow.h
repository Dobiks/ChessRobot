#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "UR3Intermediator.h"
#include "connectdialog.h"
#include "chessrobot.h"
#include <QMainWindow>
#include "settings.h"
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void moduleChanged(QObject *object);

private:
    UR3Intermediator* ur3;

    Ui::MainWindow *ui;
    ConnectDialog* connectDialog;

    // dodane do projektu
    QTimer *timer;
    ChessRobot *board;
    //koniec
    Settings *settings;

public slots:


    void OnConnectedDialogInfo(QString ip, int port);
    void OnMoveJ();
    void OnSpeedJ();
    void OnMoveL();
    void OnSamuraiCut();

    // dodane do projektu
    void timer_game();
    void OnSave( );
    //koniec

    void OnActionConnection();
    void Home();
    void OnNewJointPos(QVector<double> pose);
    void OnNewTCP(QVector<double> data, char c);
    void ConnectedToInfo(char* Ip, bool Achieved);
    void showSettings();
};

#endif // MAINWINDOW_H
