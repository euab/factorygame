#include "game.h"

// Set to nullptr for now for testing purposes.
Game *game = nullptr;

int main(int argc, const char* argv[])
{
    game = new Game();

    // Call to initialise SDL
    game->Init("Factoryscape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               800, 600, true);

    // Begin the game loop
    while (game->Running())
    {
        Uint32 starting_tick = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        // Check if we are iterating through frames too quickly. If we are,
        // delay the game loop so it is back in sync.
        if ( ( 1000 / FPS) > SDL_GetTicks() - starting_tick)
        {
            SDL_Delay( ( 1000 / FPS) - ( SDL_GetTicks() - starting_tick));
        }
    }

    // It is time for the game to shut down.
    game->Clean();

    return 0;
}
