#include "cFigura.h"



cFigura::cFigura(float x,float y,std::string pole,bool kolor):x_(x),y_(y),pole_(pole),kolor_(kolor)
{

}

void cFigura::przesun(float x,float y)
{
	x_ = x;
	y_ = y;
}
