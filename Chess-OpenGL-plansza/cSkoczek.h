#pragma once
#include"cFigura.h"
class cSkoczek :public cFigura
{

public:
	cSkoczek(std::string, bool);
	void rysuj();
	bool czy_mozliwy(float, float);

};

