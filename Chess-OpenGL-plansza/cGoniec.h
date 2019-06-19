#pragma once
#include"cFigura.h"
class cGoniec :public cFigura
{

public:
	cGoniec(std::string, bool);
	void rysuj();
	bool czy_mozliwy(float,float);
};

