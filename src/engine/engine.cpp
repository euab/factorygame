#include "engine/engine.h"
#include "engine/init.h"
#include "engine/assets.h"

#include <iostream>

Engine::Engine(const char* title, int x, int y, int w, int h, bool fullscreen,
               bool resizable) :
               m_windowTitle     (title),
               m_windowX         (x),
               m_windowY         (y),
               m_windowW         (w),
               m_windowH         (h),
               m_windowFullscreen(fullscreen),
               m_windowResizable (resizable),
               m_initialiser     (std::make_shared<Initialiser>()),
               m_loop            (60, *this),
               m_assets          (*this)

{
    // We have a name for our engine now :)
    std::cout << "Starting Ryu engine" << std::endl;

    m_initialiser->initSDL();
    m_initialiser->initWindow(m_windowTitle, m_windowX, m_windowY, m_windowW,
        m_windowH, m_windowFullscreen, m_windowResizable);
}

Engine::~Engine() { }

void Engine::init() { }

SceneManager &Engine::scenes()
{
    return m_sceneManager;
}

Scenegraph &Engine::scenegraphs()
{
    return m_scenegraphs;
}

Assets &Engine::assets()
{
    return m_assets;
}

TextureManager &Engine::textureManager()
{
    return m_textureManager;
}

GameLoop &Engine::loop()
{
    return m_loop;
}

SDL_Renderer *Engine::renderer()
{
    return m_initialiser->getRenderer();
}

SDL_Window *Engine::window()
{
    return m_initialiser->getWindow();
}
