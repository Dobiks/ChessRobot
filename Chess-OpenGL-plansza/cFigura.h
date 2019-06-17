#pragma once
#ifndef __apple__
#include <GLUT/GLUT.h>
#else
#include <GL/freeglut.h>
#endif
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

