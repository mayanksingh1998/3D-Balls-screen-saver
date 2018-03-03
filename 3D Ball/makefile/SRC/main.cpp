//#include "Ball.h"
#include <thread>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <mutex>
#include "physics.h"
#include "Vector.h"
#define FILE_PATH "tst.wav"
//#include "camera.h"
// float angle=0.0;
// // actual vector representing the camera's direction
// float lx=0.0f,lz=-1.0f;
// // XZ position of the camera
// float x=0.0f,z=0.0f;
//#include "camera.h"
void initGL(){
	glClearColor(0.0,0.0,0.0,0.1);  //set clor to blk
}
int n;
int WindowWidth = 640;
int WindowHeight = 480;
int WindowPosx = 50;
int WindowPosy=50;
int refresh = 30; //refresh period in ms

const GLfloat light_ambient[] = {0.0f,0.0f,0.0f,1.0f};
const GLfloat light_diffuse[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat light_position[] = {2.0f,5.0f,5.0f,0.0f};
const GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
const GLfloat mat_diffuse[] = {0.8f,0.8f,0.8f,1.0f};
const GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
const GLfloat high_shininess[] = {100.0f};
 
 //projection clipping area
GLdouble clipAreaxleft,clipAreaxRight,clipAreayBottom,clipAreayTop;
std::mutex mtx;
terrain t[8];
physics p;
void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}
//terrain t;
// void ballmaker(Ball b)
// {
// 	glLoadIdentity();
// glMatrixMode(GL_MODELVIEW);
//  glTranslatef(b.ballcenx,b.ballceny,0.0f);
// 	glColor3f(b.col,b.col,b.col);
// // 	glutWireSphere(b.ballRadius,20,20);}
// Ball b2;
// Ball b1;
// Ball b3;
// Ball b4;
// Ball b5;
Ball b[1000];
// void phys(Ball *a,Ball *b)
// {
// 	p.collision(&a,&b);
// }
void drawWalls()
{


glPushMatrix();
//glRotatef(0,0,0,1);
//glScalef(2,1,2);
gluLookAt(  p.x, 0.0f, p.z,
            p.x+p.lx, 0.0f,  p.z+p.lz,
            0.0f, 1.0f,  0.0f);
glBegin(GL_QUADS);
/* Floor */
/*glColor3f(1.0,0.0,0.0);
glVertex3f(-1, -1, -1);
glVertex3f(-1, -1, 1);
glVertex3f(1, -1, 1);
glVertex3f(1, -1, -1);
/* Ceiling 
*/
glColor3f(0.3,0.1,1.0);
glVertex3f(-1,1,-1);
glVertex3f(1,1,-1);
glVertex3f(1,1,1);
glVertex3f(-1,1,1);
    /* Walls */
glColor3f(0.5,1.0,0.0);
glVertex3f(-1,-1,-1);
glVertex3f(1,-1,-1);
glVertex3f(1,-1,1);
glVertex3f(-1,-1,1);
/*Back*/
glColor3f(1.0,0.2,0.2);
glVertex3f(-1,-1,-1);
glVertex3f(1,-1,-1);
glVertex3f(1,1,-1);
glVertex3f(-1,1,-1);
/*right*/
glColor3f(0.3,0.1,0.5);
glVertex3f(1,1,1);
glVertex3f(1,-1,1);
glVertex3f(1,-1,-1);
glVertex3f(1,1,-1);
/*left*/
glColor3f(0.3,0.1,0.5);
glVertex3f(-1,1,1);
glVertex3f(-1,-1,1);
glVertex3f(-1,-1,-1);
glVertex3f(-1,1,-1);
glEnd();

glPopMatrix();

}
void Display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear the color buffer
	glMatrixMode(GL_MODELVIEW); // to operate on model view matrx
	glLoadIdentity();
	glTranslated(0,0,-2.8);
	drawWalls();

for(int k=0;k<8;k++)
t[k].ballch();
gluLookAt(  p.x, 0.0f, p.z,
            p.x+p.lx, 0.0f,  p.z+p.lz,
            0.0f, 1.0f,  0.0f);

for(int i=0;i<n;i++){
b[i].ballmaker();}
gluLookAt(  p.x, 0.0f, p.z,
            p.x+p.lx, 0.0f,  p.z+p.lz,
            0.0f, 1.0f,  0.0f);

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
p.collision(&b[i],&b[j]);
for(int d=0;d<8;d++)
p.terr(&b[i],&t[d]);
}
glutSwapBuffers();
}

void mthreads(){





}
// }
// int i=0;
// Ball currentball(b[0]);


// float ori=currentball.xspeed;
// float re = currentball.yspeed;

void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            p.angle -= 0.01f;
            p.lx = sin(p.angle);
            p.lz = -cos(p.angle);
            for(int i=0;i<n;i++)
            {b[i].pangle -= 0.01f;
            b[i].plx = sin(b[i].pangle);
            b[i].plz = -cos(b[i].pangle);
            }
            // for(int i=0;i<n;i++)
            // {t[i].tangle -= 0.01f;
            // t[i].tlx = sin(t[i].tangle);
            // t[i].tlz = -cos(t[i].tangle);
            // }
            break;
        case GLUT_KEY_RIGHT :
            p.angle += 0.01f;
            p.lx = sin(p.angle);
            p.lz = -cos(p.angle);
            for(int i=0;i<n;i++)
            {b[i].pangle += 0.01f;
            b[i].plx = sin(b[i].pangle);
            b[i].plz = -cos(b[i].pangle);
            }
            // for(int i=0;i<n;i++)
            // {t[i].tangle += 0.01f;
            // t[i].tlx = sin(t[i].tangle);
            // t[i].tlz = -cos(t[i].tangle);
            // }
            break;
        case GLUT_KEY_UP :
            p.x += p.lx * fraction;
            p.z += p.lz * fraction;
            for(int i=0;i<n;i++)
            {b[i].px += b[i].plx * fraction;
            b[i].pz += b[i].plz * fraction;}
            // for(int i=0;i<n;i++)
            // {t[i].tx += t[i].tlx * fraction;
            // t[i].tz += t[i].tlz * fraction;}
            break;
        case GLUT_KEY_DOWN :
            p.x -= p.lx * fraction;
            p.z -= p.lz * fraction;
            for(int i=0;i<n;i++)
            {b[i].px -= b[i].plx * fraction;
            b[i].pz -= b[i].plz * fraction;}
            // for(int i=0;i<n;i++)
            // {t[i].tx += t[i].tlx * fraction;
            // t[i].tz += t[i].tlz * fraction;}
            // break;
    }
}

Vector v[1000];
float arr[8];

int count=0;
static bool paused = false;
void handleKeypress(unsigned char key,int d,int a) {    //The current mouse coordinates                                                                                  
        switch (key) {

                case 27: //Escape key                                                                                                                                       
                  exit(0); //Exit the program                                                                                                                               
         
                // case 'p':
                //  paused = true;
                 
             
                //   break;     
                case 'w':
                for(int i=0;i<n;i++){
                b[i].xspeed= b[i].xspeed+0.05;
                b[i].yspeed= b[i].yspeed+0.05;
                b[i].zspeed=b[i].zspeed+0.05;
                }


                    break;

                case 's':
                for(int i=0;i<n;i++){
                b[i].xspeed= b[i].xspeed/1.2;
                b[i].yspeed= b[i].yspeed/ 1.2;
                b[i].zspeed = b[i].zspeed/1.2;
                    }
                    break;

                case 'p':
                {int j=0;
                   // int count=0;
                if(count==0){    
                while(j<n){
                    v[j].x= b[j].xspeed;
                    v[j].y=b[j].yspeed;
                    v[j].z=b[j].zspeed;
                    j++;
                    count =1;

                }
                for(int i=0;i<n;i++){
                        b[i].xspeed=b[i].yspeed=b[i].zspeed=0;
                }
                for(int l=0;l<8;l++)
                 {
                    arr[l]=t[l].xSpeed;
                    t[l].xSpeed=0.0;
                 }   
                }
                else if(count ==1){
                    for(int i=0 ;i<n; i++){
                    b[i].xspeed=v[i].x;
                    b[i].yspeed=v[i].y;
                    b[i].zspeed=v[i].z;
                    count =0;
                }
                for(int l=0;l<8;l++)
                 {
                    t[l].xSpeed=arr[l];
                }   
                }
                 break;
                }
                }}
//              case 'r' :
//              for(int i=0 ;i<x; i++){
//                  b[i].xspeed=v[i].x;
//                  b[i].yspeed=v[i].y;
//              }
//              break;
                
//              // case 'c':
//              // currentball = b[i+1];
//              // break;
//           }



// }s


void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(refresh,Timer,0);


}
struct AudioData
{
    Uint8* pos;
    Uint32 length;
};

void MyAudioCallback(void* userdata, Uint8* stream, int streamLength)
{
    AudioData* audio = (AudioData*)userdata;

    if(audio->length == 0)
    {
        return;
    }

    Uint32 length = (Uint32)streamLength;
    length = (length > audio->length ? audio->length : length);

    SDL_memcpy(stream, audio->pos, length);

    audio->pos += length;
    audio->length -= length;
}



int main(int argc, char** argv)
{std::cout<<"Enter the number of balls you want!";  
 std::cin>>n;
 std::cout<<"Get into the world of Balls";
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WindowWidth,WindowHeight);
	glutInitWindowPosition(WindowPosx,WindowPosy);
	glutCreateWindow("ball");
	glutKeyboardFunc(handleKeypress);
	  glutSpecialFunc(processSpecialKeys);
    // if(paused=true)
      //    {
    glutDisplayFunc(Display);       //drawScene draws everything does the real work
          // glutTimerFunc(10,Timer, 0); //Add a timer                                                                                                                     
          
//	glutDisplayFunc(Display);
	 glutReshapeFunc(reshape);
//glutReshapeFunc(reshape);
	glutTimerFunc(0,Timer,0);
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec;
    Uint8* wavStart;
    Uint32 wavLength;

    if(SDL_LoadWAV(FILE_PATH, &wavSpec, &wavStart, &wavLength) == NULL)
    {
        // TODO: Proper error handling
        std::cerr << "Error: " << FILE_PATH 
            << " could not be loaded as an audio file" << std::endl;
        return 1;
    }

    AudioData audio;
    audio.pos = wavStart;
    audio.length = wavLength;

    wavSpec.callback = MyAudioCallback;
    wavSpec.userdata = &audio;

    SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL,
            SDL_AUDIO_ALLOW_ANY_CHANGE);
    if(device == 0)
    {
        // TODO: Proper error handling
        std::cerr << "Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_PauseAudioDevice(device, 0);

    while(audio.length > 0)
    {
        SDL_Delay(100);
    }

    SDL_CloseAudioDevice(device);
    SDL_FreeWAV(wavStart);
SDL_Quit();
	initGL();
	glutMainLoop();
	return 0;
}


