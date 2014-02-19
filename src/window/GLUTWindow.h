/*
 * GLUTWindow.h
 *
 *  Created on: Feb 18, 2014
 *      Author: andrey
 */

#ifndef GLUTWINDOW_H_
#define GLUTWINDOW_H_

#include "Window.h"
#include <stdlib.h>
#include <GL/glut.h>

class GLUTWindow: public Window {
public:
	GLUTWindow(int x, int y, int width, int height, int argc, char** argv);
	virtual ~GLUTWindow();
};

#endif /* GLUTWINDOW_H_ */
