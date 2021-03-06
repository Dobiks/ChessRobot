#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cProstokat.h"
#include "cFigura.h"
#include "cWieza.h"
#include "cSkoczek.h"
#include "cGoniec.h"
#include "cKrol.h"
#include "cPionek.h"
#include "cHetman.h"
#include "cGra.h"
#include <vector>
#include <map>
#include <string>
#define window_width 800
#define window_heigth 600
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void timer_binding(int i);
void mouse_binding(int button, int state, int x, int y);

class cScena {
	cGra gra;
	//std::vector<cFigura*>figury;
	std::vector<cProstokat*>plansza;
	cProstokat* tlo;
public:
   // std::map<std::string, float[2]>pola;
	cScena();
	~cScena();
	void resize(int width, int height);
	void timer();
	void display();
	void init(int argc, char *argv[], const char* window_name);
	void set_callbacks();
    void mouse_control(int button, int state, int x, int y);


};


#endif //FREEGLUT_CSCENA_H
