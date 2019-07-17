#include "cSkoczek.h"



cSkoczek::cSkoczek(std::string field, bool kolor) :cFigura(field, kolor)
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

bool cSkoczek::czy_mozliwy(float new_x, float new_y)
{
	float warunekx;
	float waruneky;
	if (new_x > x_)
		warunekx = abs(new_x - x_);
	else
		warunekx = abs(x_ - new_x);
	if (new_y > y_)
		waruneky = abs(new_y - y_);
	else
		waruneky = abs(y_ - new_y);
	if ((warunekx == 1 || waruneky == 1)&&new_x!=x_&&new_y!=y_)
		return 1;
	else
		return 0;
}