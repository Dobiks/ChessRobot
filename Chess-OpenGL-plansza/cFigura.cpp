#include "cFigura.h"



cFigura::cFigura(std::string field,bool kolor):field_(field),kolor_(kolor)
{
	{ //przypisywanie x_ i y_ na podstawie stringa podanego w argumencie
		std::string tmp;
		char a = 65;
		for (float x = -1.75; x <= 1.75; x += .5)
		{
			int n = 1;

			for (float y = -1.75; y <= 1.75; y += .5)
			{
				tmp = a + std::to_string(n);
				if (field_ == tmp)
				{
					x_ = x;
					y_ = y;
				}
				n++;
			}
			a++;
		}
	}
}

void cFigura::przesun(float x,float y)
{
	x_ = x;
	y_ = y;
}
