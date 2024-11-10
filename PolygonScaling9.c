// 9. Implement the program to draw a polygon that interact with input keyboard functions to scale the object.



//polygon Scaling
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>

float scale = 0.1f;

void clearScreen() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-10, 10, -10, 10);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '+':
		scale += 0.1f;
		break;
	case '-':
		if (scale > 0.1f)scale -= 0.1f;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glScalef(scale, scale, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-10.0f, -10.0f);
	glVertex2f(10.0f, -10.0f);
	glVertex2f(0.0f, 10.0f);
	glEnd();
	glPopMatrix();
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("POLYGON");
	clearScreen();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
