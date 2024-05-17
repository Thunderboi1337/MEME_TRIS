#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    Grid grid;
    void Draw();
    void handle_input();
    bool game_over;
    int score;
    void move_block_down();

private:
    bool is_block_outside();
    void rotate_block();
    void lock_block();
    bool block_fits();
    void reset();
    void update_score(int lines_cleared, int move_down_point);
    void move_block_left();
    void move_block_right();
    std::vector<Block> blocks;
    Block get_random_block();
    std::vector<Block> get_all_blocks();
    Block current_block;
    Block next_block;
};

#endif