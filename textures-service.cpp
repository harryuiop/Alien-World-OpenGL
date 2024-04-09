#include <GL/freeglut.h>
#include "loadTGA.h"
#include "loadBMP.h"
#include "textures-service.h"

// Function to load textures
void loadTexture(GLuint* txId)
{

    // string root = chdir();
    // Generate texture ids
    glGenTextures(4, txId);

    // Bind texture and load TGA file
    glBindTexture(GL_TEXTURE_2D, txId[0]);
    loadTGA("../skybox-photos/TCom_Sand_Muddy2_2x2_1K_albedo.tga");
    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_WRAP_R);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_EDGE);

    // Bind texture and load TGA file
    glBindTexture(GL_TEXTURE_2D, txId[1]);
    loadTGA("../skybox-photos/Front.tga");
    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_WRAP_R);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_EDGE);

     // Bind texture and load TGA file
    glBindTexture(GL_TEXTURE_2D, txId[2]);
    loadTGA("../skybox-photos/TCom_Gore_1K_normal.tga");
    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_TEXTURE_WRAP_R);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP_TO_EDGE);

    // Bind texture and load TGA file
    glBindTexture(GL_TEXTURE_2D, txId[3]);  //Use this texture name for the following OpenGL texture
	loadBMP("../skybox-photos/Earth.bmp");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
}

