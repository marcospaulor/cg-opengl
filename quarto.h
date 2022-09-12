#include "textura.h"
#include <GL/glext.h>

void chao() {
    glColor3f(0.5, 0.5, 0.5);

    // Chão
    loadTexture("texturas/Floor_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f( 4,-4); glVertex3f(-5.0f,0.0f,5.0f);
        glTexCoord2f( 4, 4); glVertex3f(5.0f,0.0f,5.0f);
        glTexCoord2f(-4, 4); glVertex3f(5.0f,0.0f,-5.0f);
        glTexCoord2f(-4,-4); glVertex3f(-5.0f,0.0f,-5.0f);
    glEnd();
}

void paredes() {
    // Face Esquerda
    loadTexture("texturas/Wall_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f( 5,0); glVertex3f( 5,0,5);
        glTexCoord2f(-5,0); glVertex3f(-5,0,5);
        glTexCoord2f(-5,5); glVertex3f(-5,5,5);
        glTexCoord2f( 5,5); glVertex3f( 5,5,5);
    glEnd();

    // Face Traseira
    glBegin(GL_QUADS);
        glTexCoord2f( 5,0); glVertex3f(-5,0,5);
        glTexCoord2f(-5,0); glVertex3f(-5,0,-5);
        glTexCoord2f(-5,5); glVertex3f(-5,5,-5);
        glTexCoord2f( 5,5); glVertex3f(-5,5,5);
    glEnd();

    // Face Direita com Buraco
    glBegin(GL_QUADS);
        glTexCoord2f(-5,0); glVertex3f(-5,0,-5);
        glTexCoord2f(-2,0); glVertex3f(-2,0,-5);
        glTexCoord2f(-2,5); glVertex3f(-2,5,-5);
        glTexCoord2f(-5,5); glVertex3f(-5,5,-5);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(5,0); glVertex3f(5,0,-5);
        glTexCoord2f(2,0); glVertex3f(2,0,-5);
        glTexCoord2f(2,5); glVertex3f(2,5,-5);
        glTexCoord2f(5,5); glVertex3f(5,5,-5);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(-2,4); glVertex3f(-2,4,-5);
        glTexCoord2f( 2,4); glVertex3f(2,4,-5);
        glTexCoord2f( 2,5); glVertex3f(2,5,-5);
        glTexCoord2f(-2,5); glVertex3f(-2,5,-5);
    glEnd();

    // Face Dianteira
    glBegin(GL_QUADS);
        glTexCoord2f( 5,0); glVertex3f(5,0,5);
        glTexCoord2f(-5,0); glVertex3f(5,0,-5);
        glTexCoord2f(-5,5); glVertex3f(5,5,-5);
        glTexCoord2f( 5,5); glVertex3f(5,5,5);
    glEnd();
}

void teto() {
    // Teto
    glBegin(GL_QUADS);
        glTexCoord2f( 5,-5); glVertex3f(-5,5,5);
        glTexCoord2f( 5, 5); glVertex3f(5,5,5);
        glTexCoord2f(-5, 5); glVertex3f(5,5,-5);
        glTexCoord2f(-5,-5); glVertex3f(-5,5,-5);
    glEnd();
}

void vao() {
    // Vão
    loadTexture("texturas/Paisagem_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-3.5,0,-5);
        glTexCoord2f(1,0); glVertex3f(3.5,0,-5);
        glTexCoord2f(1,1); glVertex3f(3.5,5,-6);
        glTexCoord2f(0,1); glVertex3f(-3.5,5,-6);
    glEnd();
}

void som() {
    // Frente Som Esquerdo
    loadTexture("texturas/Speaker_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-4,0.0,2.1);
        glTexCoord2f(1, 0); glVertex3f(-4,0.0,1.1);
        glTexCoord2f(1, 1); glVertex3f(-4,2.0,1.1);
        glTexCoord2f(0, 1); glVertex3f(-4,2.0,2.1);
    glEnd();

    // Frente Som Direito
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-4,0.0,-2.1);
        glTexCoord2f(1,0); glVertex3f(-4,0.0,-1.1);
        glTexCoord2f(1,1); glVertex3f(-4,2.0,-1.1);
        glTexCoord2f(0,1); glVertex3f(-4,2.0,-2.1);
    glEnd();

    // Frente Caixa Central
    loadTexture("texturas/Central_Speaker_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-4,0.0,1.0);
        glTexCoord2f(1,0); glVertex3f(-4,0.0,-1.0);
        glTexCoord2f(1,1); glVertex3f(-4,1.0,-1.0);
        glTexCoord2f(0,1); glVertex3f(-4,1.0,1.0);
    glEnd();

    // Caixa de Som Esquerda
    loadTexture((char *) "texturas/Wood_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,2.1);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,2.1);
        glTexCoord2f(2,-4); glVertex3f(-4,2.0,2.1);
        glTexCoord2f(2,-5); glVertex3f(-5,2.0,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,1.1);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,1.1);
        glTexCoord2f(2,-4); glVertex3f(-4,2.0,1.1);
        glTexCoord2f(2,-5); glVertex3f(-5,2.0,1.1);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(2.1,-5); glVertex3f(-5,2.0,2.1);
        glTexCoord2f(1.1,-5); glVertex3f(-5,2.0,1.1);
        glTexCoord2f(1.1,-4); glVertex3f(-4,2.0,1.1);
        glTexCoord2f(2.1,-4); glVertex3f(-4,2.0,2.1);
    glEnd();

    // Caixa de Som Direita
    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,-2.1);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,-2.1);
        glTexCoord2f(2,-4); glVertex3f(-4,2.0,-2.1);
        glTexCoord2f(2,-5); glVertex3f(-5,2.0,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,-1.1);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,-1.1);
        glTexCoord2f(2,-4); glVertex3f(-4,2.0,-1.1);
        glTexCoord2f(2,-5); glVertex3f(-5,2.0,-1.1);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(-2.1,-5); glVertex3f(-5,2.0,-2.1);
        glTexCoord2f(-1.1,-5); glVertex3f(-5,2.0,-1.1);
        glTexCoord2f(-1.1,-4); glVertex3f(-4,2.0,-1.1);
        glTexCoord2f(-2.1,-4); glVertex3f(-4,2.0,-2.1);
    glEnd();

    // Caixa Central
    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,1.0);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,1.0);
        glTexCoord2f(1,-4); glVertex3f(-4,1.0,1.0);
        glTexCoord2f(1,-5); glVertex3f(-5,1.0,1.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f(0,-5); glVertex3f(-5,0.0,-1.0);
        glTexCoord2f(0,-4); glVertex3f(-4,0.0,-1.0);
        glTexCoord2f(1,-4); glVertex3f(-4,1.0,-1.0);
        glTexCoord2f(1,-5); glVertex3f(-5,1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);
        glTexCoord2f( 1,-5); glVertex3f(-5,1.0,1.0);
        glTexCoord2f(-1,-5); glVertex3f(-5,1.0,-1.0);
        glTexCoord2f(-1,-4); glVertex3f(-4,1.0,-1.0);
        glTexCoord2f( 1,-4); glVertex3f(-4,1.0,1.0);
    glEnd();
}

void tv() {
    // Tela
    loadTexture((char *) "texturas/Shrek_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-4.965,2.6,2.0);
        glTexCoord2f(1,0); glVertex3f(-4.965,2.6,-2.0);
        glTexCoord2f(1,1); glVertex3f(-4.965,4.4,-2.0);
        glTexCoord2f(0,1); glVertex3f(-4.965,4.4,2.0);
    glEnd();

    // Televisão
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-5.0,2.5,-2.1);
        glVertex3f(-5.0,4.5,-2.1);
        glVertex3f(-4.9,4.5,-2.1);
        glVertex3f(-4.9,2.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,2.5,2.1);
        glVertex3f(-5.0,4.5,2.1);
        glVertex3f(-4.9,4.5,2.1);
        glVertex3f(-4.9,2.5,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,2.5,-2.1);
        glVertex3f(-5.0,2.5,2.1);
        glVertex3f(-4.9,2.5,2.1);
        glVertex3f(-4.9,2.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,4.5,-2.1);
        glVertex3f(-5.0,4.5,2.1);
        glVertex3f(-4.9,4.5,2.1);
        glVertex3f(-4.9,4.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,2.5,-2.1);
        glVertex3f(-4.9,2.5,-2.0);
        glVertex3f(-4.9,4.5,-2.0);
        glVertex3f(-4.9,4.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,2.5,2.1);
        glVertex3f(-4.9,2.5,2.0);
        glVertex3f(-4.9,4.5,2.0);
        glVertex3f(-4.9,4.5,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,2.5,-2.0);
        glVertex3f(-4.9,2.5,2.0);
        glVertex3f(-4.9,2.6,2.0);
        glVertex3f(-4.9,2.6,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,4.5,-2.0);
        glVertex3f(-4.9,4.5,2.0);
        glVertex3f(-4.9,4.4,2.0);
        glVertex3f(-4.9,4.4,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,2.6,-2.0);
        glVertex3f(-4.90,2.6,-2.0);
        glVertex3f(-4.90,2.6,2.0);
        glVertex3f(-4.965,2.6,2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,4.4,-2.0);
        glVertex3f(-4.90,4.4,-2.0);
        glVertex3f(-4.90,4.4,2.0);
        glVertex3f(-4.965,4.4,2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,2.6,-2.0);
        glVertex3f(-4.90,2.6,-2.0);
        glVertex3f(-4.90,4.4,-2.0);
        glVertex3f(-4.965,4.4,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,2.6,2.0);
        glVertex3f(-4.90,2.6,2.0);
        glVertex3f(-4.90,4.4,2.0);
        glVertex3f(-4.965,4.4,2.0);
    glEnd();
}
