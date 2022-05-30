#include "factorygame/game.h"

#include "engine/engine.h"
#include "factorygame/testscene.h"
#include "factorygame/map.h"

#include <iostream>

Game::Game(const char *title, int x, int y, int width, int height,
           bool fullscreen, bool resizable) : 
               m_engine(title, x, y, width, height, fullscreen, resizable),
               m_title(title),
               m_x(x),
               m_y(y),
               m_w(width),
               m_h(height),
               m_fullscreen(fullscreen),
               m_resizable(resizable)
{ }

Game::~Game() { }

int Game::init()
{
    m_engine.init();
    int code = run();
    return code;    
}

// NOTE: I intend to implement the engine as a singleton but
// this shift in architecture is massive and has resulted in a near
// rewrite of the engine initialisation code. We sort of have a
// half-singleton engine class right now, we haven't placed any
// explicit controls over the engine instance but we are controlling
// it implicitly.
// TODO: Implement engine class as singleton so engine can be
// instantiated and accessed using Engine::getInstance()
Engine* Game::getEngineInstance()
{
    return &m_engine;
}

int Game::run()
{
    auto testScene = std::make_shared<TestScene>();

    // ISSUE: Map will never be rendered despite the fact everything initialises
    // correctly. This happens because map has been moved from the engine to
    // the game. To solve this we need to add the ability to queue and dequeue
    // tasks to the game loop.
    Map map = Map(m_engine);

    int code = getEngineInstance()->loop().run();

    return code;
}
