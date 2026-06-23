#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
int windowWidth = 800;
int windowHeight = 600;
void drawEllipse(int a, int b, int h, int k) {
glClear(GL_COLOR_BUFFER_BIT);
float p1, p2;
int x, y;
// Region 1
x = 0;
y = b;
p1 = (b * b) - (a * a * b) + (0.25 * a * a);
glBegin(GL_POINTS);
while ((2 * a * a * y) >= (2 * b * b * x)) {
glVertex2f(x + h, y + k);
glVertex2f(-x + h, y + k);
glVertex2f(x + h, -y + k);
glVertex2f(-x + h, -y + k);
if (p1 < 0) {
x++;
p1 = p1 + (2 * b * b * x) + (b * b);
} else {
x++;
y--;
p1 = p1 + (2 * b * b * x) - (2 * a * a * y) + (b * b);
}
}
// Region 2
p2 = (b * b * (x + 0.5) * (x + 0.5)) + (a * a * (y - 1) * (y - 1)) - (a * a * b * b);
while (y >= 0) {
glVertex2f(x + h, y + k);
glVertex2f(-x + h, y + k);
glVertex2f(x + h, -y + k);
glVertex2f(-x + h, -y + k);
if (p2 > 0) {
y--;

p2 = p2 - (2 * a * a * y) + (a * a);
} else {
x++;
y--;
p2 = p2 + (2 * b * b * x) - (2 * a * a * y) + (a * a);
}
}
glEnd();
glFlush();
}
void display() {
glClearColor(1, 1, 1, 1);
glColor3f(0, 0, 0);
glPointSize(2);
int a = 30; // major axis
int b = 20; // minor axis
int h = windowWidth / 2; // x-coordinate of center
int k = windowHeight / 2; // y-coordinate of center
drawEllipse(a, b, h, k);
}
void reshape(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, w, 0, h);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(windowWidth, windowHeight);
glutCreateWindow("Midpoint Ellipse Algorithm");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
