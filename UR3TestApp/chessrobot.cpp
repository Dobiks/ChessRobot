#include "chessrobot.h"
#include <cmath>
static double RoundDouble(double val, int prec)
{
    auto precision = pow(10, prec);
    return round(val * precision) / precision;
}

//ChessRobot::ChessRobot()
//{

//}


void ChessRobot::addPoint(position tmp){
    //s.push_back(tmp);

    //if(s.size()==3) this->DrawArea();
     //if(s.size()>3)s.clear();

}
position ChessRobot::Save()
{
    position s;

    CartesianInfoData CurrentCartesianInfo=ActualRobotInfo.getCartesianInfoData();
    s.x = (RoundDouble(CurrentCartesianInfo.getX(), 4))*1000;
    s.y = (RoundDouble(CurrentCartesianInfo.getY(), 4))*1000;
    s.z = (RoundDouble(CurrentCartesianInfo.getZ(), 4))*1000;

//    qDebug()<<s.x;

//        s.push_back(RoundDouble(CurrentCartesianInfo.getRx(),4));
//        s.push_back(RoundDouble(CurrentCartesianInfo.getRy(),4));
//        s.push_back(RoundDouble(CurrentCartesianInfo.getRz(),4));
   return s;
}



void ChessRobot::DrawArea()
{

//    qDebug() << "Narożnik : " << s[0].x << "," << s[0].y << "," << s[0].z;
//    qDebug() << "Narożnik : " << s[1].x << "," << s[1].y << "," << s[1].z;
//    qDebug() << "Narożnik : " << s[2].x << "," << s[2].y << "," << s[2].z;
//        s[0].x=-200;
//        s[0].y=-150;
//        s[1].x=-300;
//        s[1].y=-150;
//    // double lewa,prawa,przod,tyl,poziom;
//    double length = s[0].x - s[1].x;
//    double krawedz = abs(length / 8);
//    map<std::string, position> pola;
//    char a = 65;
//    string pole;

//    for (int i = 0; i < 8; i++)
//    {
//        int n = 1;
//        if (i == 3)
//            home.x = s[0].x + 4 * krawedz;

//        for (int j = 0; j < 8; j++)
//        {
//            pole = a + std::to_string(n);
//            pola[pole].x = s[0].x + j * krawedz + krawedz / 2;
//            pola[pole].y = s[0].y + i * krawedz + krawedz / 2;
//            pola[pole].z = 0;

//            qDebug() << QString::fromStdString(pole) << " X: " << pola[pole].x
//                     << " Y:" << pola[pole].y << " Z:" << pola[pole].z;

//            if (j == 3)
//                home.y = s[0].y + 4 * krawedz;
//            n++;
//        }
//        home.z = 10;
//        a++;
//    }
//    int h = 0;

//    qDebug() << "Home "
//             << " X: " << home.x << " Y:" << home.y << " Z:" << home.z;
//    QVector<double> home_v{ home.x , home.y , home.z };
//    while (_running == true)
//    {
//        h++;
//        qDebug() << "Trwa ruch";
//        this->CheckIfStillMovejRunning();
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        if (h > 300)
//            break;
//    }
//    this->MoveToPoint(home_v, 1, 1);
//    string pole1, pole2, pole1_last = "a", pole2_last = "b";


//    while (true)
//    {
//        ifstream plik("/Users/jakubczech/Documents/GitHub/ChessRobot/UR3TestApp/wyjscie.txt");
//        if (plik.is_open())
//        {
//            getline(plik, pole1);
//            getline(plik, pole2);
//            plik.close();
//        }
//        if (pole1 != pole1_last && pole2 != pole2_last and pole1!="" and pole2!="")
//        { // sprawdzenie czy ruch nie zostal wykonany


//            QVector<double> q{ pola[pole1].x , pola[pole1].y , pola[pole1].z }; // wspolrzedna punktu 1
//            h = 0;
//            while (_running == true)
//            {
//                h++;
//                qDebug() << "Trwa ruch do home";
//                this->CheckIfStillMovejRunning();
//                std::this_thread::sleep_for(std::chrono::milliseconds(100));
//                if (h > 300)
//                    break;
//            }
//            this->MoveToPoint(q, 1, 1);


//            // pionek podniesiony teraz idz do home
//            h = 0;
//            while (_running == true)
//            {
//                h++;
//                qDebug() << "Trwa ruch do home";
//                this->CheckIfStillMovejRunning();
//                std::this_thread::sleep_for(std::chrono::milliseconds(100));
//                if (h > 300)
//                    break;
//            }
//            this->MoveToPoint(home_v, 1, 1);


//            qDebug() << "Przesuwam z :" << QString::fromStdString(pole1) << " do "
//                     << QString::fromStdString(pole2);



//        if (pole2 == "del")
//        {
//            // usuniecie pionka z planszy
//            h = 0;
//            while (_running == true)
//            {
//                qDebug() << "Trwa ruch2";
//                h++;
//                this->CheckIfStillMovejRunning();
//                std::this_thread::sleep_for(std::chrono::milliseconds(100));
//                if (h > 300)
//                    break;
//            }
//            q = { s[0].x +150, s[0].y +150, s[0].z };
//            this->MoveToPoint(q, 1, 1);
//        }
//        else
//        {
//            h = 0;
//            while (_running == true)
//            {
//                h++;
//                qDebug() << "Trwa ruch3";
//                this->CheckIfStillMovejRunning();
//                std::this_thread::sleep_for(std::chrono::milliseconds(100));
//                if (h > 300)
//                    break;
//            }
//            q = { pola[pole2].x  , pola[pole2].y  , pola[pole2].z };
//            this->MoveToPoint(q, 1, 1);
//        }
//        h = 0;
//        while (_running == true)
//        {
//            h++;
//            qDebug() << "Trwa ruch4";
//            this->CheckIfStillMovejRunning();
//            std::this_thread::sleep_for(std::chrono::milliseconds(100));
//            if (h > 300)
//                break;
//        }
//        pole1_last = pole1;
//        pole2_last = pole1;
//        this->MoveToPoint(home_v, 1, 1);
//        h = 0;
//        while (_running == true)
//        {
//            h++;
//            qDebug() << "Trwa ruch5";
//            this->CheckIfStillMovejRunning();
//            std::this_thread::sleep_for(std::chrono::milliseconds(100));
//            if (h > 300)
//                break;
//        }
//        ofstream ok_wykonano("/Users/jakubczech/Documents/GitHub/ChessRobot/UR3TestApp/wejscie.txt");
//        if (ok_wykonano.is_open())
//        {
//            ok_wykonano << "ok";
//            qDebug() << "Przesunieto";
//            ok_wykonano.close();
//        }

//    }
//}
//// koniec gry
}


