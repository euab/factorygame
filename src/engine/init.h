#ifndef ENGINE_INIT_H
#define ENGINE_INIT_H

#include "SDL2/SDL.h"

class Initialiser
{
public:
    void initSDL();
    void shutdownSDL();

    void initWindow(const char *title, int x, int y, int w, int h,
                    bool fullscreen, bool resizable);
    void destroyWindow();
    void destroyRenderer();

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
};

#endif // ENGINE_INIT_H
