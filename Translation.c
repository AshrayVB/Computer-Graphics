// 13.Design a 2D object and show the object before and after translation.



#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

float translationX = 0.0f;
float translationY = 0.0f;

void clearScreen() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-2, 2, -2, 2);
}
void sq() {
	glBegin(GL_QUADS);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.05f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	sq();

	glPushMatrix();
	glTranslatef(0.5f, 0.5f, 0.0f);
	glColor3f(0.0, 1.0, 0.0);
	sq();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(translationX, translationY, 0.0f);
	glColor3f(0.0, 0.0, 1.0);
	sq();
	glPopMatrix();

	glFlush();
}
void timer(int val) {
	translationX += 0.01f;
	translationY += 0.01f;
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("13");
	clearScreen();

	glutDisplayFunc(draw);
	glutTimerFunc(1000, timer, 0);
	glutMainLoop();
}
