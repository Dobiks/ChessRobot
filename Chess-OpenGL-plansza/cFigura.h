#pragma once

#include <GL/freeglut.h>
#include <string>
class cFigura
{
protected:
	float x_, y_; //pole
	bool kolor_; //0 biale, 1 czarne
    std::string pole_;
    bool aktyw_=0;
public:
    friend class cScena;
    cFigura(float, float,std::string, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);

};

