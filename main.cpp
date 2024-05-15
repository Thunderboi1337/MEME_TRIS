#include "raylib.h"

#define FPS 60

int main(void)
{

    Color darkblue = {44, 44, 127, 255};

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Main"); // Initialization

    SetTargetFPS(FPS);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(darkblue);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}