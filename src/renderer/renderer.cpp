#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "../map/Map.h"

void renderer_setup() {
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 500, 500);
}

void renderer(Map* map) {
    if(map == NULL) {
        return;
    }
    glViewport(0, 0, 500, 500);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1., 1., -1., 1., 1., 20.);
    glOrtho(-(double(map->width) * 0.1), double(map->width) * 1.1, double(map->height) * 1.1, -(double(map->height) * 0.1), 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);
    
    unsigned int size = map->width * map->height;
    
    for(unsigned int i = 0; i < size; i++) {
        if(map->map[i] != NULL) {
            Tile* t = map->map[i];
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_QUADS);
                glVertex3f(float(t->x) - 0.5f, float(t->y) - 0.5f, 0.0f);
                glVertex3f(float(t->x) + 0.5f, float(t->y) - 0.5f, 0.0f);
                glVertex3f(float(t->x) + 0.5f, float(t->y) + 0.5f, 0.0f);
                glVertex3f(float(t->x) - 0.5f, float(t->y) + 0.5f, 0.0f);
            glEnd();
        }
    }
} 
