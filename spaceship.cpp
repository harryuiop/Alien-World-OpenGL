#include "spaceship.h"

float light_posi[4] = {-6, 20, 0, 1};     //above origin
float shadowMats[16] = {light_posi[1], 0, 0, 0, -light_posi[0], 0, -light_posi[2],-1,
                        0, 0, light_posi[1], 0, 0, 0, 0, light_posi[1]};


void drawSpaceship(float* radAngle, float* shipHeight, GLuint* txId)
{
    glColor3f(0.5, 0.5, 0.9);
    
    glPushMatrix();
        glTranslatef(0, *shipHeight, -40);
        glRotatef(*radAngle, 0, 1, 0);

        // Balls
        // glBindTexture(GL_TEXTURE_2D, txId[3]);
        glPushMatrix();
            glTranslatef(-3, 13, -8);
            glRotatef(*radAngle * 8, 0, 1, 0);
            glTranslatef(2, 0, 0);
            gluSphere(gluNewQuadric(), 0.4, 20, 20);
        glPopMatrix();
        // glBindTexture(GL_TEXTURE_2D, 0); 
        

        // Top Half
        glPushMatrix();
            glTranslatef(0, 13, -15);
            glRotatef(90, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 3.0, 10.0, 3.0, 20, 20);
        glPopMatrix();

        if (*shipHeight < 1) {
        glDisable(GL_LIGHTING);
        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
            glMultMatrixf(shadowMats);
            glTranslatef(0, 13, -15);
            glRotatef(90, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 3.0, 10.0, 3.0, 20, 20);
        glPopMatrix();
        glEnable(GL_LIGHTING);
        glColor3f(0.4, 0.4, 0.9);
        }

        // Middle Section
        glPushMatrix();
            glTranslatef(0, 10, -15);
            glRotatef(90, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 10.0, 10.0, 0.5, 20, 20);
        glPopMatrix();

        if (*shipHeight < 1) {
        glDisable(GL_LIGHTING);
        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
            glMultMatrixf(shadowMats);
            glTranslatef(0, 10 - *shipHeight, -15);
            glRotatef(90, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 10.0, 10.0, 0.5, 20, 20);
        glPopMatrix();
        glEnable(GL_LIGHTING);
        glColor3f(0.4, 0.4, 0.9);
        }

        // Bottom Half    
        glPushMatrix();
            glTranslatef(0, 7, -15);
            glRotatef(270, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 3.0, 10.0, 3.0, 20, 20);
        glPopMatrix();
         
        if (*shipHeight < 1) {
        glDisable(GL_LIGHTING);
        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
            glMultMatrixf(shadowMats);
            glTranslatef(0, 7, -15);
            glRotatef(270, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 3.0, 10.0, 3.0, 20, 20);
        glPopMatrix();
        glEnable(GL_LIGHTING);
        glColor3f(0.4, 0.4, 0.9);
        }

        // Antenna
        glPushMatrix();
            glTranslatef(-3, 10, -8);
            glRotatef(270, 1, 0, 0); //270
            gluCylinder(gluNewQuadric(), 0.2, 0.2, 3.0, 20, 20);
        glPopMatrix();

        if (*shipHeight < 1) {
        glDisable(GL_LIGHTING);
        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
            glMultMatrixf(shadowMats);
            glTranslatef(-3, 10, -8);
            glRotatef(270, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 0.2, 0.2, 3.0, 20, 20);
        glPopMatrix();
        glEnable(GL_LIGHTING);
        glColor3f(0.4, 0.4, 0.9);
        }

        // Antenna Top
        glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(-3, 13, -8);
            glRotatef(270, 0, 1, 0);
            gluSphere(gluNewQuadric(), 0.4, 20, 20);
        glPopMatrix();

    glPopMatrix();
}