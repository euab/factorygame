#include "map.h"
#include "texture_manager.h"
#include "assets.h"

// Debug
int test_map[MAP_SIZE_Y][MAP_SIZE_X];

Map::Map()
{
    // Load in terrain textures
    tex_dirt = Assets::GetTexture("dirt.png");
    tex_grass = Assets::GetTexture("grass.png");
    tex_water = Assets::GetTexture("water.png");

    GenerateMap();
    LoadMap(test_map);

    src_rect.x = src_rect.y = 0;
    src_rect.w = dst_rect.w = 32;
    src_rect.h = dst_rect.h = 32;
    dst_rect.x = dst_rect.y = 0;
}

Map::~Map()
{
    SDL_DestroyTexture(tex_water);
    SDL_DestroyTexture(tex_grass);
    SDL_DestroyTexture(tex_dirt);
}

void Map::LoadMap(int arr[MAP_SIZE_Y][MAP_SIZE_X])
{
    for (int row = 0; row < MAP_SIZE_Y; row++)
    {
        for (int col = 0; col < MAP_SIZE_X; col++)
        {
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap()
{
    int terrain_type = 0;
    for (int row = 0; row < MAP_SIZE_Y; row++)
    {
        for (int col = 0; col < MAP_SIZE_X; col++)
        {
            terrain_type = map[row][col];

            dst_rect.x = col * 32;
            dst_rect.y = row * 32;

            switch (terrain_type)
            {
                case 0:
                    TextureManager::Draw(tex_water, src_rect, dst_rect);
                    break;
                
                case 1:
                    TextureManager::Draw(tex_dirt, src_rect, dst_rect);
                    break;
                
                case 2:
                    TextureManager::Draw(tex_grass, src_rect, dst_rect);
                
                default:
                    break;
            }
        }
    }
}

void Map::GenerateMap()
{
    int terrain_type;
    for (int row=0; row<MAP_SIZE_Y; row++) {
        for (int col=0; col<MAP_SIZE_X; col++) {
            terrain_type = std::rand() % 3;
            test_map[row][col] = terrain_type;
        }
    }
}
