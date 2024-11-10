// 7. Implement a circle drawing algorithm.



#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void drawpixel(GLint cx, GLint cy) {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(cx, cy);
	glEnd();
}

void plotpixel(GLint h, GLint k, GLint x, GLint y) {
	drawpixel(x + h, y + k);
	drawpixel(-x + h, y + k);
	drawpixel(x + h, -y + k);
	drawpixel(-x + h, -y + k);
	drawpixel(y + h, x + k);
	drawpixel(-y + h, x + k);
	drawpixel(y + h, -x + k);
	drawpixel(-y + h, -x + k);
}

void circle(GLint xc, GLint yc, GLint r) {
	GLint d = 1 - r, x = 0, y = r;
	while (y > x) {
		plotpixel(xc, yc, x, y);
		if (d < 0) {
			d += 2 * x + 3;
		}
		else {
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixel(xc, yc, x, y);

}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	circle(320, 240, 100);
	glFlush();

}
void clearScreen() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 640, 0, 480);

}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle");
	clearScreen();
	glutDisplayFunc(display);
	glutMainLoop();
}
