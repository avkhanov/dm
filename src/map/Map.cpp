/* 
 * File:   Map.cpp
 * Author: Andrey
 * 
 * Created on February 24, 2014, 6:23 PM
 */

#include "Map.h"

inline int randInt(int max) {
    return (rand() % max) + 1;
}

bool probTest(float success_chance) {
    if(success_chance > 1.0) {
        throw "Probability of success cannot be higher than 1";
    }
    
    float test = float(rand()) / RAND_MAX;
    
    if(test >= success_chance) {
        return false;
    } else {
        return true;
    }
}

Map::Map() {
}

Tile* Map::add_tile(int x, int y) {
    Tile* ret = new Tile(x, y);
    tile_list.push_back(ret);
    return ret;
}

void Map::generate_rect(Tile* start) {
    int width = randInt(Map::RECT_DIM);
    int height = randInt(Map::RECT_DIM);
    Tile* curx = start;
    Tile* cury = start;
    
    bool east = start->east == NULL;
    bool west = start->west == NULL;
    bool north = start->north == NULL;
    bool south = start->south == NULL;
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(east) {
                if(curx->x + 1 > max_east) {
                    max_east = curx->x + 1;
                }
                
                curx->east = add_tile(curx->x + 1, curx->y);
                curx = curx->east;
            } else if(west) {
                if(curx->x - 1 < max_west) {
                    max_west = curx->x - 1;
                }
                
                curx->west = add_tile(curx->x - 1, curx->y);
                curx = curx->west;
            }
        }
        
        if(north) {
            if(cury->y + 1 > max_north) {
                max_north = cury->y + 1;
            }
            
            cury->north = add_tile(cury->x, cury->y + 1);
            cury = cury->north;
        } else if(south) {
            if(cury->y - 1 < max_south) {
                max_south = cury->y - 1;
            }
            
            cury->south = add_tile(cury->x, cury->y - 1);
            cury = cury->south;
        }
        
        curx = cury;
    }
}

void Map::generate(long seed) {
    m_seed = seed;
    srand(seed);
    m_start_tile = m_exit_tile = add_tile(0, 0);
    
    generate_rect(m_start_tile);
    generate_rect(m_start_tile);
}

void Map::generate() {
    generate((long)time(NULL));
}

void Map::print() {
    int x_offset = -max_west;
    int y_offset = -max_south;
    int height = max_north - max_south;
    int width = max_east - max_west;
    
    std::cout << height << " " << width << std::endl;
    
    bool* array = new bool[width * height];
    //std::cout << "DIM: " << width * height << " " << x_offset << " " << y_offset << std::endl;
    
    std::vector<Tile*>::iterator i;
    for(i = tile_list.begin(); i != tile_list.end(); i++) {
        int x = (*i)->x + x_offset;
        int y = (*i)->y + y_offset;
        //std::cout << x << " " << y << " " << (y*width+x) << std::endl;
        array[y * width + x] = true;
    }
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            std::cout << x << " " << y << " " << (y*width+x) << "/" << (width * height) << std::endl;
            if(array[y * width + x]) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << width << " " << height << std::endl;
}