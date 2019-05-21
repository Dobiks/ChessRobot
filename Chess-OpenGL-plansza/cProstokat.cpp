#include "cProstokat.h"

cProstokat::cProstokat(double a, double b, double x, double y) :x_(x),y_(y), a_(a), b_(b) {

}

void cProstokat::rysuj(float r,float g,float b) {
    glPushMatrix();

    glTranslated(x_, y_, 0.0);
    glRotated(0, 1.0, 0.0, 0.0);
    glRotated(0, 0.0, 1.0, 0.0);
    glRotated(0, 0.0, 0.0, 1.0);

    glColor3d(r,g,b);

    glBegin(GL_POLYGON);
    {
        glVertex3d(-a_ / 2, b_ / 2, 0);
        glVertex3d(a_ / 2, b_ / 2, 0);
        glVertex3d(a_ / 2, -b_ / 2, 0);
        glVertex3d(-a_ / 2, -b_ / 2, 0);
    }
    glEnd();
    glPopMatrix();
}

