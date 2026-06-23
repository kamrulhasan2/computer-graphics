#include <GL/glut.h>
int windowWidth = 800;
int windowHeight = 600;
float scaleX = 1.0f;
float scaleY = 1.0f;
float translateX = 0.0f;
float translateY = 0.0f;
void init() {
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
}
void drawRectangle() {
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex2f(100.0, 100.0);
glVertex2f(200.0, 100.0);
glVertex2f(200.0, 200.0);
glVertex2f(100.0, 200.0);
glEnd();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
// Apply scaling and translation transformations
glTranslatef(translateX, translateY, 0.0);
glScalef(scaleX, scaleY, 1.0);
drawRectangle();
glFlush();
}
void reshape(int width, int height) {
windowWidth = width;
windowHeight = height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(windowWidth, windowHeight);
glutCreateWindow("2D Scaling and Translation");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
