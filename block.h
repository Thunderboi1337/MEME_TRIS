#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <vector>
#include <raylib.h>
#include "position.h"

class Block
{
public:
    Block();
    void Draw();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
};

#endif