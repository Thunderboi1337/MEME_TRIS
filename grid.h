#pragma once

class Grid
{
public:
    Grid();
    void init();
    int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellsize;
};
