#include <GL/glut.h>
GLfloat squareVertices[] = {-0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f};
GLfloat translation[] = {0.0f, 0.0f};
GLfloat rotationAngle = 0.0f;
void init() {
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
void drawSquare() {
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glTranslatef(translation[0], translation[1], 0.0);
glRotatef(rotationAngle, 0.0, 0.0, 1.0);
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
for (int i = 0; i < 8; i += 2) {
glVertex2f(squareVertices[i], squareVertices[i + 1]);
}
glEnd();
glFlush();
}
void keyboard(unsigned char key, int x, int y) {
switch (key) {
case 't':
translation[0] += 0.1;
break;
case 'T':
translation[0] -= 0.1;
break;
case 'r':
rotationAngle += 10.0;
break;
case 'R':
rotationAngle -= 10.0;
break;
case 27: // ESC key
exit(0);

break;
}
glutPostRedisplay();
}
int main(int argc, char **argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutCreateWindow("2D Translation and Rotation");
init();
glutDisplayFunc(drawSquare);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
