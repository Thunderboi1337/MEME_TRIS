#include <raylib.h>
#include "game.h"

#define FPS 60

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization
    SetTargetFPS(FPS);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.handle_input();
        BeginDrawing();

        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}