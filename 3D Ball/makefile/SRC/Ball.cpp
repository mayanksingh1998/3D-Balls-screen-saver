#include "Ball.h"
#include <random>
#include <GL/glut.h>
#include <iostream>
#include <chrono>

//#include "physics.h"
using namespace std;
Ball::Ball()
{unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine getw(seed);
uniform_real_distribution<float> a(0.1,0.3);
uniform_real_distribution<float> s(0.01,0.09);
uniform_real_distribution<float> b(-1.0f,1.0f);
uniform_real_distribution<float> c(0.0f,1.0f);
uniform_real_distribution<float> zz(-2.0f,-5.0f);

float colf=b(getw);
cola=c(getw);
colb=c(getw);
 xspeed=s(getw);
 yspeed=s(getw);
zspeed=s(getw);
 ballceny=b(getw);
 ballcenz=zz(getw);
 ballcenx=b(getw);
 // Mass=a(getw);
}

 void Ball::translate()
  {
float redc=0.05;
 	ballcenx=ballcenx+xspeed;
	ballceny=ballceny+yspeed;
	ballcenz=ballcenz-zspeed;
    
	//if(ballceny>ballyMax){
	// 	ballceny=ballyMax;
	// 	yspeed= -yspeed;
	// }
	// else	if(ballceny<ballyMin){
	// 	ballceny=ballyMin;
	// 	yspeed= -yspeed;
	// }

 }
void Ball::ballmaker()
{
	GLfloat light_ambient[] = {0.2f,0.2f,0.2f,1.0f};
	GLfloat light_diffuse[] = {0.8f,0.5f,1.0f,1.0f};
	const GLfloat light_specular[] = {0.7f,0.7f,0.7f,1.0f};
	const GLfloat light_position[] = {0.0f,0.0f,0.0f,1.0f};
	const GLfloat mat_ambient[] = {0.5f,0.6f,0.7f,1.0f};
	const GLfloat mat_diffuse[] = {0.6f,0.7f,0.8f,1.0f};
	const GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
	const GLfloat high_shininess[] = {50.0f};

		glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);

        glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


	glLoadIdentity();
//glMatrixMode(GL_MODELVIEW);
 glTranslatef(ballcenx,ballceny,ballcenz);
	glColor3f(cola+0.1,colb+0.2,cola+colb);
gluLookAt(  px, 0.0f, pz,
            px+plx, 0.0f,  pz+plz,
            	0.0f, 1.0f,  0.0f);

glutSolidSphere(ballRadius,20,20);
glScalef(1.0,1.0,1.0);
translate();
}
