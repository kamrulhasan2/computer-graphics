#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A,B,C,D; // values for scaling and shifting
void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);  //background color is white
  glColor3f(0.0f, 0.0f, 0.0f);  //drawing color is black
  glPointSize(4.0); //a dot is 2 by 2 pixels

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0, 1.0, -1.0, 1.0);

  A = screenWidth/4.0; //Set values for scaling and shifting
  B= 0.0;
  C=D=screenHeight/2.0;
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen
    glPointSize(2.0);

  GLint x,y, x1=50, x2=100, y1=100, y2=200;
  GLint dx, dy, inc1, inc2, d;

  x = x1;
  y = y1;

  dx = x2-x1;
  dy = y2-y1;

  inc1 = 2 * dy;
  inc2 = 2 * (dy-dx);

  d = inc1 - dx;

  while(x <= x2)
    {

      glBegin(GL_POINTS);
      {
	glVertex2i(x,y);
      }
      glEnd();

	  x++;

	  if(d < 0)
      d = d + inc1;

	  else {
		  d = d + inc2;
		  y++;
	  }

      }

  glFlush(); //send all output to display
}

int  main(int argc, char** argv)
{
  glutInit(&argc, argv);  //initialize the toolkit
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
  glutInitWindowSize(640,480);  //set window size
  glutInitWindowPosition(100,150);
  glutCreateWindow("My First Window");

  glutDisplayFunc(myDisplay);

  myInit();
  glutMainLoop();  //go into a perpetual loop

  //fprintf(stderr, "Hello!\n");
  return 1;

}
