#include "map.h"
#include "texture_manager.h"

// Debug
int test_map[20][25] = { 

	{ 0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,2,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,2,2,2,2,2,1,1,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,2,2,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
    // Load in terrain textures
    tex_dirt = TextureManager::LoadTexture("assets/dirt.png");
    tex_grass = TextureManager::LoadTexture("assets/grass.png");
    tex_water = TextureManager::LoadTexture("assets/water.png");

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

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 25; col++)
        {
            map[row][col] = arr[row][col];
        }
    }
}

void Map::DrawMap()
{
    int terrain_type = 0;
    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col < 25; col++)
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

void Map::CaretsanToIsometric() { };

void Map::IsometricToCartesan() { };