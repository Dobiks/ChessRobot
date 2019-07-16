#ifndef CHESSROBOT_H
#define CHESSROBOT_H

#include "UR3Intermediator.h"
#include <stdio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <QVector>
#include <vector>


class ChessRobot{

public:
    vector<position> s; //wektor z punktami
    map<std::string, position> pola;
    position *home;
    position Save(UR3Intermediator *ur3); //Zapisanie pozycji robota
    void DrawArea();
    bool addPoint(position a);
     ChessRobot();
    void game(UR3Intermediator *ur3);
 private:

    //Fields

};
#endif // CHESSROBOT_H
