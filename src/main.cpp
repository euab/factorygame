#include "game.h"

// Set to nullptr for now for testing purposes.
Game *game = nullptr;

int main(int argc, const char* argv[])
{
    game = new Game();

    // Call to initialise SDL
    game->Init("Factoryscape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               800, 600, false);

    // Begin the game loop
    while (game->Running())
    {
        game->HandleEvents();
        game->Update();
        game->Render();
    }

    // It is time for the game to shut down.
    game->Clean();

    return 0;
}
