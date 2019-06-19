#include "cGoniec.h"



cGoniec::cGoniec(std::string field, bool kolor) :cFigura(field, kolor)
{
}


void cGoniec::rysuj() {
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
		glVertex3d(.25, .125, 0);
		glVertex3d(-.25, .125, 0);
		glVertex3d(-.25, -.125, 0);
		glVertex3d(.25, -.125, 0);

	}
	glEnd();
	glPopMatrix();
}

bool cGoniec::czy_mozliwy(float new_x,float new_y)
{
	float a = abs(new_x - x_) / abs(new_y - y_);
	if (a == 1)
		return true;
	else
		return false;
}

