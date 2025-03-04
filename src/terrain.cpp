#ifndef TERRAIN
#define TERRAIN

#define WIDTH 20
#define HEIGHT 12

#include "sprite.cpp"

class BlockType {
public:
    Sprite sprite;
    bool isFatal;
};

class Block {
public:
    BlockType type;
};

class Terrain {
    Block raw[WIDTH][HEIGHT];

public:
    void draw()
    {
    }
};

#endif
