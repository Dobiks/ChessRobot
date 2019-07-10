#pragma once
#ifdef _WIN32 || defined _WIN64
#include <GL/freeglut.h>
#else
#include <GLUT/GLUT.h>
#endif
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
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
	virtual bool czy_mozliwy(float,float) = 0;
	void przesun(float,float);
	void set_active(bool);
	void set_field(std::string);
	//void usun();
	bool get_active();
	bool get_color();
	std::string get_field();
};

