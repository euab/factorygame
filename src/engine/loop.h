#ifndef ENGINE_LOOP_H
#define ENGINE_LOOP_H

#include "engine/engine.h"

class Engine;

class GameLoop
{
public:
    GameLoop(int fps, Engine &engine);
    ~GameLoop();

    int run();
    void quit();

    void handleEvents();
    void update();
    void draw();

    bool isRunning();

private:
    bool m_running;
    int m_fps;
    Engine &m_engine;
};

#endif // ENGINE_LOOP_H
