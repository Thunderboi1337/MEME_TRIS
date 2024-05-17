#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

#define FPS 60

int main(void)
{

    const int screenWidth = 300;
    const int screenHeight = 600;
    Color darkBlue = {44, 44, 127, 255};

    Grid grid = Grid();
    grid.init();

    LBlock block = LBlock();

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization
    SetTargetFPS(FPS);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}