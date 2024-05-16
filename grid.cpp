#include "grid.h"
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

std::vector<Color> Grid::get_cell_color()
{
    Color light_gray = {200, 200, 200, 255}; // Light Gray
    Color gray = {130, 130, 130, 255};       // Gray
    Color dark_gray = {80, 80, 80, 255};     // Dark Gray
    Color yellow = {253, 249, 0, 255};       // Yellow
    Color gold = {255, 203, 0, 255};         // Gold
    Color orange = {255, 161, 0, 255};       // Orange
    Color pink = {255, 109, 194, 255};       // Pink
    Color red = {230, 41, 55, 255};          // Red
    Color maroon = {190, 33, 55, 255};       // Maroon
    Color green = {0, 228, 48, 255};         // Green
    Color lime = {0, 158, 47, 255};          // Lime
    Color dark_green = {0, 117, 44, 255};    // Dark Green
    Color sky_blue = {102, 191, 255, 255};   // Sky Blue
    Color blue = {0, 121, 241, 255};         // Blue
    Color dark_blue = {0, 82, 172, 255};     // Dark Blue
    Color purple = {200, 122, 255, 255};     // Purple
    Color violet = {135, 60, 190, 255};      // Violet
    Color dark_purple = {112, 31, 126, 255}; // Dark Purple
    Color beige = {211, 176, 131, 255};      // Beige
    Color brown = {127, 106, 79, 255};       // Brown
    Color dark_brown = {76, 63, 47, 255};    // Dark Brown

    Color white = {255, 255, 255, 255};     // White
    Color black = {0, 0, 0, 255};           // Black
    Color blank = {0, 0, 0, 0};             // Blank (Transparent)
    Color magenta = {255, 0, 255, 255};     // Magenta
    Color ray_white = {245, 245, 245, 255}; // White(raylib logo)

    return {yellow, green, red, purple, blue};
}

void Grid::Draw()
{

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize, row * cellSize, cellSize, colors[cellValue]);
        }
    }
}