#include <iostream>
#include <raylib.h>
#include "game.h"

#define FPS 60

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

Texture2D atlas;

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 500;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization
    SetTargetFPS(FPS);

    Font font = LoadFontEx("Font/monogram.tff", 64, 0, 0);
    atlas = LoadTexture("memes/Pic.png");
    if (atlas.id == 0)
    {
        std::cerr << "Failed to load texture" << std::endl;
    }

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        game.handle_input();
        if (event_trigger(0.2))
        {
            game.move_block_down();
        }

        ClearBackground(darkBlue);

        DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
        if (game.game_over)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
        }

        char score_text[10];
        sprintf(score_text, "%d", game.score);
        Vector2 text_size = MeasureTextEx(font, score_text, 38, 2);

        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, LIGHTGRAY);
        DrawTextEx(font, score_text, {320 + (170 - text_size.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, LIGHTGRAY);

        game.Draw();

        if (atlas.id != 0)
        {
            DrawTextureEx(atlas, (Vector2){20, 20}, 0, 0.08, WHITE);
        }
        else
        {
            DrawText("Failed to load texture", 10, 10, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}