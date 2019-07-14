#ifndef CHESSROBOT_H
#define CHESSROBOT_H

#include "UR3Intermediator.h"
#include <stdio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <QVector>


class ChessRobot: UR3Intermediator
{

public:

    position home;
    QVector<position> s; //wektor z punktami
    position Save(); //Zapisanie pozycji robota
    void DrawArea();
    void addPoint(position a);
 private:

    //Fields

};
#endif // CHESSROBOT_H
