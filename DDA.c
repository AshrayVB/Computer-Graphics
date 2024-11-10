// Design a line using DDA line drawing algorithm



#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 500
#define GRAPH_HEIGHT 20
#define GRAPH_WIDTH 20

void clearScreen(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, GRAPH_HEIGHT, 0, GRAPH_WIDTH);
}

void display(){
    float x0 = 5.0;
    float y0 = 7.0;

    float x1 = 10.0;
    float y1 = 15.0;

    float dx = abs(x1 - x0);
    float dy = abs(y1 - y0);

    float slope = dy / dx;

    float step;
    if (slope > 1)
        step = dy;
    else
        step = dx;

    float x_incr = dx / step;
    float y_incr = dy / step;

    float x = x0;
    float y = y0;
    for (int i = 0; i < step; i++){
        glBegin(GL_POINTS);
        glPointSize(2.0);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2f(x, y);
        glEnd();
        glFlush();

        x += x_incr;
        y += y_incr;
    }
}

void main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA Algorithm");
    clearScreen();
    glutDisplayFunc(display);
    glutMainLoop();
}
