#include "WIN32Window.h"
#include <windows.h>
#include <GL/GL.h>
#include <iostream>
using namespace std;

WIN32Window::WIN32Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    m_hInstance = hInstance;
    m_hPrevInstance = hPrevInstance;
    m_lpCmdLine = lpCmdLine;
    m_nShowCmd = nShowCmd;
}

void WIN32Window::setWidth(int width) {
    m_width = width;
}

void WIN32Window::setHeight(int height) {
    m_height = height;
}

void WIN32Window::setX(int x) {
    m_x = x;
}

void WIN32Window::setY(int y) {
    m_y = y;
}

int WIN32Window::getWidth() {
    return m_width;
}

int WIN32Window::getHeight() {
    return m_height;
}

int WIN32Window::getX() {
    return m_x;
}

int WIN32Window::getY() {
    return m_y;
}

void WIN32Window::show() {
    MSG msg          = {0};
    WNDCLASS wc      = {0}; 
    wc.lpfnWndProc   = WIN32Window::WndProc;
    wc.hInstance     = m_hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "DM";
    wc.style = CS_OWNDC;
    if( !RegisterClass(&wc) )
            return;
    HWND h = CreateWindow(wc.lpszClassName,"DM",WS_OVERLAPPEDWINDOW|WS_VISIBLE,0,0,640,480,0,0,m_hInstance,0);

    while( GetMessage( &msg, NULL, 0, 0 ) > 0 )
            DispatchMessage( &msg );
}

LRESULT CALLBACK WIN32Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch(message) {
        case WM_CREATE: {
            PIXELFORMATDESCRIPTOR pfd = {
                    sizeof(PIXELFORMATDESCRIPTOR),
                    1,
                    PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
                    PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
                    32,                        //Colordepth of the framebuffer.
                    0, 0, 0, 0, 0, 0,
                    0,
                    0,
                    0,
                    0, 0, 0, 0,
                    24,                        //Number of bits for the depthbuffer
                    8,                        //Number of bits for the stencilbuffer
                    0,                        //Number of Aux buffers in the framebuffer.
                    PFD_MAIN_PLANE,
                    0,
                    0, 0, 0
            };

            HDC ourWindowHandleToDeviceContext = GetDC(hWnd);

            int pixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd); 
            SetPixelFormat(ourWindowHandleToDeviceContext, pixelFormat, &pfd);

            HGLRC gl_context = wglCreateContext(ourWindowHandleToDeviceContext);
            wglMakeCurrent (ourWindowHandleToDeviceContext, gl_context);

            WIN32Window::m_setup_func();
        }
        break;
        case WM_CLOSE: {
            //wglDeleteContext(WIN32Window::gl_context);
            PostQuitMessage(0);
        }
        default: {
            WIN32Window::m_render_func(NULL);
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    
    return DefWindowProc(hWnd, message, wParam, lParam);
}
