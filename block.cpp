#include "block.h"
#include "colors.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = get_cell_color();
    rowOffset = 0;
    collumoffset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = get_cell_positions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int col)
{

    rowOffset += rows;
    collumoffset += col;
}

std::vector<Position> Block::get_cell_positions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + collumoffset);
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}