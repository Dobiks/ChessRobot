#include "cSkoczek.h"



cSkoczek::cSkoczek(float x, float y,std::string pole, bool kolor) :cFigura(x, y, pole, kolor)
{
}


void cSkoczek::rysuj() {
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
		glVertex3d(.125, .125, 0);
		glVertex3d(-.125, .125, 0);
		glVertex3d(-.125, -.125, 0);
		glVertex3d(.125, -.125, 0);

	}
	glEnd();
	glPopMatrix();
}

