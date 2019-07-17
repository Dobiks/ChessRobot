#include "chessrobot.h"
#include <cmath>
static double RoundDouble(double val, int prec)
{
    auto precision = pow(10, prec);
    return round(val * precision) / precision;
}
void ChessRobot::do_it(UR3Intermediator *ur3)
{
    if(!zadania.empty()){
        QVector<double> q;
        string polecenie=zadania.front();
        zadania.pop_front();
        q= { pola[polecenie].x , pola[polecenie].y , pola[polecenie].z }; // wspolrzedna punktu 1
        ur3->MoveToPoint(q, 1, 1);
        qDebug() << "Przesuwam do :" << QString::fromStdString(polecenie);
    }
    if(zadania.empty()){
        ofstream ok_wykonano("/Users/jakubczech/Documents/GitHub/ChessRobot/UR3TestApp/wejscie.txt");
              if (ok_wykonano.is_open())
              {
                  ok_wykonano << "ok";
                  qDebug() << "Przesunieto";
                  ok_wykonano.close();
              }

    }


}
bool ChessRobot::addPoint(position tmp){

    s.push_back(tmp);
   if(s.size()==3)return true;
     if(s.size()>3)s.clear();
     return false;

}

bool ChessRobot::get_zadania_empty()
{
    if(zadania.empty()){
        return true;
    }else return false;

}

bool ChessRobot::check_file(UR3Intermediator *ur3)
{
    string pole1, pole2;
       ifstream plik("/Users/jakubczech/Documents/GitHub/ChessRobot/UR3TestApp/wyjscie.txt");
              if (plik.is_open())
              {
                  getline(plik, pole1);
                  getline(plik, pole2);
                  plik.close();
              }
              if (pole1 != pole1_last && pole2 != pole2_last and pole1!="" and pole2!="")
              {
               pole1_last = pole1;
               pole2_last = pole2;
               zadania.push_back(pole1);
               zadania.push_back("home");
               zadania.push_back(pole2);
               zadania.push_back("home");

               if(!ur3->ActualRobotInfo.robotModeData.getIsProgramRunning())this->do_it(ur3);
               return true;
              }
              else return false;


}
position ChessRobot::Save(UR3Intermediator *ur3)
{
    position tmp_point;
    CartesianInfoData CurrentCartesianInfo = ur3->ActualRobotInfo.cartesianInfoData;
    tmp_point.x = (RoundDouble(CurrentCartesianInfo.getX(), 4))*1000;
    tmp_point.y = (RoundDouble(CurrentCartesianInfo.getY(), 4))*1000;
    tmp_point.z = (RoundDouble(CurrentCartesianInfo.getZ(), 4))*1000;
    qDebug()<<"X: "<<tmp_point.x<<" Y: "<<tmp_point.y<<" Z: "<<tmp_point.z;
    return tmp_point;
}


void ChessRobot::DrawArea()
{
    qDebug()<<"Rysuje plansze";
    qDebug() << "Narożnik 1: " << s[0].x << "," << s[0].y << "," << s[0].z;
    qDebug() << "Narożnik 2: " << s[1].x << "," << s[1].y << "," << s[1].z;
    qDebug() << "Narożnik 3: " << s[2].x << "," << s[2].y << "," << s[2].z;
        s[0].x=-200;
        s[0].y=-150;
        s[1].x=-300;
        s[1].y=-150;
    double length = s[0].x - s[1].x;
    double krawedz = abs(length / 8);
    char a = 65;
    string pole;
    position home;

    for (int i = 0; i < 8; i++)
    {
        int n = 1;
        if (i == 3)
            home.x = s[0].x + 4 * krawedz;

        for (int j = 0; j < 8; j++)
        {
            pole = a + std::to_string(n);
            pola[pole].x = s[0].x + j * krawedz + krawedz / 2;
            pola[pole].y = s[0].y + i * krawedz + krawedz / 2;
            pola[pole].z = 0;

            qDebug() << QString::fromStdString(pole) << " X: " << pola[pole].x
                     << " Y:" << pola[pole].y << " Z:" << pola[pole].z;

            if (j == 3)
                home.y = s[0].y + 4 * krawedz;
            n++;
        }
        home.z = 10;
        a++;
    }
    pola["home"].x = home.x;
    pola["home"].y = home.y;
    pola["home"].z = home.z;

    pola["del"].x = s[0].x +150;
    pola["del"].y =s[0].y +150;
    pola["del"].z = s[0].z ;

    qDebug() << "Home "<< " X: " << home.x << " Y:" << home.y << " Z:" << home.z;
}

