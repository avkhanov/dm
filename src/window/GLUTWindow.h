/*
 * GLUTWindow.h
 *
 *  Created on: Feb 18, 2014
 *      Author: andrey
 */

#ifndef GLUTWINDOW_H_
#define GLUTWINDOW_H_

#include "Window.h"
#include <GL/glut.h>

class GLUTWindow: public Window {
public:
	GLUTWindow();
	virtual ~GLUTWindow();
};

#endif /* GLUTWINDOW_H_ */
