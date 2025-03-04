#ifndef PLAYER
#define PLAYER

#include "sprite.cpp"
#include <cmath>
#include <raylib.h>

#define PLAYER_SPEED 600.0
#define FALL_SPEED 1200.0

class PlayerState { };

class Player {
private:
    PlayerState state;

public:
    Sprite sprite;
    Vector2 position;
    void draw()
    {
        DrawTextureV(sprite.texture, position, WHITE);
    }

    void move()
    {
        int targetFps = GetFPS();

        int movementX = 0.0;

        if (IsKeyDown(KEY_D)) {
            movementX += PLAYER_SPEED * GetFrameTime();
        }

        if (IsKeyDown(KEY_A)) {
            movementX -= PLAYER_SPEED * GetFrameTime();
        }

        position.x += movementX;
    }

    void fall()
    {
        position.y += FALL_SPEED * GetFrameTime();
    }
};

#endif
