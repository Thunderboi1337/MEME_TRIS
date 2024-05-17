#ifndef GRID_H
#define GRID_H

#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void init(void);
    void print(void);
    void Draw();
    bool is_cell_outside(int row, int col);
    int grid[20][10];

private:
    std::vector<Color> colors;
    int numRows;
    int numCols;
    int cellSize;
};

#endif
