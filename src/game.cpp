#ifndef GAME
#define GAME

#include "level.cpp"
#include "player.cpp"
#include "terrain.cpp"

#include <raylib.h>

class GameState {
    Level level;
};

class Game {
private:
    GameState state;
    Player player;
    Terrain terrain;
    void loop()
    {
        ClearBackground(BLACK);
        player.draw();
        player.move();
        player.fall();
    };

    void configureRaylib()
    {
        SetConfigFlags(FLAG_VSYNC_HINT);
        SetExitKey(KEY_NULL);
        ToggleFullscreen();
    }

public:
    void start(std::string title)
    {
        InitWindow(0, 0, title.c_str());
        configureRaylib();

        player.sprite.load("resources/player.png");

        while (!WindowShouldClose()) {
            BeginDrawing();
            loop();
            EndDrawing();
        }
        CloseWindow();
    }
};
#endif
