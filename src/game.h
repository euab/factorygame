#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define FPS 60

class Game
{
    public:
        Game();
        ~Game();

        void Init(const char* title, int x, int y, int width, int height,
                  bool fullscreen);
        
        void HandleEvents();
        void Update();
        void Render();
        void Clean();

        bool Running();

    private:
        bool is_running;
        SDL_Window* window;
        SDL_Renderer* renderer;
        int ticks;
};

#endif
