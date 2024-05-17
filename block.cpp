#include "block.h"
#include "colors.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = get_cell_color();
}

void ::Block::Draw()
{
}