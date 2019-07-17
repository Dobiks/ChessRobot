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

    position Save(UR3Intermediator *ur3); //Zapisanie pozycji robota
    void DrawArea();
    bool addPoint(position a);
    bool get_zadania_empty();
    bool check_file(UR3Intermediator *ur3);
    void do_it(UR3Intermediator *ur3);
 private:
    string pole1_last,pole2_last;
    vector<position> s; //wektor z punktami
    map<std::string, position> pola;
    list<string> zadania;
    //Fields
};
#endif // CHESSROBOT_H
