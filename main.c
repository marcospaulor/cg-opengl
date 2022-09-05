#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define WIDTH_GL 640
#define HEIGHT_GL 480

#define WIDTH_PC glutGet(GLUT_SCREEN_WIDTH)
#define HEIGHT_PC glutGet(GLUT_SCREEN_HEIGHT)

void init(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glBegin(GL_QUADS);
    //     glColor3f(1.0, 0.0, 0.0);
    //     glVertex3f( 1.0f, 1.0f, -1.0f);
    //     glVertex3f(-1.0f, 1.0f, -1.0f);
    //     glVertex3f(-1.0f, 1.0f,  1.0f);
    //     glVertex3f( 1.0f, 1.0f,  1.0f);
    // glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, -10.0);
        glVertex3f(0.0, 1.0, 1);
        glVertex3f(1.0, 1.0, 1);
        glVertex3f(1.0, 0.0, 0.0);

        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.5, 0.0, 1);
        glVertex3f(-0.5, 1.0, 1);
        glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    glutInitWindowSize(WIDTH_GL, HEIGHT_GL);
    glutInitWindowPosition((WIDTH_PC - WIDTH_GL) / 2, (HEIGHT_PC - HEIGHT_GL) / 2);
    glutCreateWindow("Sala");

    glutDisplayFunc(display);

    init();
    
    /*glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutReshapeFunc(reshape);*/

    glutMainLoop();

    return 0;
}
