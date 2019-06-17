#pragma once

#include <GL/freeglut.h>
#include <string>
class cFigura
{
protected:
	float x_, y_; //pole
	bool kolor_; //0 biale, 1 czarne
    std::string pole;
public:
	cFigura(float, float, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);

};

