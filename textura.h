#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <cstdio>

GLuint idTextura;
AUX_RGBImageRec *imagemTextura;

AUX_RGBImageRec *LoadBMP(const char *filename){
    FILE *file = NULL;

    if (!filename) {
        return NULL;         
    }

    file=fopen(filename,"r");	
    if (file) {
        fclose(file);			    

        return auxDIBImageLoad(filename);
    }

    return NULL;			
}

void loadTexture(const char *filename) {
    imagemTextura = LoadBMP(filename);

    if (!imagemTextura) {
        printf("Erro ao carregar imagem %s");
    }

    glGenTextures(1, &idTextura);
    glBindTexture(GL_TEXTURE_2D, idTextura);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura->sizeX, 
			imagemTextura->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
			imagemTextura->data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}