#include <iostream>
#include <raylib.h>
#include "grid.h"

#define FPS 60

#define FPS 60

int main(void)
{

    Color darkBlue = {44, 44, 127, 255};

    const int screenWidth = 300;
    const int screenHeight = 600;

    Grid grid = Grid();
    grid.init();
    grid.print();

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization
    SetTargetFPS(FPS);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(darkBlue);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}