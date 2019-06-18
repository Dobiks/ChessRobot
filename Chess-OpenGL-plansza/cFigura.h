#pragma once
#ifdef _WIN32 || defined _WIN64
#include <GL/freeglut.h>
#else
#include <GLUT/GLUT.h>
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


	cFigura(std::string, bool);
	virtual void rysuj() = 0;
	void przesun(float,float);
	void set_active(bool);
	void set_field(std::string);
	bool get_active();
	std::string get_field();
};

