#include "cScena.h"
#include <iostream>
#include <chrono>


using std::string;
cScena::cScena()
{
	tlo = new cProstokat(4, 4, 0, 0);
	string pole;
	char a = 65;

	for (float x = -1.75; x <= 1.75; x += .5)
	{
		int n = 1;

		for (float y = -1.75; y <= 1.75; y += .5)
		{
			pole = a + std::to_string(n);
			pola[pole][0] = x;
			pola[pole][1] = y;
			n++;

		}
		a++;
	}
	
	{
		//wieze
		figury.push_back(new cWieza("A1", 0));
		figury.push_back(new cWieza("A8", 1));
		figury.push_back(new cWieza("H1", 0));
		figury.push_back(new cWieza("H8", 1));
		//skoczki
		figury.push_back(new cSkoczek("B1", 0));
		figury.push_back(new cSkoczek("G1", 0));
		figury.push_back(new cSkoczek("B8", 1));
		figury.push_back(new cSkoczek("G8", 1));
		//gonce
		figury.push_back(new cGoniec("C1", 0));
		figury.push_back(new cGoniec("C8", 1));		
		figury.push_back(new cGoniec("F8", 1));
		figury.push_back(new cGoniec("F1", 0));


	}
		for (float j = 1.75; j > -2.25; j--)
		{
			for (float i = -1.25; i <= 1.75; i++)
			{
				plansza.push_back(new cProstokat(0.5, 0.5, i, j));
				plansza.push_back(new cProstokat(0.5, 0.5, i - 0.5, j - 0.5));
			}
		}
}

void cScena::resize(int width, int height) {
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void cScena::timer() {



	glutPostRedisplay();
	glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		//Figury:
		for (auto& el : figury)
		{
			el->rysuj();
		}
		//Plansza:
		for (auto& el : plansza)
		{
			el->rysuj(0, 0, .75);
		}

		tlo->rysuj(1, 1, 1);
       
	}

	glPopMatrix();
	glutSwapBuffers();
}


void cScena::set_callbacks() {
	glutReshapeFunc(resize_binding);
	glutDisplayFunc(display_binding);
	//glutIdleFunc(idle_binding);
	glutTimerFunc(40, timer_binding, 0);
	glutKeyboardFunc(key_binding);
	glutPassiveMotionFunc(mouse_motion_binding);
    glutMouseFunc(mouse_binding);


}

void cScena::init(int argc, char **argv, const char *window_name) {

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(0, 0, 0, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	set_callbacks();

	glutMainLoop();
}

void cScena::key(unsigned char key, int x, int y)
{

}

cScena::~cScena()
{

}
void cScena::mouse_control(int button, int state, int x, int y){
    double openglX = ((double)x - window_width/2) / window_width * 6.68;
    double openglY = -((double)y - window_heigth/2) / window_heigth * 5;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        for(auto& el: pola){
            if(openglX>(el.second[0]-0.25) && openglX<(el.second[0]+0.25) and openglY>(el.second[1]-0.25) && openglY<(el.second[1]+0.25) ){std::string pole=el.first;
                for(auto& el: figury){
                    if (el->field_==pole)el->aktyw_=true;
                }
            }
        }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        for(auto& el1: figury)
            if(el1->aktyw_)
            {
                for(auto& el: pola)
                    if(openglX>(el.second[0]-0.25) && openglX<(el.second[0]+0.25) and openglY>(el.second[1]-0.25) && openglY<(el.second[1]+0.25) ){
                        el1->field_=el.first;
                        el1->x_=el.second[0];
                        el1->y_=el.second[1];
                        el1->aktyw_=0;
                    }
            }
}

void cScena::mouse_motion_control(int x, int y){
    double openglX = ((double)x - window_width/2) / window_width * 6.68;
    double openglY = -((double)y - window_heigth/2) / window_heigth * 5;
}

