#pragma once
#include <iostream>
#include "Viewer.h"

using namespace std;//�ι�° Ŀ��

Viewer OpenGL_Viewer;

void Initialize(void)
{
	OpenGL_Viewer.Initialize();
}

void Render(void)
{
	OpenGL_Viewer.Render();
}

void Reshape(int w, int h)
{
	OpenGL_Viewer.Reshape(w, h);
}

void Keyboard(unsigned char key, int x, int y)
{
	OpenGL_Viewer.Keyboard(key, x, y);
}

void Update(int value)
{
	OpenGL_Viewer.Update();

	glutPostRedisplay();
	glutTimerFunc(10, Update, 0);
}

int main(int argc, char ** argv)
{
	//InitGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Smoothed-Particle Hydrodynamics Simulation");

	Initialize();
	glutTimerFunc(10, Update, 0);
	glutDisplayFunc(Render);

	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);

	glutMainLoop();

	return 0;
}