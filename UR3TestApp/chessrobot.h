#ifndef CHESSROBOT_H
#define CHESSROBOT_H

#include "UR3Intermediator.h"
#include <stdio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <QVector>


class ChessRobot{

public:
    QVector<position> s; //wektor z punktami
    map<std::string, position> pola;
    position home;

    position Save(UR3Intermediator *ur3); //Zapisanie pozycji robota
    void DrawArea(UR3Intermediator *ur3);
    void addPoint(position a,UR3Intermediator *ur3);
     ChessRobot();
 private:

    //Fields

};
#endif // CHESSROBOT_H
