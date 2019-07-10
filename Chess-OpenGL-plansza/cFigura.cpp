#include "cFigura.h"

using namespace std;

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

bool wyslij(string pole1, string pole2)
{
	ofstream plik("wyjscie.txt");

	if (plik.is_open())
	{
		plik << pole1 << endl << pole2;
		plik.close();
	}

	string tmp;
	while (true)
	{
		fstream ok("wejscie.txt", ios::in);
		ok >> tmp;
		if (tmp == "ok")
			break;
		else
			ok.close();
		Sleep(5000);
	}
	ofstream ok_wykonano("wejscie.txt");
	if (ok_wykonano.is_open())
		ok_wykonano << "wykonano";
	ok_wykonano.close();
	
	return 1;
}

void cFigura::set_field(std::string pole)
{
	if (pole == "del")
	{
		wyslij(field_, pole);
		x_ = 2.5;
		y_ = 0;
		field_ = "del";
	}
	else
	{
		wyslij(field_, pole);
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
}



//void cFigura::usun()
//{
//	x_ = 2.5;
//	y_ = 0;
//	field_ = "del";
//}

bool cFigura::get_active()
{
	return aktyw_;
}

bool cFigura::get_color()
{
	return kolor_;
}

std::string cFigura::get_field()
{
	return field_;
}


