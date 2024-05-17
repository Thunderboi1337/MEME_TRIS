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

    void handle_input();

    void move_block_left();

    void move_block_right();

    void move_block_down();

    void Draw();

private:
    bool is_block_outside();
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
};

#endif