#ifndef MAP_H
#define MAP_H
#include <Vector>

const int MAPWIDTH = 17;
const int MAPHEIGHT = 17;
const size_t REALSIZE = 15;//we only use 15*15 part of the grid

//Map representing a grid of size 15*15, in which the entry 1 indicating a block, and 0 indicating space the player can go
class Map{
public:
    Map();
    //~Map();
    int getValue(int x, int y);
    void setValue(int x, int y, int value);
private:
    std::vector<std::vector<int>> arr;
};



#endif // MAP_H
