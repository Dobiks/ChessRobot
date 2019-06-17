#pragma once
#ifdef _APPLE_
#include <GLUT/GLUT.h>
#elif defined _WIN32 || defined _WIN64
#include <GL/freeglut.h>
#endif
#include <iostream>
#include <string>
#include <map>
class cFigura
{
protected:
	float x_, y_; //pole
	bool kolor_; //0 biale, 1 czarne
    std::string field_;
    bool aktyw_=0;
public:
    friend class cScena;

	cFigura(std::string, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);

};

