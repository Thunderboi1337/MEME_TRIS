#pragma once

class Grid
{
public:
    Grid();
    void init(void);
    void print(void);
    int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellSize;
};
