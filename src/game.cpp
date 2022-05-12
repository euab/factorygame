#include "game.h"
#include "texture_manager.h"
#include "game_object.h"
#include "map.h"
#include "file.h"
#include "keyboard.h"
#include "mouse.h"
#include "player.h"

Player* test_player;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game::~Game() {}

void Game::Init(const char* title, int x, int y, int width, int height,
                bool fullscreen)
{
    int flags = 0;

    // If the we have chosen to launch into fullscreen set flags to
    // enable fullscreen.
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    // Initialse all SDL subsystems and branch if successful.
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL subsystems initialised." << std::endl;
        // Create the SDL window, log if we did it successfully.
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window)
            std::cout << "We made a window" << std::endl;
        
        // Create a renderer using the first availible driver.
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "We made a renderer" << std::endl;
            // Set the renderer draw colour to white.
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        is_running = true;

    } else {
        // Set is_running to false so we can break out of the game loop.
        is_running = false;
    }

    test_player = new Player("block.png", 0, 0);

    map = new Map();

    ticks = 0;
}

void Game::HandleEvents()
{
    SDL_Event event;
    // Remove the next event from the event queue.
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            // The user has exited.
            is_running = false;
            break;

        case SDL_KEYDOWN:
            if (Keyboard::IsDown(K_W))
                std::cout << "W key pressed." << std::endl;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (Mouse::IsDown(MOUSE_LEFT))
                std::cout << "Left click detected" << std::endl;
            break;

        default:
            break;
    }
}

void Game::Update()
{
    test_player->OnUpdate();
}

void Game::Render()
{
    // Clear the current frame
    SDL_RenderClear(renderer);
    // Draw the map
    map->DrawMap();
    // Draw the test texture
    test_player->OnRender();
    // Push the next frame
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    // Clean up the running process. Best practise is to work in the
    // inverse order of what objects were created.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Print notification 
    std::cout << "Process cleaned" << std::endl;
}

bool Game::Running()
{
    return Game::is_running;
}
