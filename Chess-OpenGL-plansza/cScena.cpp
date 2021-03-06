#include "cScena.h"
#include <iostream>
#include <chrono>
#include <cmath>


using std::string;
cScena::cScena()
{
	tlo = new cProstokat(4, 4, 0, 0);
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
		for (auto& el : gra.figury)
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
	glutTimerFunc(40, timer_binding, 0);
	glutMouseFunc(mouse_binding);
}

void cScena::init(int argc, char **argv, const char *window_name) {

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	glClearColor(0.2, 0.2, 0.2, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	set_callbacks();

	glutMainLoop();
}

void cScena::mouse_control(int button, int state, int x, int y) {
	double openglX = ((double)x - window_width / 2) / window_width * 6.68;
	double openglY = -((double)y - window_heigth / 2) / window_heigth * 5;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		gra.wybierz_figure(openglX, openglY);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		gra.przesun_figure(openglX, openglY);
	}
}

cScena::~cScena()
{

}

