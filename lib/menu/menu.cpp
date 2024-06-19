#include "menu.h"
#define RAYGUI_IMPLEMENTATION

#include <raygui.h>
#include <raylib.h>

Menu::Menu()
{
    showMessageBox = false;
}

void Menu::Draw()
{

    if (GuiButton((Rectangle){24, 24, 120, 30}, "Show Message"))
        showMessageBox = true;

    if (showMessageBox)
    {
        int result = GuiMessageBox((Rectangle){85, 70, 250, 100},
                                   "Message Box", "Hi! This is a message!", "Nice;Cool");

        if (result >= 0)
            showMessageBox = false;
    }
}
