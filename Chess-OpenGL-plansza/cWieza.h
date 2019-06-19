#pragma once
#include"cFigura.h"

class cWieza :public cFigura
{

public:
	cWieza(std::string,bool);
	void rysuj();
	bool czy_mozliwy(float, float);

};

