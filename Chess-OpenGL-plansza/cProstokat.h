#pragma once
#ifdef _WIN32 || defined _WIN64
#include <GL/freeglut.h>
#else
#include <GLUT/GLUT.h>
#endif
class cProstokat{
double a_,b_,x_,y_;

public:
    cProstokat(double a, double b, double x, double y);
    void rysuj(float,float,float);

};

 
