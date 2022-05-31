#ifndef ENGINE_LOOP_H
#define ENGINE_LOOP_H

#include <functional>

#include "engine/engine.h"

class Engine;

class GameLoop
{
    using RendererHandler = std::function<void(void)>;
    using UpdateHandler = std::function<void(void)>;

public:
    GameLoop(int fps, Engine &engine);
    ~GameLoop();

    int run();
    void quit();

    void handleEvents();
    void update();
    void draw();

    bool isRunning();

    void queueRendererHandle(RendererHandler handler);
    void dequeueHandlerHandle(RendererHandler handler);

    void enqueueUpdateHandle(UpdateHandler handler);
    void dequeueUpdateHandle(UpdateHandler handler);

private:
    bool m_running;
    int m_fps;
    Engine &m_engine;

    std::list<RendererHandler> m_qRendering;
    std::list<UpdateHandler> m_qUpdating;
};

#endif // ENGINE_LOOP_H
