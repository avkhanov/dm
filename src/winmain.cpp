/* 
 * File:   winmain.cpp
 * Author: Andrey
 *
 * Created on February 19, 2014, 5:04 PM
 */

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "window/WIN32Window.h"
#include <iostream>
using namespace std;

void setup() {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 640, 480);
}

void DrawAQuad(void* data) {
    glViewport(0, 0, 640, 480);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1., 1., -1., 1., 1., 20.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);

    glBegin(GL_QUADS);
        glColor3f(1., 0., 0.); glVertex3f(-.75, -.75, 0.);
        glColor3f(0., 1., 0.); glVertex3f( .75, -.75, 0.);
        glColor3f(0., 0., 1.); glVertex3f( .75,  .75, 0.);
        glColor3f(1., 1., 0.); glVertex3f(-.75,  .75, 0.);
    glEnd();
} 

void render(void* data) {
    
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {
    WIN32Window* w = new WIN32Window(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    w->setSetupFunc(setup);
    w->setRenderFunc(DrawAQuad);
    w->show();
    return 0;
}

