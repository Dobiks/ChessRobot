#pragma once
#include <GL/freeglut.h>

class cFigura
{
protected:
	float x_, y_; //pole
	bool kolor_; //0 biale, 1 czarne
public:
	cFigura(float, float, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);

};

