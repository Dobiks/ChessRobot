#include "cHetman.h"



cHetman::cHetman(std::string field, bool kolor) :cFigura(field, kolor)
{
}


void cHetman::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(180, 0.0, 0.0, 1.0);

	if (kolor_ == 1) //analogicznie z teksturami
		glColor3d(0, 0, 0);
	else
		glColor3d(0, 1, 0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(0, .125, 0);
		glVertex3d(.125, -.125, 0);
		glVertex3d(-.125, -.125, 0);
	}
	glEnd();
	glPopMatrix();
}

bool cHetman::czy_mozliwy(float new_x, float new_y)
{
	if (abs(new_x - x_) / abs(new_y - y_) == 1||new_x==x_||new_y==y_)
		return true;
	else 
		return false;
}
