// TODO: Inject defines at compile-time for arch based compilation
#ifndef ARCH_WINDOWS
#define SDL_MAIN_HANDLED
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "engine/init.h"

// NOTE: crap x
//
// Initialise all of the SDL subsystems and return a structure of pointers to
// the subsystems.
void Initialiser::initSDL()
{
    // Notify SDL that the main function is being handled for windows instances
    SDL_SetMainReady();

    // Initialise SDL base
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        // Is exiting directly a good idea? Do I care...
        // yes I actually do but for now oh well.
        exit(0);
}

void Initialiser::shutdownSDL()
{
    SDL_Quit();
}

void Initialiser::initWindow(const char* title, int x, int y, int w, int h,
                             bool fullscreen, bool resizable)
{
    unsigned int windowFlags = 0;

    if (fullscreen) windowFlags |= SDL_WINDOW_FULLSCREEN;
    if (resizable) windowFlags |= SDL_WINDOW_RESIZABLE;

    m_window = SDL_CreateWindow(title, x, y, w, h, windowFlags);
    if (!m_window) {
        std::cerr << "Failed to create window" << std::endl
            << SDL_GetError() << std::endl;
        exit(1);
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if (!m_renderer) {
        std::cerr << "Failed to create renderer" << std::endl
            << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Initialiser::destroyWindow()
{
    if (m_window != nullptr) SDL_DestroyWindow(m_window);
}

void Initialiser::destroyRenderer()
{
    if (m_renderer != nullptr) SDL_DestroyRenderer(m_renderer);
}

SDL_Window *Initialiser::getWindow() const
{
    return m_window;
}

SDL_Renderer *Initialiser::getRenderer() const
{
    return m_renderer;
}
