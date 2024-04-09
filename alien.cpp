#include "alien.h"

float light[4] = {0, 20, 0, 1};
float shadowMat[16] = {light[1], 0, 0, 0, -light[0], 0, -light[2],-1,
							0, 0, light[1], 0, 0, 0, 0, light[1]};

void drawAlien(int* angle, float* radAngle, GLuint* txId) 
{
    float newRadAngle = *radAngle;

    // glBindTexture(GL_TEXTURE_2D, txId[7]);
    glColor3f(0.2, 1, 0.2);
    glPushMatrix();
        glTranslatef(0, 0, -27); // -15 to get it around the ship;
        glRotatef(newRadAngle, 0, 1, 0);
        glTranslatef(0, 0, 27);
        glRotatef(70, 0, 1, 0);

        // Neck
        glPushMatrix();
            glTranslatef(0, 4.5, 0);
            glScalef(0.7, 1.7, 0.7);
            glRotatef(90, 1, 0, 0);
            gluCylinder(gluNewQuadric(), 0.25, 0.25, 0.7, 20, 20);
        glPopMatrix();

        glDisable(GL_LIGHTING);
        glPushMatrix();
            glMultMatrixf(shadowMat);
            glTranslatef(0, 4, 0);
            glScalef(0.7, 1.7, 0.7);
            glRotatef(90, 1, 0, 0);
            glColor4f(0.2, 0.2, 0.2, 1.0);
            gluCylinder(gluNewQuadric(), 0.25, 0.25, 0.7, 20, 20);
            glColor3f(0.2, 1, 0.2);
        glPopMatrix();
        glEnable(GL_LIGHTING);

        // Right Arm
        glPushMatrix();
            glTranslatef(-1, 2.3, 0);

            glTranslatef(0 , 2, 0);
            glRotatef(*angle, 1, 0, 0);
            glTranslatef(0 , -2, 0);

            glRotatef(-20, 0, 0, 1);
            glScalef(0.2, 0.55, 0.2);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
        glPopMatrix();

        glDisable(GL_LIGHTING);
        glPushMatrix();
            glMultMatrixf(shadowMat);
            glTranslatef(-1, 2.1, 0);

            glTranslatef(0 , 2, 0);
            glRotatef(*angle, 1, 0, 0);
            glTranslatef(0 , -2, 0);

            glRotatef(-20, 0, 0, 1);
            glScalef(0.2, 0.55, 0.2);
            glColor4f(0.2, 0.2, 0.2, 1.0);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
            glColor3f(0.2, 1, 0.2);
        glPopMatrix();
        glEnable(GL_LIGHTING);

        // Left Arm
        glPushMatrix();
            glTranslatef(1, 2.4, 0);

            glTranslatef(0 , 2, 0);
            glRotatef(-*angle, 1, 0, 0);
            glTranslatef(0 , -2, 0);

            glRotatef(20, 0, 0, 1);
            glScalef(0.2, 0.55, 0.2);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
        glPopMatrix();

        glDisable(GL_LIGHTING);
        glPushMatrix();
            glMultMatrixf(shadowMat);
            glTranslatef(1, 2.1, 0);

            glTranslatef(0 , 2, 0);
            glRotatef(-*angle, 1, 0, 0);
            glTranslatef(0 , -2, 0);

            glRotatef(20, 0, 0, 1);
            glScalef(0.2, 0.55, 0.2);
            glColor4f(0.2, 0.2, 0.2, 1.0);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
            glColor3f(0.2, 1, 0.2);
        glPopMatrix();
        glEnable(GL_LIGHTING);

        // Left Leg
        glPushMatrix();
            glTranslatef(0.4, 0.8, 0);
    
            glTranslatef(0, 2, 0);
            glRotatef(*angle, 1, 0, 0);
            glTranslatef(0, -2, 0);

            glScalef(0.2, 0.55, 0.2);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
        glPopMatrix();

        glDisable(GL_LIGHTING);
        glPushMatrix();
            glMultMatrixf(shadowMat);
            glTranslatef(0.4, 0.5, 0);
    
            glTranslatef(0, 2, 0);
            glRotatef(*angle, 1, 0, 0);
            glTranslatef(0, -2, 0);

            glScalef(0.2, 0.55, 0.2);
            glColor4f(0.2, 0.2, 0.2, 1.0);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
            glColor3f(0.2, 1, 0.2);
        glPopMatrix();
        glEnable(GL_LIGHTING);

        // Right Leg
        glPushMatrix();
            glTranslatef(-0.4, 0.8, 0);

            glTranslatef(0, 2, 0);
            glRotatef(-*angle, 1, 0, 0);
            glTranslatef(0, -2, 0);

            glScalef(0.2, 0.55, 0.2);
            gluSphere(gluNewQuadric(), 1.7, 10, 10);
        glPopMatrix();

            glDisable(GL_LIGHTING);
            glPushMatrix();
                glMultMatrixf(shadowMat);
                glTranslatef(-0.4, 0.5, 0);

                glTranslatef(0, 2, 0);
                glRotatef(-*angle, 1, 0, 0);
                glTranslatef(0, -2, 0);

                glScalef(0.2, 0.55, 0.2);
                glColor4f(0.2, 0.2, 0.2, 1.0);
                gluSphere(gluNewQuadric(), 1.7, 10, 10);
                glColor3f(0.2, 1, 0.2);
            glPopMatrix();
            glEnable(GL_LIGHTING);

        // Head
        glPushMatrix();
            GLUquadric* quadric = gluNewQuadric();
            glTranslatef(0, 5.3, 0);
            glScalef(0.3, 0.3, 0.3);
            gluQuadricTexture(quadric, GL_TRUE);
            gluSphere(quadric, 3, 10, 10);
            gluDeleteQuadric(quadric);
        glPopMatrix();

        glDisable(GL_LIGHTING);
            glPushMatrix();
                glMultMatrixf(shadowMat);
                glTranslatef(0, 5, 0);
                glScalef(0.3, 0.3, 0.3);
                glColor4f(0.2, 0.2, 0.2, 1.0);
                gluSphere(gluNewQuadric(), 3, 10, 10);
                glColor3f(0.2, 1, 0.2);
            glPopMatrix();
        glEnable(GL_LIGHTING);

        // Body
        glColor3f(0.2, 0.5, 0.6);
        glPushMatrix();
            glColor3f(1, 1, 1);
            glTranslatef(0, 2.5, 0);
            glScalef(0.3, 0.5, 0.3);
            gluSphere(gluNewQuadric(), 3, 10, 10);
        glPopMatrix();

        glDisable(GL_LIGHTING);
        glPushMatrix();
            glMultMatrixf(shadowMat);
            glTranslatef(0, 2.5, 0);
            glScalef(0.3, 0.5, 0.3);
            glColor4f(0.2, 0.2, 0.2, 1.0);
            gluSphere(gluNewQuadric(), 3, 10, 10);
            glColor3f(0.2, 1, 0.2);
        glPopMatrix();
        glEnable(GL_LIGHTING);
        

        // Eye 1
        glColor3f(0, 0, 0);
        glPushMatrix();
            glTranslatef(-0.3, 5.5, 0.85);
            glScalef(0.05, 0.085, 0.05);
            gluSphere(gluNewQuadric(), 3, 10, 10);
        glPopMatrix();

        // Eye 2
            glColor3f(0, 0, 0);
        glPushMatrix();
            glTranslatef(0.3, 5.5, 0.9);
            glScalef(0.05, 0.085, 0.05);
            gluSphere(gluNewQuadric(), 3, 10, 10);
        glPopMatrix();
    
    glPopMatrix();
}   