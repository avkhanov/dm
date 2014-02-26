/* 
 * File:   _WindowTemplate.cpp
 * Author: Andrey
 * 
 * Created on February 19, 2014, 6:12 PM
 */

#include "_WindowTemplate.h"
#include "LinuxWindow.h"
#include "../map/Map.h"
#include <iostream>

Map* _WindowTemplate::m_map = NULL;

void (*_WindowTemplate::m_setup_func)();
void (*_WindowTemplate::m_render_func)(Map* map);

void _WindowTemplate::default_setup_func() {}
void _WindowTemplate::default_render_func(Map* map) {}
    
void _WindowTemplate::setSetupFunc(void (*setup_func)()) {
    _WindowTemplate::m_setup_func = setup_func;
}

void _WindowTemplate::setRenderFunc(void (*render_func)(Map* map)) {
    _WindowTemplate::m_render_func = render_func;
}

_WindowTemplate::_WindowTemplate() {
    _WindowTemplate::m_setup_func = _WindowTemplate::default_setup_func;
    _WindowTemplate::m_render_func = _WindowTemplate::default_render_func;
}

void _WindowTemplate::attachMap(Map* map) {
    m_map = map;
}