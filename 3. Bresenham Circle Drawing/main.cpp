#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);  //background color is white
  glColor3f(0.0f, 0.0f, 0.0f);  //drawing color is black
  glPointSize(4.0); //a dot is 2 by 2 pixels

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);   //clear the screen

  glPointSize(2.0);
  GLint h = 200,k = 200, x, y, r, d;

  y = r = 100;
  d = 3 - 2*r;

  for(x=0; x<=y; x++)
    {
	  glBegin(GL_POINTS);
      {

	glVertex2i(x+h,y+k);
	glVertex2i(x+h,k-y);
	glVertex2i(y+h,x+k);
	glVertex2i(y+h,k-x);
	glVertex2i(-y+h,x+k);
	glVertex2i(-y+h,k-x);
	glVertex2i(-x+h,y+k);
	glVertex2i(-x+h,k-y);
      }
      glEnd();
	  if(d<0)
		  d = d + 4*x + 6;
	  else{
		  d = d + 4*(x-y) + 10;
		  y--;
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

return 1;

}
