#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "engine/scene/scenemanager.h"
#include "engine/scene/scenegraph.h"
#include "engine/assets.h"
#include "engine/legacy/texturemanager.h"
#include "engine/loop.h"
#include "engine/init.h"

#include <SDL2/SDL.h>
#include <memory>

class Engine
{
public:
    Engine(const char* title, int x, int y, int w, int h, bool fullscreen,
           bool resizable);
    ~Engine();

    void init();

    SceneManager &scenes();
    Scenegraph &scenegraphs();
    Assets &assets();
    TextureManager &textureManager();
    GameLoop &loop();

    SDL_Window* window();
    SDL_Renderer* renderer();

private:
    std::shared_ptr<Initialiser> m_initialiser;
    SceneManager m_sceneManager;
    Scenegraph m_scenegraphs;
    Assets m_assets;
    TextureManager m_textureManager;
    GameLoop m_loop;

    const char* m_windowTitle;
    int m_windowX;
    int m_windowY;
    int m_windowW;
    int m_windowH;
    int m_windowFullscreen;
    int m_windowResizable;
};

#endif // ENGINE_ENGINE_H
