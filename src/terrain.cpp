#ifndef TERRAIN
#define TERRAIN

#include <optional>
#define WIDTH 20
#define HEIGHT 12

#include "sprite.cpp"
#include <raylib.h>

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
    std::optional<Block> raw[WIDTH][HEIGHT];

public:
    void init()
    {
        Sprite grassSprite;
        grassSprite.load("resources/grass.png");
        Block grass = Block {
            .type = {
                .sprite = grassSprite,
                .isFatal = false,
            },
        };

        for (unsigned int i = 0; i < WIDTH; i++) {
            raw[i][10] = std::make_optional(grass);
        }
    }
    void draw()
    {
        int blockWidth = GetScreenWidth() / WIDTH;
        for (unsigned int i = 0; i < WIDTH; i++) {
            for (unsigned int j = 0; j < HEIGHT; j++) {
                std::optional<Block> block = raw[i][j];
                if (block.has_value()) {
                    Texture blockTexture = block.value().type.sprite.texture;

                    DrawTexture(blockTexture, blockWidth * i, blockWidth * j, WHITE);
                }
            }
        }
    }
};

#endif
