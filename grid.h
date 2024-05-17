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
    bool is_cell_empty(int row, int col);
    int clear_full_rows();
    int grid[20][10];

private:
    bool is_row_full(int row);
    void clear_row(int row);
    void move_row_down(int row, int numrow);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};

#endif
