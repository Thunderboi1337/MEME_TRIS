#include <raylib.h>
#include "game.h"

double last_update_time = 0;

bool event_trigger(double interval)
{

    double current_time = GetTime();
    if (current_time - last_update_time >= interval)
    {
        last_update_time = current_time;
        return true;
    }

    return false;
}

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
        if (event_trigger(0.2))
        {
            game.move_block_down();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}