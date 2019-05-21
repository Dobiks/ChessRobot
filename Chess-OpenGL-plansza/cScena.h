#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cProstokat.h"
#include <vector>

void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void timer_binding(int i);
void mouse_motion_binding(int x, int y);

class cScena {
	std::vector<cProstokat*>plansza;
	cProstokat* tlo;
public:
    cScena();
    ~cScena();
    void resize(int width, int height);
    void timer();
    void display();
    void init(int argc, char *argv[], const char* window_name);
    void set_callbacks();
    void key(unsigned char key, int x, int y);
    void mouse_motion_control(int x, int y);

};


#endif //FREEGLUT_CSCENA_H
