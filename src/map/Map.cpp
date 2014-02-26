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

inline int randInt(int min, int max) {
    return (rand() % (max - min)) + min;
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

Map::Map(int complexity, float density) {
    m_complexity = complexity;
    m_density = density;
}

void Map::generate(unsigned int seed) {
    this->seed = seed;
    srand(seed);
    //std::cout << "SEED: " << this->seed << std::endl;
    
    int area = int(float(m_complexity) / m_density);
    width = randInt(int(float(area) * 0.05), int(float(area) * 0.15));
    height = int(ceil(double(area) / double(width)));
    
    map = new Tile*[width * height];
    std::deque<Block*> blocks;
    
    for(int i = 0; i < width * height; i++) {
        map[i] = NULL;
    }
    
    for(int i = 0; i < m_complexity; i++) {
        bool redo = false;
        int redos = 0;
        
        do {
            int x = randInt(width) - 1;
            int y = randInt(height) - 1;
            //std::cout << x << " " << y << std::endl;
            
            if(map[y * width + x] != NULL) {
                redo = true;
                redos++;
            } else {
                map[y * width + x] = new Tile(x, y);
                Block* block = new Block();
                block->tiles.push_back(map[y * width + x]);
                blocks.push_back(block);
                
                redo = false;
            }
        } while(redo && redos < area);
    }
    
    int size = blocks.size();
    //for(int i = 0; i < size - 1; i++) {
    while(blocks.size() > 1) {
        Block* b = blocks.front();
        blocks.pop_front();
        
        int smallest_distance = -1;
        int other_block = 0;
        int this_block_idx = 0;
        int other_block_idx = 0;
        
        for(unsigned int j = 0; j < blocks.size(); j++) {
            Block* test = blocks[j];
            for(unsigned int b1 = 0; b1 < b->tiles.size(); b1++) {
                for(unsigned int b2 = 0; b2 < test->tiles.size(); b2++) {
                    int dist = Map::gridDistance(b->tiles[b1]->x, b->tiles[b1]->y, test->tiles[b2]->x, test->tiles[b2]->y);
                    if(dist < smallest_distance || smallest_distance == -1) {
                        smallest_distance = dist;
                        other_block = j;
                        this_block_idx = b1;
                        other_block_idx = b2;
                    }
                }
            }
        }
        
        Block* ob = blocks[other_block];
        blocks.erase(blocks.begin() + other_block);
        
        for(unsigned int i = 0; i < ob->tiles.size(); i++) {
            b->tiles.push_back(ob->tiles[i]);
        }
                
        Tile* t1 = b->tiles[this_block_idx];
        Tile* t2 = ob->tiles[other_block_idx];
        int north_south = t2->y - t1->y;
        int east_west = t2->x - t1->x;
        int ns_dir = north_south == 0 ? 0 : (north_south / abs(north_south));
        int ew_dir = east_west == 0 ? 0 : (east_west / abs(east_west));
        
        Tile* cur_tile = t1;
        
        //std::cout << "(" << t1->x << "," << t1->y << ") to (" << t2->x << "," << t2->y << ") RIGHT: " << east_west << " DOWN: " << north_south << " " << smallest_distance << std::endl;
        //std::cout << "EW: " << ew_dir << " NS: " << ns_dir << std::endl;
        while(north_south != 0 || east_west != 0) {
            bool ns = probTest(0.5); //should we go north-south?
            //std::cout << "Going north-south? " << ns << std::endl;
            if((ns || east_west == 0) && north_south != 0) {
                //std::cout << "We are going north-south..." << std::endl;
                int index = (cur_tile->y + ns_dir) * width + cur_tile->x;
                //std::cout << "going to (" << cur_tile->x << "," << cur_tile->y + ns_dir << ")" << std::endl;
                if(map[index] == NULL) {
                    map[index] = new Tile(cur_tile->x, cur_tile->y + ns_dir);
                    b->tiles.push_back(map[index]);
                }
                cur_tile = map[index];
                north_south -= ns_dir;
            } else if((!ns || north_south == 0) && east_west != 0) {
                //std::cout << "We are going east-west..." << std::endl;
                int index = cur_tile->y * width + cur_tile->x + ew_dir;
                //std::cout << "going to (" << cur_tile->x + ew_dir << "," << cur_tile->y << ")" << std::endl;
                if(map[index] == NULL) {
                    map[index] = new Tile(cur_tile->x + ew_dir, cur_tile->y);
                    b->tiles.push_back(map[index]);
                }
                cur_tile = map[index];
                east_west -= ew_dir;
            }
        }
        
        delete ob;
        blocks.push_back(b);
    }
    
    //std::cout << width << " " << height << " " << blocks.size() << std::endl;
}

void Map::generate() {
    generate((unsigned int)(time(NULL)));
}

void Map::print() {
    if(map == NULL) {
        return;
    }
    
    std::cout << "+";
    for(int x = 0; x < width; x++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
    
    for(int y = 0; y < height; y++) {
        std::cout << "|";
        
        for(int x = 0; x < width; x++) {
            if(map[y * width + x] != NULL) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        
        std::cout << "|" << std::endl;
    }
    
    std::cout << "+";
    for(int x = 0; x < width; x++) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
    std::cout << std::endl << "W:" << width << " H:" << height << " SEED:" << seed << std::endl;
}

int Map::gridDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}