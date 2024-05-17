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
    void Move(int rows, int col);
    std::vector<Position> get_cell_positions();
    void rotate();
    void undo_rotate();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotation_state;
    std::vector<Color> colors;
    int rowOffset;
    int collumoffset;
};

#endif