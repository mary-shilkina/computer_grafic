#include "glew.h"
#include "glut.h"
float angle = 0.0f;
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
	glPushMatrix();

	glTranslatef(1.4, 0, -10);
	glRotatef(angle, 1, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 105, 180);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(1.4, 0, -5);
	glRotatef(angle, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 0);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(-2, 0, -5);
	glRotatef(angle, 0, 0, 1);

	glBegin(GL_TRIANGLES);
	glColor3ub(0, 255, 255);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();
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

	glewInit();
	glutMainLoop();
}