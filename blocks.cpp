#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
    }

private:
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 1;
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 1)};
    }

private:
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 1;
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
    }

private:
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 1;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[2] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        cells[3] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    }

private:
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 1;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
        cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
    }

private:
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 1;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
    }

private:
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 1;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
    }

private:
};