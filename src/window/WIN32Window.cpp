#include "WIN32Window.h"
#include <windows.h>
#include <GL/GL.h>

Window::Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    m_hInstance = hInstance;
    m_hPrevInstance = hPrevInstance;
    m_lpCmdLine = lpCmdLine;
    m_nShowCmd = nShowCmd;
}

void Window::setWidth(int width) {
    
}

void Window::setHeight(int height) {
    
}

void Window::setX(int x) {
    
}

void Window::setY(int y) {
    
}

void Window::show() {
    MSG msg          = {0};
    WNDCLASS wc      = {0}; 
    wc.lpfnWndProc   = Window::WndProc;
    wc.hInstance     = m_hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.lpszClassName = "DM";
    wc.style = CS_OWNDC;
    
    if(!RegisterClass(&wc)) {
        return;
    }
    
    CreateWindow(wc.lpszClassName,"DM",WS_OVERLAPPEDWINDOW|WS_VISIBLE,0,0,640,480,0,0,m_hInstance,0);

    while( GetMessage( &msg, NULL, 0, 0 ) > 0 ) {
        DispatchMessage( &msg );
    }
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
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

                int  letWindowsChooseThisPixelFormat;
                letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd); 
                SetPixelFormat(ourWindowHandleToDeviceContext,letWindowsChooseThisPixelFormat, &pfd);

                HGLRC ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
                wglMakeCurrent (ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

                MessageBoxA(0,(char*)glGetString(GL_VERSION), "OPENGL VERSION",0);

                wglDeleteContext(ourOpenGLRenderingContext);
                PostQuitMessage(0);
        }
        break;
        default: {
                return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    
    return 0;
}