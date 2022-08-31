#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define WIDTH_GL 640
#define HEIGHT_GL 480

#define WIDTH_PC glutGet(GLUT_SCREEN_WIDTH)
#define HEIGHT_PC glutGet(GLUT_SCREEN_HEIGHT)

void display(void) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glDepthMask(GL_TRUE);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(WIDTH_GL, HEIGHT_GL);
    glutInitWindowPosition((WIDTH_PC - WIDTH_GL) / 2, (HEIGHT_PC - HEIGHT_GL) / 2);
    glutCreateWindow("Sala");

    glutDisplayFunc(display);

    //init();
    
    /*glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutReshapeFunc(reshape);*/

    glutMainLoop();

    return 0;
}
