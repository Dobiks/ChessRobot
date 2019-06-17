#pragma once
#ifndef __apple__
#include <GLUT/GLUT.h>
#elif _WIN32
#include <GL/freeglut.h>
#endif
class cProstokat{
double a_,b_,x_,y_;

public:
    cProstokat(double a, double b, double x, double y);
    void rysuj(float,float,float);

};

 
