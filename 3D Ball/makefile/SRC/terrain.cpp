#include "terrain.h"
#include <random>
#include <GL/glut.h>
#include <iostream>
#include <chrono>
using namespace std;

terrain:: terrain()
{unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine gtw(seed);
uniform_real_distribution<float> a(-1,1);
uniform_real_distribution<float> z(-3.0,-6.0);
fixX =a(gtw);
uniform_real_distribution<float> r(0.26,0.55);
xSpeed=0.01;
	fixY =-1.4;
	fixZ =z(gtw);
	fixR =r(gtw);}
void terrain::ballch()
{
	/*const GLfloat light_ambient[] = {0.3f,0.3f,0.3f,1.0f};
	const GLfloat light_diffuse[] = {1.0f,1.0f,1.0f,1.0f};
	const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
	const GLfloat light_position[] = {2.0f,6.0f,5.0f,0.0f};*/
	const GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
	const GLfloat mat_diffuse[] = {0.8f,0.8f,0.8f,1.0f};
	const GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
	const GLfloat high_shininess[] = {100.0f};

		glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);

        /*glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);*/

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
 glTranslatef(fixX,fixY,fixZ);
	glColor3f(0.5,0.5,0.5);
	gluLookAt(  tx, 0.0f, tz,
            tx+tlx, 0.0f,  tz+tlz,
            0.0f, 1.0f,  0.0f);
	glutSolidSphere(fixR,20,20);
transl();
}
void terrain::transl()
{
fixX=fixX-xSpeed;
if(fixX<-2)
fixX=2;
}   



