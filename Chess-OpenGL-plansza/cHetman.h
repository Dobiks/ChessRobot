#pragma once
#include"cFigura.h"
class cHetman :public cFigura
{

public:
	cHetman(std::string, bool);
	void rysuj();
	bool czy_mozliwy(float, float);

};

