#pragma once
#include"cFigura.h"
class cKrol :public cFigura
{

public:
	cKrol(std::string, bool);
	void rysuj();
	bool czy_mozliwy(float, float);

};

