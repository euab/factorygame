#include <iostream>
#include <SDL2/SDL.h>

#include "factorygame/game.h"
#include "engine/engine.h"
#include "engine/defs.h"

// Entry point for factorygame.
int main(int argc, char* argv[])
{
    std::cout << "Hello there :)" << std::endl;
    int code = 0;

    Game game = Game("Factorygame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     DEFAULT_RESOLUTION_X, DEFAULT_RESOLUTION_Y, false, false);

    code = game.init();

    std::cout << "Bye :(" << std::endl;
    return code;
}
