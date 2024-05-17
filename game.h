#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    Grid grid;
    Block get_random_block();

    std::vector<Block> get_all_blocks();

    void Draw();

private:
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
};

#endif