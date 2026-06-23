#include <GL/glut.h>
GLfloat angle = 45.0f; // Initial rotation angle
GLfloat translationX = 0.0f, translationY = 0.0f; // Initial translation values
void drawObject() {
glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
glBegin(GL_POLYGON);
glVertex2f(-0.5f, -0.5f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.5f, 0.5f);
glVertex2f(-0.5f, 0.5f);
glEnd();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix(); // Save the current matrix
glTranslatef(translationX, translationY, 0.0f); // Apply translation
glRotatef(angle, 0.0f, 0.0f, 1.0f); // Apply rotation
drawObject(); // Draw the object after transformations
glPopMatrix(); // Restore the saved matrix
glutSwapBuffers();
}
void reshape(int width, int height) {
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y) {
switch (key) {
case 'r':
angle += 10.0f; // Increment rotation angle
break;
case 't':
translationX += 0.1f; // Increment translation along X
break;
case 'u':

translationY += 0.1f; // Increment translation along Y
break;
case 27: // ESC key
exit(0);
break;
}
glutPostRedisplay(); // Request a redraw
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutCreateWindow("Composite Transformation");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
glutMainLoop();
return 0;
}
