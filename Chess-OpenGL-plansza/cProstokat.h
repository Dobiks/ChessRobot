#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#ifndef __apple__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
class cProstokat{
double a_,b_,x_,y_;

public:
    cProstokat(double a, double b, double x, double y);
    void rysuj(float,float,float);

};


#endif 
