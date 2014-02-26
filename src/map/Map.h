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
#include <cmath>
#include <vector>
#include <deque>
#include <iostream>
#include "Tile.h"

int randInt(int max);
bool probTest(float success_chance);

class Map {
private:
    class Block {
    public:
        std::vector<Tile*> tiles;
    };
    float m_density; // nodes per Area
    int m_complexity; // Number of nodes
    unsigned int seed;
public:
    Tile** map = NULL;
    int width = 0;
    int height = 0;
    Map(int complexity, float density);
    static int gridDistance(int x1, int y1, int x2, int y2);
    void generate(unsigned int seed);
    void generate();
    void print();
};

#endif	/* MAP_H */

