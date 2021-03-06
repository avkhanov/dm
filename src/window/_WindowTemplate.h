/* 
 * File:   _WindowTemplate.h
 * Author: Andrey
 *
 * Created on February 19, 2014, 6:12 PM
 */

#ifndef _WINDOWTEMPLATE_H
#define	_WINDOWTEMPLATE_H

#include "../map/Map.h"

class _WindowTemplate {
protected:
    static void (*m_setup_func)();
    static void (*m_render_func)(Map* map);
    static Map* m_map;
private:
    static void default_setup_func();
    static void default_render_func(Map* map);
public:
    _WindowTemplate();
    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual void show() = 0;
    virtual void close() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    void attachMap(Map* map);
    void setSetupFunc(void (*setup_func)());
    void setRenderFunc(void (*render_func)(Map* map));
};

#endif	/* _WINDOWTEMPLATE_H */

