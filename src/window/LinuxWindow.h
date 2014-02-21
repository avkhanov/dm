/* 
 * File:   GLXWindow.h
 * Author: andrey
 *
 * Created on February 20, 2014, 2:20 PM
 */

#ifndef GLXWINDOW_H
#define	GLXWINDOW_H

#include "_WindowTemplate.h"

class LinuxWindow : public _WindowTemplate {
public:
        void setWidth(int width);
        void setHeight(int height);
        void setX(int x);
        void setY(int y);
        void show();
private:

};

#endif	/* GLXWINDOW_H */

