/* 
 * File:   winmain.cpp
 * Author: Andrey
 *
 * Created on February 19, 2014, 5:04 PM
 */

#include <windows.h>
#include <GL/GL.h>
#include "window/WIN32Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {
    Window* w = new Window(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    w->show();
    return 0;
}

