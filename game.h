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
    void handle_input();
    void move_block_left();
    void move_block_right();
    void move_block_down();
    bool game_over;

private:
    bool is_block_outside();
    void rotate_block();
    void lock_block();
    bool block_fits();
    void reset();
    std::vector<Block> blocks;
    Block current_block;
    Block next_block;
};

#endif