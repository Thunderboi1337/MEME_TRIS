#include <iostream>
#include <raylib.h>
#include "game.h"
#include "screens.h"
#include "menu.h"

#define FPS 60

double last_update_time = 0;
GameScreen currentScreen = LOGO;

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

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 500;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Main window"); // Initialization
    SetTargetFPS(FPS);

    Font font = LoadFontEx("Font/monogram.tff", 64, 0, 0);

    currentScreen = LOGO;
    InitLogoScreen();
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        switch (currentScreen)
        {
        case LOGO:
        {

            ClearBackground(WHITE);
            UpdateLogoScreen();
            DrawLogoScreen();

            if (FinishLogoScreen())
            {
                currentScreen = GAME;
            }
            DrawRectangle(GetScreenWidth() - 200, GetScreenHeight() - 50, 200, 40, Fade(WHITE, 0.6f));
            DrawText("ALPHA VERSION", GetScreenWidth() - 180, GetScreenHeight() - 40, 20, DARKGRAY);
            break;
        }
        case MENU:
        {

            ClearBackground(WHITE);
            UpdateLogoScreen();
            DrawLogoScreen();

            if (FinishLogoScreen())
            {
                currentScreen = GAME;
            }
            DrawRectangle(GetScreenWidth() - 200, GetScreenHeight() - 50, 200, 40, Fade(WHITE, 0.6f));
            DrawText("ALPHA VERSION", GetScreenWidth() - 180, GetScreenHeight() - 40, 20, DARKGRAY);
            break;
        }
        case GAME:
        {
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
            break;
        }
        default:
        {

            break;
        }
        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
