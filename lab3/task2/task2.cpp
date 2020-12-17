#include "glew.h"
#include "glut.h"
float angle = 0.0f;
int a = 1;
int b = 0;
int c = 0;
void addmenu(int value)
{
	switch (value)
	{
	case 1:
		a = 1;
		b = 0;
		c = 0;
		break;
	case 2:
		a = 0;
		b = 1;
		c = 0;
		break;
	case 3:
		a = 0;
		b = 0;
		c = 1;

		break;
	default:
		break;
	}

}
void display()
{
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
	glRotatef(angle, a, b, c);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glBegin(GL_TRIANGLES);

	glColor3ub(255, 0, 0);//Red
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	glColor3ub(0, 255, 0);//Green
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3ub(0, 0, 255);//Blue left
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glColor3ub(48, 213, 200);//Cyan Right
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3ub(255, 255, 100);//yellow
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glColor3ub(140, 0, 255);//top
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glutSwapBuffers();
}
void idle()
{
	angle += 0.02f;
	glutPostRedisplay();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}
void main(int count, char* args[])
{
	glutInit(&count, args);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	int mainWindow = glutCreateWindow("Some Title");
	glutSetWindow(mainWindow);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutCreateMenu(addmenu);

	glutAddMenuEntry("x", 1);

	glutAddMenuEntry("y", 2);

	glutAddMenuEntry("z", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glewInit();
	glutMainLoop();
}