#include <iostream>
#include "cScena.h"

cScena scena;
void resize_binding(int width, int height){
    scena.resize(width,height);
}
void idle_binding(){
    //scena.timer();
}
void timer_binding(int msec){
    scena.timer();
}
void display_binding(){
    scena.display();
}

void key_binding(unsigned char key,int x, int y){
    scena.key(key, x, y);
}
void mouse_motion_binding(int x, int y){
    scena.mouse_motion_control(x,y);
}
void mouse_binding(int button, int state, int x, int y){
    scena.mouse_control(button,state,x,y);
}

int main(int argc, char *argv[])
{
    // it's still possible to use console to print messages



    scena.init(argc,argv,"Okno sceny");
    


    return 0;
}
