#include "physics.h"
#include <random>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
mutex mt;
physics::physics()
 {//	bool col=false;
}


void physics::wall(Ball *a)
{
		if(a->ballcenx>a->ballyMax)
	{
		a->ballcenx=a->ballxMax;
		a->xspeed= -a->xspeed;
	}
	else	if(a->ballcenx < a->ballxMin){
		a->ballcenx=a->ballxMin;
		a->xspeed= -a->xspeed;
	}
	if(a->ballceny>a->ballyMax){
		a->ballceny=a->ballyMax;
		a->yspeed= -a->yspeed;
	}
	else	if(a->ballceny<a->ballyMin){
		a->ballceny=a->ballyMin;
		a->yspeed= -a->yspeed;
	}
		if(a->ballcenz>a->ballzMax)
{	a->ballcenz=a->ballzMax;
		a->zspeed= -a->zspeed;
	}
	else	if(a->ballcenz < a->ballzMin){
		a->ballcenz=a->ballzMin;
		a->zspeed= -a->zspeed;
	}

}
void physics::terrlimit(terrain *b)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine gtw(seed);
	uniform_real_distribution<float> z(-3.0,-6.0);
	if(b->fixZ<-5 or b->fixZ>-2)
	{
		
		b->fixZ =z(gtw);
	}
}
void physics::terr(Ball *a,terrain *b)
{GLfloat x=a->ballcenx - b->fixX;
			GLfloat y=a->ballceny - b->fixY;
			GLfloat z=a->ballcenz - b->fixZ;
			GLfloat distance= sqrt(x*x + y*y +z*z );
			GLfloat radius = a->ballRadius + b->fixR;
if(radius+0.02>=distance)
{
a->xspeed=-a->xspeed;
a->yspeed=-a->yspeed;
a->zspeed=-a->zspeed;
if(distance<2*a->ballRadius)
{
a->ballcenx = a->ballcenx-0.05;
a->ballceny = a->ballceny-0.05;
a->ballcenz = a->ballcenz+0.05;
}
}
terrlimit(b);
}
void  physics::collision(Ball* a,Ball* b)
	{
			GLfloat x=a->ballcenx - b->ballcenx;
			GLfloat y=a->ballceny - b->ballceny;
			GLfloat z=a->ballcenz - b->ballcenz;
			GLfloat distance= sqrt(x*x + y*y +z*z );
			GLfloat radius = a->ballRadius + b->ballRadius;
			//std:: cout <<distance<<"float1"<<"\n\n";
	// for(int i=0;i<2;i++){
	// 	for(int j=i;j<2;j++){
	// 		if(radius<=distance){
	// 		arr[i][j]=true;	
	// 		}
	// 		else continue;
	// 	}
	// }

	// for(int i=0;i<2;i++){
	// 	for(int j<2;j++){
	// 		if(arr[i][j]==true){
	// 			arr[i][j]=false;
	// 			reverse (a,b);
	// 		}
	// 	}
	// }
//mt.lock();
if(radius+0.02>=distance)
{
resolve(a,b);
if(distance<2*a->ballRadius)
{
a->ballcenx = a->ballcenx-0.1;
a->ballceny = a->ballceny-0.1;
a->ballcenz = a->ballcenz+0.1;
}
}
else
{
//triangle(a);
//triangle(b);
wall(a);
wall(b);
}//mt.unlock();
}
void physics::resolve(Ball *a,Ball *b)
{
//doo=collision(a,b);
//std::thread t1(alc,a,b);
//t1.join();
//mt.lock();	
	GLfloat tempx = a->xspeed;
	a->xspeed=  b->xspeed;
	b->xspeed = tempx;
	// std::cout<<"X=> "<<a->ballcenx<<std::endl;
	GLfloat tempy = a->yspeed;
	a->yspeed =  b->yspeed;
	b->yspeed =  tempy;
	GLfloat tempz = a->zspeed;
	a->zspeed =  b->zspeed;
	b->zspeed =  tempz;
	
//while(doo==1)
//co++;
	// std::cout<<"Y=> "<<b->ballcenx<<std::endl;
}
