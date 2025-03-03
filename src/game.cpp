#ifndef GAME
#define GAME

#include "level.cpp"
#include "player.cpp"

#include <raylib.h>

class GameState {
    Level level;
};

class Game {
private:
    GameState state;
    Player player;
    void loop()
    {
        player.draw();
    };

public:
    void start(std::string title)
    {
        InitWindow(0, 0, title.c_str());
        SetExitKey(KEY_NULL);
        ToggleFullscreen();
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
