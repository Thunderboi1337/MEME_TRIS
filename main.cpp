

#include "raylib.h"

int main(void)
{
    const int screenWidth = 600;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization

    CloseWindow(); // Close window and OpenGL context

    return 0;
}