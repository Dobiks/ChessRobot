#pragma once
#include"cFigura.h"
class cPionek :public cFigura
{

public:
	cPionek(std::string, bool);
	void rysuj();
	bool czy_mozliwy(float, float);

};

