#include <vector>
#include "colors.h"

const Color light_gray = {200, 200, 200, 255}; // Light Gray
const Color gray = {130, 130, 130, 255};       // Gray
const Color yellow = {253, 249, 0, 255};       // Yellow
const Color gold = {255, 203, 0, 255};         // Gold
const Color orange = {255, 161, 0, 255};       // Orange
const Color pink = {255, 109, 194, 255};       // Pink
const Color red = {230, 41, 55, 255};          // Red
const Color green = {0, 228, 48, 255};         // Green
const Color blue = {0, 121, 241, 255};         // Blue
const Color purple = {200, 122, 255, 255};     // Purple
const Color brown = {127, 106, 79, 255};       // Brown
const Color white = {255, 255, 255, 255};      // White
const Color black = {0, 0, 0, 255};            // Black
const Color magenta = {255, 0, 255, 255};      // Magenta
const Color ray_white = {245, 245, 245, 255};  // White(raylib logo)

std::vector<Color> get_cell_color()
{
    return {blue, pink, green, brown, white, red};
}