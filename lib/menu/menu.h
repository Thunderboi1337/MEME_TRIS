#ifndef MENU_H
#define MENU_H

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>

class Menu
{
public:
    Menu();
    void Draw(void);

private:
    bool showMessageBox;
};

#endif
