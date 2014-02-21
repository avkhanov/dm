/* 
 * File:   _WindowTemplate.cpp
 * Author: Andrey
 * 
 * Created on February 19, 2014, 6:12 PM
 */

#include "_WindowTemplate.h"
#include "LinuxWindow.h"
#include <iostream>

void (*_WindowTemplate::m_setup_func)();
void (*_WindowTemplate::m_render_func)(void*);

void _WindowTemplate::default_setup_func() {}
void _WindowTemplate::default_render_func(void* data) {}
    
void _WindowTemplate::setSetupFunc(void (*setup_func)()) {
    _WindowTemplate::m_setup_func = setup_func;
}

void _WindowTemplate::setRenderFunc(void (*render_func)(void* data)) {
    _WindowTemplate::m_render_func = render_func;
}

_WindowTemplate::_WindowTemplate() {
    _WindowTemplate::m_setup_func = _WindowTemplate::default_setup_func;
    _WindowTemplate::m_render_func = _WindowTemplate::default_render_func;
}