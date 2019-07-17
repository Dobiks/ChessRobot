#pragma once
#include "cProstokat.h"
#include "cFigura.h"
#include "cWieza.h"
#include "cSkoczek.h"
#include "cGoniec.h"
#include "cKrol.h"
#include "cPionek.h"
#include "cHetman.h"
#include <vector>
#include <map>
#include <string>

class cGra
{
	friend class cScena;
	std::map<std::string, float[2]>pola;
	std::vector<cFigura*>figury;
	cGra();
	void wybierz_figure(double,double);//do przesuniecia
	void przesun_figure(double, double);
	~cGra();
};

