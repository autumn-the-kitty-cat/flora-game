#ifndef SPRITE
#define SPRITE

#include <raylib.h>
#include <string>

class Sprite {
public:
    std::string name;
    Texture texture;
    void load(std::string imagePath)
    {
        name = imagePath;

        texture = LoadTexture(name.c_str());

        texture.height = 128;
        texture.width = 128;
    }
};

class Grass : Sprite {
    Vector2 position;
    void draw()
    {
        DrawTextureV(texture, position, WHITE);
    }
};

#endif
