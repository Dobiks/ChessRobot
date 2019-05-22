#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#define NDEBUG
#ifdef __APPLE__
#include "TargetConditionals.h"
#ifdef TARGET_OS_MAC
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
#endif
#elif defined _WIN32 || defined _WIN64
#include <GL\glut.h>
#endif

#include <iostream>
#include <vector>
#include <iostream>
#include <chrono>

class cProstokat{
double a_,b_,x_,y_;

public:
    cProstokat(double a, double b, double x, double y);
    void rysuj(float,float,float);

};


#endif 
