// 6. Design a menu driven program to draw three different polygons using mouse interactions.



#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int polygonType = 0;

void clearScreen() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void tri(float x, float y) {
    glColor3f(1.0, 0.0, 0.0);  // Red color
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 50, y);
    glVertex2f(x + 25, y + 50);
    glEnd();
}

void rect(float x, float y) {
    glColor3f(0.0, 1.0, 0.0);  // Green color
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 60, y);
    glVertex2f(x + 60, y + 40);
    glVertex2f(x, y + 40);
    glEnd();
}

void pent(float x, float y) {
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(x + 25, y + 50);
    glVertex2f(x + 50, y + 30);
    glVertex2f(x + 40, y);
    glVertex2f(x + 10, y);
    glVertex2f(x, y + 30);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float xf = x;  // Mouse X position
        float yf = 480 - y;  // Convert Y to OpenGL coordinate system

        if (polygonType == 0) {
            tri(xf, yf);
        }
        else if (polygonType == 1) {
            rect(xf, yf);
        }
        else if (polygonType == 2) {
            pent(xf, yf);
        }
        glFlush();
    }
}

void menu(int option) {
    polygonType = option;
    glutPostRedisplay();  // Redraw the screen with the new polygon type
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("POLYGONS");

    clearScreen();

    glutCreateMenu(menu);
    glutAddMenuEntry("Tri", 0);
    glutAddMenuEntry("Rect", 1);
    glutAddMenuEntry("Pent", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
