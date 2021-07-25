#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void triangle()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2i (80, 150);
	glVertex2i (80, 250);
	glVertex2i (130,200);
	glEnd();
}
void line(int sx,int sy,int dx,int dy)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i (sx, sy);
	glVertex2i (dx, dy);
	glEnd();
}
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	
		line(100,150,100,250);
		triangle();

	glTranslatef(70.0, 20.0,0.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xF0F0);
	glScalef (1.5, 0.5, 1.0);

    line(100,150,100,250);
	triangle();

	glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0.0, 350.0, 0.0, 350.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (350, 350);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Transformation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

return 0;
}