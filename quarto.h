#include "textura.h"

void chao() {
    // Chão
    glColor3f(0.25f,0.25f,0.25f);
    glBegin(GL_QUADS);
        glVertex3f(-5.0f,0.0f,5.0f);
        glVertex3f(5.0f,0.0f,5.0f);
        glVertex3f(5.0f,0.0f,-5.0f);
        glVertex3f(-5.0f,0.0f,-5.0f);
    glEnd();
}

void paredes() {
    // Face Esquerda
    glColor3f(0.25f,0.25f,0.25f);

    loadTexture("Wall_Texture.bmp");
    glBegin(GL_QUADS);
        glTexCoord2f( 5,0); glVertex3f( 5,0,5);
        glTexCoord2f(-5,0); glVertex3f(-5,0,5);
        glTexCoord2f(-5,5); glVertex3f(-5,5,5);
        glTexCoord2f( 5,5); glVertex3f( 5,5,5);
    glEnd();

    // Face Traseira
    glBegin(GL_QUADS);
        glVertex3f(-5,0,5);
        glVertex3f(-5,0,-5);
        glVertex3f(-5,5,-5);
        glVertex3f(-5,5,5);
    glEnd();

    // Face Direita com Buraco
    glBegin(GL_QUADS);
        glVertex3f(-5,0,-5);
        glVertex3f(-2,0,-5);
        glVertex3f(-2,5,-5);
        glVertex3f(-5,5,-5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(5,0,-5);
        glVertex3f(2,0,-5);
        glVertex3f(2,5,-5);
        glVertex3f(5,5,-5);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-2,4,-5);
        glVertex3f(2,4,-5);
        glVertex3f(2,5,-5);
        glVertex3f(-2,5,-5);
    glEnd();

    // Face Dianteira
    glBegin(GL_QUADS);
        glVertex3f(5,0,5);
        glVertex3f(5,0,-5);
        glVertex3f(5,5,-5);
        glVertex3f(5,5,5);
    glEnd();
}

void teto() {
    // Teto
    glBegin(GL_QUADS);
        glColor3f(0.25f,0.25f,0.25f);
        glVertex3f(-5,5,5);
        glVertex3f(5,5,5);
        glVertex3f(5,5,-5);
        glVertex3f(-5,5,-5);
    glEnd();
}

void som() {
    // Caixa de Som Esquerda
    glColor3f(0.63f, 0.32f, 0.18f);
    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,2.1);
        glVertex3f(-4,0.0,2.1);
        glVertex3f(-4,2.0,2.1);
        glVertex3f(-5,2.0,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,1.1);
        glVertex3f(-4,0.0,1.1);
        glVertex3f(-4,2.0,1.1);
        glVertex3f(-5,2.0,1.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4,0.0,2.1);
        glVertex3f(-4,0.0,1.1);
        glVertex3f(-4,2.0,1.1);
        glVertex3f(-4,2.0,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,2.0,2.1);
        glVertex3f(-5,2.0,1.1);
        glVertex3f(-4,2.0,1.1);
        glVertex3f(-4,2.0,2.1);
    glEnd();

    // Caixa de Som Direita
    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,-2.1);
        glVertex3f(-4,0.0,-2.1);
        glVertex3f(-4,2.0,-2.1);
        glVertex3f(-5,2.0,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,-1.1);
        glVertex3f(-4,0.0,-1.1);
        glVertex3f(-4,2.0,-1.1);
        glVertex3f(-5,2.0,-1.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4,0.0,-2.1);
        glVertex3f(-4,0.0,-1.1);
        glVertex3f(-4,2.0,-1.1);
        glVertex3f(-4,2.0,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,2.0,-2.1);
        glVertex3f(-5,2.0,-1.1);
        glVertex3f(-4,2.0,-1.1);
        glVertex3f(-4,2.0,-2.1);
    glEnd();

    // Caixa Central
    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,1.0);
        glVertex3f(-4,0.0,1.0);
        glVertex3f(-4,1.0,1.0);
        glVertex3f(-5,1.0,1.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,0.0,-1.0);
        glVertex3f(-4,0.0,-1.0);
        glVertex3f(-4,1.0,-1.0);
        glVertex3f(-5,1.0,-1.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4,0.0,1.0);
        glVertex3f(-4,0.0,-1.0);
        glVertex3f(-4,1.0,-1.0);
        glVertex3f(-4,1.0,1.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5,1.0,1.0);
        glVertex3f(-5,1.0,-1.0);
        glVertex3f(-4,1.0,-1.0);
        glVertex3f(-4,1.0,1.0);
    glEnd();
}

void tv() {
    // Televisão
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-5.0,3.0,-2.1);
        glVertex3f(-5.0,4.5,-2.1);
        glVertex3f(-4.9,4.5,-2.1);
        glVertex3f(-4.9,3.0,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,3.0,2.1);
        glVertex3f(-5.0,4.5,2.1);
        glVertex3f(-4.9,4.5,2.1);
        glVertex3f(-4.9,3.0,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,3.0,-2.1);
        glVertex3f(-5.0,3.0,2.1);
        glVertex3f(-4.9,3.0,2.1);
        glVertex3f(-4.9,3.0,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-5.0,4.5,-2.1);
        glVertex3f(-5.0,4.5,2.1);
        glVertex3f(-4.9,4.5,2.1);
        glVertex3f(-4.9,4.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,3.0,-2.1);
        glVertex3f(-4.9,3.0,-2.0);
        glVertex3f(-4.9,4.5,-2.0);
        glVertex3f(-4.9,4.5,-2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,3.0,2.1);
        glVertex3f(-4.9,3.0,2.0);
        glVertex3f(-4.9,4.5,2.0);
        glVertex3f(-4.9,4.5,2.1);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,3.0,-2.0);
        glVertex3f(-4.9,3.0,2.0);
        glVertex3f(-4.9,3.1,2.0);
        glVertex3f(-4.9,3.1,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.9,4.5,-2.0);
        glVertex3f(-4.9,4.5,2.0);
        glVertex3f(-4.9,4.4,2.0);
        glVertex3f(-4.9,4.4,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,3.1,-2.0);
        glVertex3f(-4.90,3.1,-2.0);
        glVertex3f(-4.90,3.1,2.0);
        glVertex3f(-4.965,3.1,2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,4.4,-2.0);
        glVertex3f(-4.90,4.4,-2.0);
        glVertex3f(-4.90,4.4,2.0);
        glVertex3f(-4.965,4.4,2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,3.1,-2.0);
        glVertex3f(-4.90,3.1,-2.0);
        glVertex3f(-4.90,4.4,-2.0);
        glVertex3f(-4.965,4.4,-2.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-4.965,3.1,2.0);
        glVertex3f(-4.90,3.1,2.0);
        glVertex3f(-4.90,4.4,2.0);
        glVertex3f(-4.965,4.4,2.0);
    glEnd();

    // Tela
    glColor3f(1.0,0.25,0.25);
    glBegin(GL_QUADS);
        glVertex3f(-4.965,3.1,2.0);
        glVertex3f(-4.965,3.1,-2.0);
        glVertex3f(-4.965,4.4,-2.0);
        glVertex3f(-4.965,4.4,2.0);
    glEnd();
}
