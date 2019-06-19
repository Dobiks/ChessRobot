#include "cKrol.h"



cKrol::cKrol(std::string field, bool kolor) :cFigura(field, kolor)
{
}


void cKrol::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(45, 0.0, 0.0, 1.0);

	if (kolor_ == 1) //analogicznie z teksturami
		glColor3d(0, 0, 0);
	else
		glColor3d(0, 1, 0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(.125, .125, 0);
		glVertex3d(.125, -.125, 0);
		glVertex3d(-.125, -.125, 0);
		glVertex3d(-.125, .125, 0);





	}
	glEnd();
	glPopMatrix();
}

bool cKrol::czy_mozliwy(float new_x, float new_y)
{
	return true;
}