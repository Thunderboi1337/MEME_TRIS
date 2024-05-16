#ifndef COLORS_H
#define COLORS_H

#include <raylib.h>

extern const Color light_gray; // Light Gray
extern const Color gray;       // Gray
extern const Color yellow;     // Yellow
extern const Color gold;       // Gold
extern const Color orange;     // Orange
extern const Color pink;       // Pink
extern const Color red;        // Red
extern const Color green;      // Green
extern const Color blue;       // Blue
extern const Color purple;     // Purple
extern const Color brown;      // Brown
extern const Color white;      // White
extern const Color black;      // Black
extern const Color magenta;    // Magenta
extern const Color ray_white;  // White(raylib logo)

std::vector<Color> get_cell_color();

#endif
