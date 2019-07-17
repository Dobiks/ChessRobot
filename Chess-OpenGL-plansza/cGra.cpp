#include "cGra.h"


using namespace std;

cGra::cGra()
{
	string pole;
	char a = 65;
	for (float x = -1.75; x <= 1.75; x += .5)
	{
		int n = 1;

		for (float y = -1.75; y <= 1.75; y += .5)
		{
			pole = a + std::to_string(n);
			pola[pole][0] = x;
			pola[pole][1] = y;
			n++;

		}
		a++;
	}
	//wieze
	figury.push_back(new cWieza("A1", 0));
	figury.push_back(new cWieza("A8", 1));
	figury.push_back(new cWieza("H1", 0));
	figury.push_back(new cWieza("H8", 1));
	//skoczki
	figury.push_back(new cSkoczek("B1", 0));
	figury.push_back(new cSkoczek("G1", 0));
	figury.push_back(new cSkoczek("B8", 1));
	figury.push_back(new cSkoczek("G8", 1));
	//gonce
	figury.push_back(new cGoniec("C1", 0));
	figury.push_back(new cGoniec("C8", 1));
	figury.push_back(new cGoniec("F8", 1));
	figury.push_back(new cGoniec("F1", 0));
	//krole
	figury.push_back(new cKrol("E1", 0));
	figury.push_back(new cKrol("E8", 1));
	//piony
	for (char a = 65; a <= 73; a++)
	{
		string tmp = a + std::to_string(2);
		string tmp2 = a + std::to_string(7);
		figury.push_back(new cPionek(tmp, 0));
		figury.push_back(new cPionek(tmp2, 1));
	}
	//hetmany
	figury.push_back(new cHetman("D1", 0));
	figury.push_back(new cHetman("D8", 1));
}

void cGra::wybierz_figure(double openglX,double openglY)
{
	for (auto& el : pola) {
		if (openglX > (el.second[0] - 0.25) && openglX<(el.second[0] + 0.25) and openglY>(el.second[1] - 0.25) && openglY < (el.second[1] + 0.25))
		{
			std::string pole = el.first;
			for (auto& el1 : figury)
			{
				if (el1->get_field() == pole)el1->set_active(true);
			}
		}
	}
}

void cGra::przesun_figure(double openglX, double openglY)
{
	bool flag = 0;
	for (auto& el1 :figury)
	{
		if (el1->get_active())
		{
			for (auto& el :pola)
				if (openglX > (el.second[0] - 0.25) && openglX<(el.second[0] + 0.25) and openglY>(el.second[1] - 0.25) && openglY < (el.second[1] + 0.25)) {
					for (auto& el2 :figury)
					{
						if (el2->get_field() == el.first)
						{
							if (el2->get_color() != el1->get_color())
							{
								el2->set_field("del");
								el1->set_field(el.first);
								flag = 1;
								break;
							}
							else
							{
								el1->set_active(false);
								flag = 1;
								break;
							}
						}
					}
					if (flag == 1)
						break;
					if (el1->get_active())
					{
						el1->set_field(el.first);
						break;
					}

				}
		}
		if (flag == 1)
			break;
	}
}



cGra::~cGra()
{
}
