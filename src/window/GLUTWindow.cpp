/*
 * GLUTWindow.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: andrey
 */

#include "GLUTWindow.h"
#include <iostream>
using namespace std;

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glutSwapBuffers();
}

GLUTWindow::GLUTWindow(int x, int y, int width, int height, int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("DM");
	glutDisplayFunc(renderScene);
	glutMainLoop();
	cout << "Window should be visible..." << endl;
}

GLUTWindow::~GLUTWindow() {
	// TODO Auto-generated destructor stub
}

