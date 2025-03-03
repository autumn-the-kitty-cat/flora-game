#ifndef PLAYER
#define PLAYER

#include <raylib.h>
#include <string>

class PlayerState { };

class Sprite {
public:
    std::string name;
    Texture texture;
    Vector2 position;
    void load(std::string imagePath)
    {
        name = imagePath;

        texture = LoadTexture(name.c_str());

        texture.height = 128;
        texture.width = 128;
    }
};

class Player {
private:
    PlayerState state;

public:
    Sprite sprite;
    Vector2 position;
    void draw()
    {
        DrawTexture(sprite.texture, position.x, position.y, WHITE);
    }
};
#endif
