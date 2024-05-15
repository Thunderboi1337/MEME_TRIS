#include "grid.h"

Grid::Grid()
{

    numsRow = 20;
    numsCols = 10;
    cellSize = 30;
}

void Grid::init()
{
    for (int row = 0; row < numRows, row++)
    {
        for (int column = 0; column < numCols; column++)
        {

            grid([row][column] = 0);
        }
    }
}