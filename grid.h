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
    int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> get_cell_color();
    std::vector<Color> colors;
};

#endif
