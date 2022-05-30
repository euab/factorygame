#ifndef FACTORYGAME_GAME_H
#define FACTORYGAME_GAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "engine/engine.h"

#define FPS 60

class Engine;

class Game
{
public:
    Game(const char *title, int x, int y, int width, int height,
         bool fullscreen, bool resizable);
    ~Game();

    int init();
    int run();
    Engine* getEngineInstance();

private:
    bool m_running;
    Engine m_engine;

    const char* m_title;
    int m_x, m_y, m_w, m_h;
    bool m_fullscreen, m_resizable;
};

#endif // FACTORYGAME_GAME_H
