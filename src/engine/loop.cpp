#include "engine/engine.h"
#include "engine/loop.h"

#include <SDL2/SDL.h>
#include <iostream>

GameLoop::GameLoop(int fps, Engine &engine) : m_fps(fps), m_running(false),
                   m_engine(engine) { }

GameLoop::~GameLoop() { }

int GameLoop::run()
{
    m_running = true;

    while (m_running) {
        unsigned int startingTick = SDL_GetTicks();

        handleEvents();
        update();
        draw();

        // Check if we are iterating through frames too quickly. If we are,
        // delay the game loop so we get back in sync.
        if ( ( 1000 / m_fps) > SDL_GetTicks() - startingTick )
            SDL_Delay( ( 1000 / m_fps ) - ( SDL_GetTicks() - startingTick ) );
    }

    quit();

    return 0;
}

void GameLoop::quit()
{
    m_running = false;
}

void GameLoop::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            // Exit signal. Stop the game loop.
            quit();
            break;
        
        default: break;
    }
}

void GameLoop::update()
{
    for (auto& uHandler : m_qUpdating)
        uHandler();
}

void GameLoop::draw()
{
    SDL_RenderClear(m_engine.renderer());

    // Call to each registered renderer handler
    for (auto& handler : m_qRendering)
        handler();

    SDL_RenderPresent(m_engine.renderer());
}

bool GameLoop::isRunning()
{
    return m_running;
}

// Push a render handler onto the back of the render queue.
void GameLoop::queueRendererHandle(RendererHandler handler)
{
    m_qRendering.push_back(std::move(handler));
}

// Push an update handler onto the back of the update queue.
void GameLoop::enqueueUpdateHandle(UpdateHandler handler)
{
    m_qUpdating.push_back(std::move(handler));
}
