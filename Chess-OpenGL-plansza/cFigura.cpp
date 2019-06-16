#include "cFigura.h"



cFigura::cFigura(float x,float y,bool kolor):x_(x),y_(y),kolor_(kolor)
{

}

void cFigura::przesun(float x,float y)
{
	x_ = x;
	y_ = y;
}
