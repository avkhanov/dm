/* 
 * File:   LinuxWindow.cpp
 * Author: andrey
 * 
 * Created on February 20, 2014, 2:20 PM
 */

#include "LinuxWindow.h"
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

void LinuxWindow::setWidth(int width) {
    
}

void LinuxWindow::setHeight(int height) {
    
}

void LinuxWindow::setX(int x) {
    
}

void LinuxWindow::setY(int y) {
    
}

void LinuxWindow::close() {
    
}

int LinuxWindow::getWidth() {
    return 0;
}

int LinuxWindow::getHeight() {
    return 0;
}

int LinuxWindow::getX() {
    return 0;
}

int LinuxWindow::getY() {
    return 0;
}

void LinuxWindow::show() {
    Display* dpy;
    Window root;
    GLint att[] = {
        GLX_RGBA,
        GLX_DEPTH_SIZE,
        24,
        GLX_DOUBLEBUFFER,
        None
    };
    XVisualInfo* vi;
    Colormap cmap;
    XSetWindowAttributes swa;
    Window win;
    GLXContext glc;
    XWindowAttributes gwa;
    XEvent xev;
    
    dpy = XOpenDisplay(NULL);
    
    if(dpy == NULL) {
        return;
    }
    
    root = DefaultRootWindow(dpy);
    vi = glXChooseVisual(dpy, 0, att);
    
    if(vi == NULL) {
        return;
    }
    
    cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.event_mask = ExposureMask | KeyPressMask;
    
    win = XCreateWindow(dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
    XMapWindow(dpy, win);
    XStoreName(dpy, win, "DM");
    glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
    glXMakeCurrent(dpy, win, glc);
    
    LinuxWindow::m_setup_func();
    
    while(1) {
        XNextEvent(dpy, &xev);

        if(xev.type == Expose) {
                XGetWindowAttributes(dpy, win, &gwa);
                glViewport(0, 0, gwa.width, gwa.height);
                LinuxWindow::m_render_func(NULL);
                glXSwapBuffers(dpy, win);
        } else if(xev.type == KeyPress) {
                glXMakeCurrent(dpy, None, NULL);
                glXDestroyContext(dpy, glc);
                XDestroyWindow(dpy, win);
                XCloseDisplay(dpy);
                return;
        }
    }
}
