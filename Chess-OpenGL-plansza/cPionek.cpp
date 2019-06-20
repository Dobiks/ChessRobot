#include "cPionek.h"



cPionek::cPionek(std::string field, bool kolor) :cFigura(field, kolor)
{
}


void cPionek::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	if (kolor_ == 1) //analogicznie z teksturami
		glColor3d(0, 0, 0);
	else
		glColor3d(0, 1, 0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(0, .25, 0);
		glVertex3d(.25, -.25, 0);
		glVertex3d(-.25, -.25, 0);


	}
	glEnd();
	glPopMatrix();
}

bool cPionek::czy_mozliwy(float new_x, float new_y)
{
	//mozna jeszcze dodac ograniczenie przesuwania sie o 1 lub 2 pola
	if (kolor_ == 0 && new_y > y_)
	{
		return true;
	}
	else if (kolor_ == 1 && new_y < y_)
	{

		return true;
	}
	else
		return 0;
}