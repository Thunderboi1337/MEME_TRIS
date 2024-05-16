#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <map>
#include "position.h"

class Block
{
public:
    Block();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
};

#endif