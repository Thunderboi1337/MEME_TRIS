#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    init();
    colors = get_cell_color();
}

void Grid::init()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void ::Grid::print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::is_cell_outside(int row, int col)
{
    if (row >= 0 && row < numRows && col >= 0 && col < numCols)
    {

        return false;
    }
    return true;
}

bool Grid::is_cell_empty(int row, int col)
{

    if (grid[row][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::clear_full_rows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (is_row_full(row))
        {
            clear_row(row);
            completed++;
        }
        else if (completed > 0)
        {
            move_row_down(row, completed);
        }
    }

    return completed;
}

bool Grid::is_row_full(int row)
{
    for (int col = 0; col < numCols; col++)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }

    return true;
}

void Grid::clear_row(int row)
{
    for (int col = 0; col < numCols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::move_row_down(int row, int num_rows)
{
    for (int col = 0; col < numCols; col++)
    {
        grid[row + num_rows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
