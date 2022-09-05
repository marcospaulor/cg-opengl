#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.1415

#define WIDTH_GL 640
#define HEIGHT_GL 480

#define WIDTH_PC glutGet(GLUT_SCREEN_WIDTH)
#define HEIGHT_PC glutGet(GLUT_SCREEN_HEIGHT)


GLfloat obs[3] = {0.0,7.0,0.0};
GLfloat olho[3] = {0.0,3.0,0.0};

GLfloat tetaxz = 0.0;
GLfloat raioxz = 6.0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Chão
    // glBegin(GL_QUADS);
    //     glColor3f(0.8f,0.0f,0.0f);
    //     glVertex3f(0.03f,-0.13f,0.0f);
    //     glVertex3f(0.03f,0.1f,-1.0f);
    //     glVertex3f(0.17f,0.1f,-1.0f);
    //     glVertex3f(0.17f,-0.13f,0.0f);
    // glEnd();

    glNormal3f(0,1,0);
    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f,0.0f);
        glVertex3f(-10,0,10);
        glVertex3f(10,0,10);
        glVertex3f(10,0,-10);
        glVertex3f(-10,0,-10);
    glEnd();

    glutSwapBuffers();
}

void initGL(void){
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(WIDTH_GL, HEIGHT_GL);
    glutInitWindowPosition((WIDTH_PC - WIDTH_GL) / 2, (HEIGHT_PC - HEIGHT_GL) / 2);
    glutCreateWindow("Sala");

    glutDisplayFunc(display);
    initGL();

    //init();
    
    /*glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutReshapeFunc(reshape);*/

    glutMainLoop();

    return 0;
}
