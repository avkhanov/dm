/* 
 * File:   _WindowTemplate.h
 * Author: Andrey
 *
 * Created on February 19, 2014, 6:12 PM
 */

#ifndef _WINDOWTEMPLATE_H
#define	_WINDOWTEMPLATE_H

class _WindowTemplate {
    public:
        virtual void setWidth(int width) = 0;
        virtual void setHeight(int height) = 0;
        virtual void setX(int x) = 0;
        virtual void setY(int y) = 0;
        virtual void show() = 0;
};

#endif	/* _WINDOWTEMPLATE_H */

