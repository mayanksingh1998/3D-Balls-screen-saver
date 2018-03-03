//clude <GL/glut.h>
#include "Ball.h"
#include "terrain.h"
class physics{

	public:
		float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=0.0f;

	//bool arr[2][2]={false};	
    void collision(Ball* a,Ball* b);
	void wall(Ball* a);
	void resolve(Ball* a,Ball* b);
    void terr(Ball* a,terrain *b);
	physics();
	void terrlimit(terrain *b);
};
