// 11.Design a program that plots a red-point, with a point-size equal to 3, at the position of the mouse cursor in the display window, each time when you press the left mouse button.



#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>

#define POINT_SIZE 3
#define MAXPOINT 1000

float points[MAXPOINT][2];
int pointCount = 0;

void clearScreen() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(POINT_SIZE);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (pointCount < MAXPOINT) {
			points[pointCount][0] = x;
			points[pointCount][1] = 500 - y;
			pointCount++;
			glutPostRedisplay();
		}
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (int i = 0; i < pointCount; i++)
		glVertex2f(points[i][0], points[i][1]);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3 POINTS");
	clearScreen();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}
