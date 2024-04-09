//  ========================================================================
//  COSC363: Assignment 1
//	By Harry Ellis (hel46)
//  ========================================================================
 
#include <iostream>
#include <cmath> 
#include <GL/freeglut.h>
#include "textures-service.h" 
#include "spaceship.h"
#include "alien.h"
using namespace std;

//---- Globals ----
GLuint txId[4];   //Texture ids
float angle=0, look_x=0, look_z=0., eye_x=0, eye_z=10;  //View parameters
int alienBodyPartAngle = 20;
float alienWalkAngle = 0;
bool takeoffActive = false;
float shipHeight = 0;

#define GRAVITY 50.8  
#define TERMINAL_VELOCITY 50.0 

//---- Special function callback -----
void special(int key, int x, int y)
{
    // Handle special key presses (arrow keys)
	if(key == GLUT_KEY_LEFT) angle -= 0.1;  //Change direction
	else if(key == GLUT_KEY_RIGHT) angle += 0.1;
	
	else if(key == GLUT_KEY_DOWN)
	{  //Move backward
		eye_x -= 0.1*sin(angle);
		eye_z += 0.1*cos(angle);
	}
	else if(key == GLUT_KEY_UP)
	{ //Move forward
		eye_x += 0.1*sin(angle);
		eye_z -= 0.1*cos(angle);
	}
    // Calculate new look at coordinates
	look_x = eye_x + 10*sin(angle);
	look_z = eye_z - 10*cos(angle);
    // Request redisplay
	glutPostRedisplay();
}


void drawSkydome()
{
	float radius = 100;
	int slices = 40;
	int stacks = 40;
    glPushMatrix();
		glColor3f(0.5f, 0.5f, 0.5f); 
		glBindTexture(GL_TEXTURE_2D, txId[1]);

		for (int j = 0; j < stacks; ++j) {
			glBegin(GL_QUAD_STRIP);

			for (int i = 0; i <= slices; ++i) {
				
				float angle_around_x = 2.0f * M_PI * ((float)i / slices); // Angle around the X-axis
				float angle_around_y = M_PI * ((float)j / stacks); // Angle along the Y-axis

				// x, y and z are 
				float x = radius * cosf(angle_around_x) * sinf(angle_around_y); // Calculate the vertex position
				float y = radius * cosf(angle_around_y);
				float z = radius * sinf(angle_around_x) * sinf(angle_around_y);

				glNormal3f(x, y, z); 
				glTexCoord2f((float)i / slices, (float)j / stacks); 
				glVertex3f(x, y, z);

				angle_around_y = M_PI * ((float)(j + 1) / stacks);
				x = radius * cosf(angle_around_x) * sinf(angle_around_y);
				y = radius * cosf(angle_around_y);
				z = radius * sinf(angle_around_x) * sinf(angle_around_y);

				glNormal3f(x, y, z); 
				glTexCoord2f((float)i / slices, (float)(j + 1) / stacks); 
				glVertex3f(x, y, z); 
			}
			glEnd();
		}
    glPopMatrix();
}

void drawFloor()
{
	glColor3f(0.5, 0.5, 0.5);   //replace with a texture

	for (int j = -600; j <= 600; j += 10) 
	{
		for(int i = -600; i <= 600; i +=10)
		{	
			glBindTexture(GL_TEXTURE_2D, txId[0]);

			glBegin(GL_QUADS);			
				float height = sin(i)*sin(j) -2;
				glTexCoord2f(((float)(i+600) / 1200), ((float)(j+600) / 1200));
				glVertex3f(i, height, j);

				height = sin(i+10)*sin(j)-2;
				glTexCoord2f(((float)(i+10+600) / 1200), ((float)(j+600) / 1200));
				glVertex3f(i+10, height, j);

				height = sin(i+10)*sin(j+10)-2;
				glTexCoord2f(((float)(i+10+600) / 1200), ((float)(j+10+600) / 1200));
				glVertex3f(i+10, height, j+10);

				height = sin(i)*sin(j+10)-2;
				glTexCoord2f(((float)(i+600) / 1200), ((float)(j+10+600) / 1200));
				glVertex3f(i, height, j+10);
			glEnd();
		}
	}
}

void initialise()
{ 
	float white[4]  = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0}; // Ambient light intensity (RGBA)

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	loadTexture(txId);  // Load textures
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glClearColor(0., 0., 0., 1.);  //Background colour

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);    //Default, only for LIGHT0
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);   //Default, only for LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, white);

    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);

    // Set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, 1.0, 1.5, 3000.0);   //Perspective projection with wider FOV
}

//---- The display function -----
void display()
{
	float light[] = {0.0f, 0.0f, 0.0f, 1.0f}; 
	GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
   	float spotPosn[] = {-10.0f, 14.0f, 0.0f, 1.0f}; // Spot position
	GLfloat lightPos0[] = {0.0f, 3.0f, 0.8f, 1.0f};
	GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f,0.0f};
	float shadowMat[16] = {light[1], 0, 0, 0, -light[0], 0, -light[2],-1,
						   0, 0, light[1], 0, 0, 0, 0, light[1]};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	glMatrixMode(GL_MODELVIEW);								
	glLoadIdentity();
	gluLookAt(eye_x, 5, eye_z, look_x, 3, look_z, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, light);
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor0);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos0);

    drawSkydome();
	drawSpaceship(&alienWalkAngle, &shipHeight, txId);
	drawAlien(&alienBodyPartAngle, &alienWalkAngle, txId);
	glPushMatrix();
		glTranslatef(10, 0 ,0);
		drawAlien(&alienBodyPartAngle, &alienWalkAngle, txId);
	glPopMatrix();
	drawFloor();

	glutSwapBuffers();       //Double buffered animation
}

// --- Timer Function -------------
void timer(int value) {
    static float angleStep = 1.0f; // Angle change per timer callback
    static bool increasing = true; // Flag to control direction of animation

    // Alien body part animation
    if (increasing) {
        alienBodyPartAngle += angleStep;
    } else {
        alienBodyPartAngle -= angleStep;
    }

    // Reverse direction when reaching the maximum or minimum angle
    if (alienBodyPartAngle >= 30 || alienBodyPartAngle <= -30) {
        increasing = !increasing;
    }

    alienWalkAngle += 0.2;

    static double shipVelocity = 0.0;

    if (takeoffActive) {
        if (shipHeight < 70) {
            shipHeight += 2;
            shipVelocity = 0.0; 
        } else {
            takeoffActive = false;
        }
    } else {
        double acceleration = (shipVelocity < TERMINAL_VELOCITY) ? GRAVITY : 0.0;
        shipVelocity += acceleration * (1.0 / 60.0);
		shipHeight -= shipVelocity * (1.0 / 60.0 * 2);

        if (shipHeight <= 0) {
            shipHeight = 0;
            shipVelocity = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0); 
}

void spacebar(unsigned char key, int x, int y)
{
	if (key == ' ') {
		takeoffActive = true;
	}
}

//---- Glut initialisation, registration of callbacks ----
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (10, 10);
   glutCreateWindow ("Alien World");
   glutTimerFunc(100, timer, 0);
   initialise();

   glutDisplayFunc(display); 
   glutSpecialFunc(special);
   glutKeyboardFunc(spacebar);
   glutMainLoop();
   return 0;
}