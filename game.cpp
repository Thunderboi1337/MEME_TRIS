#include "game.h"
#include <random>
#include "block.h"

Game::Game()
{
    grid = Grid();
    blocks = get_all_blocks();
    current_block = get_random_block();
    next_block = get_random_block();
}

Block Game::get_random_block()
{

    if (blocks.empty())
    {
        blocks = get_all_blocks();
    }
    int random_index = rand() % blocks.size();
    Block block = blocks[random_index];
    blocks.erase(blocks.begin() + random_index);

    return block;
}

std::vector<Block> Game::get_all_blocks()
{
    return {IBlock(), TBlock(), JBlock(), OBlock(), SBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    current_block.Draw();
}
