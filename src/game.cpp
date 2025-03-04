#ifndef GAME
#define GAME

#include "level.cpp"
#include "player.cpp"
#include "terrain.cpp"

#include <raylib.h>

#define SKY_COLOUR BLUE

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
        ClearBackground(SKY_COLOUR);
        player.draw();
        player.move();
        player.fall();
        terrain.draw();
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
        terrain.init();

        while (!WindowShouldClose()) {
            BeginDrawing();
            loop();
            EndDrawing();
        }
        CloseWindow();
    }
};
#endif
