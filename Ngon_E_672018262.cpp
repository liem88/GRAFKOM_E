#include<Windows.h>
#include<gl/freeglut.h>
#include<gl/glut.h>
#include<math.h>

void init (void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(1.0);
	glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
	glViewport(40, 400, 60, 300);
}


void ngon(int n, float cx, float cy, float radius, float rotAngle )
{
	double angle, angleInc;
	int k;
	if(n<3)return;
	angle = rotAngle*3.14159265/360;
	angleInc = 2*3.14159265/n;
	glBegin(GL_LINE_LOOP);
	glVertex2f(radius *cos(angle)+cx, radius *sin(angle)+cy);
	for(k=0;k<n-1;k++)
	{
		angle += angleInc;
		glVertex2f(radius *cos(angle)+cx, radius *sin(angle)+cy);
	}
	glEnd();
}


void Display(void)
{
	int  i;
	glClear(GL_COLOR_BUFFER_BIT);	
			for(i=0;i<45;i++)
			{
				glColor3f(2-(i*0.05),(2-i*0.05),i*0.015); 
				ngon(6,0,0,i*0.2,100-(i*5));
			}
	glFlush();
	glutSwapBuffers();
}
 

int main(int argc, char** argv)
{
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
glutInitWindowSize(600, 600); 
glutInitWindowPosition(50, 50); 
glutCreateWindow("Theresia Mutiara Posumah-672018262");
init();
glutDisplayFunc(Display);
glutMainLoop(); 
return 0;
}