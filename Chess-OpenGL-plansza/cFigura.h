#pragma once

#include <GL/freeglut.h>
#include <string>
#include <map>
class cFigura
{
protected:
	float x_, y_; //pole
	bool kolor_; //0 biale, 1 czarne
    std::string field_;
public:
	cFigura(std::string, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);

};

