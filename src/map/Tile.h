/* 
 * File:   Tile.h
 * Author: Andrey
 *
 * Created on February 24, 2014, 6:31 PM
 */

#ifndef TILE_H
#define	TILE_H
#include <cstdlib>

class Tile {
private:

public:
    Tile* north = NULL;
    Tile* east = NULL;
    Tile* west = NULL;
    Tile* south = NULL;
    int x = 0;
    int y = 0;
    Tile(int x, int y);
};

#endif	/* TILE_H */

