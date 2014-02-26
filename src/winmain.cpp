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
#include "renderer/renderer.h"
#include "map/Map.h"
#include <iostream>
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd ) {
    /*WIN32Window* w = new WIN32Window(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    w->setSetupFunc(renderer_setup);
    w->setRenderFunc(renderer);
    w->show();*/
    Map* m = new Map(50, 0.1f);
    m->generate();
    //m->generate(1393377573);
    //m->generate(1393376962);
    m->print();
    
    return 0;
}

