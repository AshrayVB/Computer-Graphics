// 3. Design a real world picture using primitive such as points, lines, triangles and polygons.



#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define winhe 600 // Window height
#define winwi 800 // Window width
#define pi 3.142857142857143

// Function to draw a circle
void circle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * pi * i / 100;
        float dx = cos(angle) * r;
        float dy = sin(angle) * r;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Function to clear the screen and set the coordinate system
void clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5, 0.8, 1.0, 1.0); // Light blue background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Coordinate system
}

// Function to draw a house
void drawhouse() {
    glColor3f(0.7, 0.4, 0.2); // Brown color for the house
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.1, -0.3);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Red color for the roof
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.7, 0.1);
    glVertex2f(-0.35, 0.4);
    glVertex2f(0.1, 0.1);
    glEnd();

    glColor3f(0.4, 0.2, 0.0); // Dark brown color for the door
    glBegin(GL_POLYGON);
    glVertex2f(-0.45, -0.3);
    glVertex2f(-0.25, -0.3);
    glVertex2f(-0.25, 0.0);
    glVertex2f(-0.45, 0.0);
    glEnd();
}

// Function to draw a tree at a specific position
void tree(float x, float y) {
    glColor3f(0.4, 0.2, 0.0); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.05, y - 0.2);
    glVertex2f(x + 0.05, y - 0.2);
    glVertex2f(x + 0.05, y);
    glVertex2f(x - 0.05, y);
    glEnd();

    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    circle(x, y + 0.1, 0.1);
    circle(x - 0.1, y, 0.1);
    circle(x + 0.1, y, 0.1);
}

// Function to draw the sun
void sun(float x, float y) {
    glColor3f(1.0, 1.0, 0.0); // Yellow color for the sun
    circle(x, y, 0.15);
}

// Function to draw the grass
void grass() {
    glColor3f(0.0, 0.8, 0.0); // Green color for the grass
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -0.3);
    glVertex2f(-1.0, -0.3);
    glEnd();
}

// Display function to draw all elements
void display() {
    clearScreen(); // Clear the screen at the start of the display
    grass();
    drawhouse();
    tree(-0.8, -0.3);
    tree(0.7, -0.3);
    sun(0.8, 0.8);
    glFlush(); // Ensure all commands are executed
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winwi, winhe);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Landscape with Primitives");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
