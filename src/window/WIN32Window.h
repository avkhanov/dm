/* 
 * File:   WIN32Window.h
 * Author: Andrey
 *
 * Created on February 19, 2014, 6:10 PM
 */

#ifndef WIN32WINDOW_H
#define	WIN32WINDOW_H

#include "_WindowTemplate.h"
#include <windows.h>

class WIN32Window : public _WindowTemplate {
    private:
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        HINSTANCE m_hInstance;
        HINSTANCE m_hPrevInstance;
        LPSTR m_lpCmdLine;
        int m_nShowCmd;
        
        int m_width;
        int m_height;
        int m_x;
        int m_y;
    
    public:
        WIN32Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
        void setWidth(int width);
        void setHeight(int height);
        void setX(int x);
        void setY(int y);
        void show();
        int getWidth();
        int getHeight();
        int getX();
        int getY();
};

#endif	/* WIN32WINDOW_H */

