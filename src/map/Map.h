/* 
 * File:   Map.h
 * Author: Andrey
 *
 * Created on February 24, 2014, 6:23 PM
 */

#ifndef MAP_H
#define	MAP_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "Tile.h"

int randInt(int max);
bool probTest(float success_chance);

class Map {
private:
    static const int RECT_DIM = 10;
    int m_width = 0;
    int m_height = 0;
    int m_start_y = 0;
    
    int max_north = 0;
    int max_south = 0;
    int max_east = 0;
    int max_west = 0;
    
    long m_seed = 0;
    
    Tile* m_start_tile = NULL;
    Tile* m_exit_tile = NULL;
    std::vector<Tile*> tile_list;
    
    Tile* add_tile(int x, int y);
    void generate_rect(Tile* start);
    
public:
    Map();
    void generate(long seed);
    void generate();
    void print();
};

#endif	/* MAP_H */

