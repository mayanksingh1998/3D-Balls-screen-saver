#include <GL/glut.h>
class Ball{
public:
	float pangle=0.0;
// actual vector representing the camera's direction
float plx=0.0f,plz=-1.0f;
// XZ position of the camera
float px=0.0f,pz=0.0f;
GLfloat ballRadius=0.18f;
GLfloat ballcenx;
GLfloat ballceny;
GLfloat ballcenz;
// GLfloat Mass; 
GLfloat ballxMax=1.0f;
GLfloat ballxMin=-1.0f;
GLfloat ballyMax=1.0f;
GLfloat ballyMin=-1.0f;
GLfloat ballzMax=-2.0f;
GLfloat ballzMin=-5.0f;
GLfloat xspeed;	// speed in x and y dir
GLfloat yspeed;
float zspeed;
float cola,colb;
Ball(Ball *a);

Ball();

void translate();

void ballmaker();
};
