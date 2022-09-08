#include "quarto.h"
#include <iostream>
#include <math.h>
#include <cstdio>

GLint WIDTH_GL = 800;
GLint HEIGHT_GL = 600;

#define WIDTH_PC glutGet(GLUT_SCREEN_WIDTH)
#define HEIGHT_PC glutGet(GLUT_SCREEN_HEIGHT)

GLdouble tetaxz = 0;
GLdouble raioxz = 5;

GLdouble obs[3]  = {raioxz * cos(2 * M_PI * tetaxz / 360), 3.5, raioxz * sin(2 * M_PI * tetaxz / 360)};
GLdouble olho[3] = {0.0,3.0,0.0};

GLfloat plano_difusa[]    = { 1.0, 1.0, 1.0, 1.0 };
GLfloat plano_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat plano_brilho[]    = { 50.0 };

GLfloat mat_a_difusa[]    = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_a_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_a_brilho[]    = { 50.0 };

GLfloat mat_b_difusa[]    = { 0.7, 0.7, 0.7, 0.5 };
GLfloat mat_b_especular[] = { 1.0, 1.0, 1.0, 0.5 };
GLfloat mat_b_brilho[]    = { 50.0 };

GLfloat posicao_luz0[]    = { -2.5, 3.0, -7.5, 1.0};
GLfloat cor_luz0[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz0_amb[]    = { 1.0, 1.0, 1.0, 1.0};

GLfloat posicao_luz1[]    = { 0.0, 10.0, 5.0, 1.0};
GLfloat cor_luz1[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat direcao_luz1[]    = { 0.0, -10.0, -5.0, 1.0};
GLint   spot_luz1         = 30;

GLfloat sem_cor[]         = { 0.0, 0.0, 0.0, 1.0};
    
GLint gouraud = 1;
GLint move    = 0;

void reshape(int width, int height) {
    WIDTH_GL=width;
    HEIGHT_GL=height;
    glViewport(0,0,(GLint)width,(GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0,width/(float)height,0.1,30.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glDepthMask(GL_TRUE);
    glClearColor(0.9,0.9,0.9,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if(gouraud) {
        glShadeModel(GL_SMOOTH);
    }
    else {
        glShadeModel(GL_FLAT);
    }    
    
    glPushMatrix();

    gluLookAt(obs[0],obs[1],obs[2],olho[0],olho[1],olho[2],0.0,1.0,0.0);
    
    /* propriedades do material do plano */
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, plano_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, plano_especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, plano_brilho);
    
    glNormal3f(0,1,0); 

    chao();
    paredes();
    teto();
    som();
    tv();

    glPushMatrix();
    glTranslatef(posicao_luz0[0],posicao_luz0[1],posicao_luz0[2]);
    glMaterialfv(GL_FRONT, GL_EMISSION, cor_luz0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_EMISSION, sem_cor);

    glPopMatrix();
    glutSwapBuffers();
}

void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            if (move == 0) {
                olho[1] += 0.5;
            }
            else if (obs[0] > -4.5) {
                obs[0] -= 0.5;
                olho[0] -= 0.5;
            }

            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            if (move == 0) {
                olho[1] -= 0.5;
            }
            else if (obs[0] < 5) {
                obs[0] += 0.5;
                olho[0] += 0.5;
            }

            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:

            olho[2] += 0.5;

            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:

            olho[2] -= 0.5;
            
            glutPostRedisplay();
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'g':
        gouraud = !gouraud;
        glutPostRedisplay();
        break;
    case 'm':
        move = 1 - move;
    }
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz0_amb);
    glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz0);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, cor_luz1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, cor_luz1);
    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, spot_luz1);
    glLightfv(GL_LIGHT1, GL_POSITION, posicao_luz1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_luz1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
}

void menu(int value) {
    switch (value) {
    case 0:
        mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=0.0;
        break;
    case 1: 
        mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=0.5;
        break;
    case 2:
        mat_a_especular[0]=mat_a_especular[1]=mat_a_especular[2]=1.0;
        break;
    case 3:
        mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=0.0;
        break;
    case 4: 
        mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=0.5;
        break;
    case 5:
        mat_a_difusa[0]=mat_a_difusa[1]=mat_a_difusa[2]=1.0;
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char **argv) {
    glutInitWindowPosition((WIDTH_PC - WIDTH_GL) / 2, (HEIGHT_PC - HEIGHT_GL) / 2);
    glutInitWindowSize(WIDTH_GL,HEIGHT_GL);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);

    if(!glutCreateWindow("Modelos de iluminacao")) {
        fprintf(stderr,"Error opening a window.\n");
        exit(-1);
    }

    init();
    
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutCreateMenu(menu);
    glutAddMenuEntry("-sem spec", 0);
    glutAddMenuEntry("-spec m�dia", 1);
    glutAddMenuEntry("-spec alta", 2);
    glutAddMenuEntry("-sem difusa", 3);
    glutAddMenuEntry("-difusa m�dia", 4);
    glutAddMenuEntry("-difusa alta", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();

    return 0;
}
