#include "cFigura.h"



cFigura::cFigura(std::string field, bool kolor) :field_(field), kolor_(kolor)
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

void cFigura::przesun(float x, float y)
{
	x_ = x;
	y_ = y;
}

void cFigura::set_active(bool aktywny)
{
	aktyw_ = aktywny;
}

void cFigura::set_field(std::string pole)
{

	field_ = pole;
	std::string tmp;
	char a = 65;
	for (float x = -1.75; x <= 1.75; x += .5)
	{
		int n = 1;

		for (float y = -1.75; y <= 1.75; y += .5)
		{
			tmp = a + std::to_string(n);
			if (field_ == tmp && czy_mozliwy(x, y))
			{

				x_ = x;
				y_ = y;
				set_active(0);

			}
			n++;
		}
		a++;
	}
}

bool cFigura::get_active()
{
	return aktyw_;
}

std::string cFigura::get_field()
{
	return field_;
}


