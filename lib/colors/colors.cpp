#include <vector>
#include "colors.h"

const Color darkgray = {26, 31, 40, 255}; // Gray
const Color yellow = {253, 249, 0, 255};  // Yellow
const Color orange = {255, 161, 0, 255};  // Orange
const Color pink = {255, 109, 194, 255};  // Pink
const Color red = {230, 41, 55, 255};     // Red
const Color green = {0, 228, 48, 255};    // Green
const Color blue = {0, 121, 241, 255};    // Blue
const Color cyan = {21, 204, 209, 255};   // Cyan
const Color purple = {166, 0, 216, 255};  // Purple

std::vector<Color> get_cell_color()
{
    return {darkgray, green, red, yellow, orange, purple, blue, cyan};
}