#include "map.h"
#include "texture_manager.h"
#include "assets.h"
#include "perlin.h"
#include <iostream>

Map::Map()
{
    // Load in terrain textures
    tex_dirt = Assets::GetTexture("dirt.png");
    tex_grass = Assets::GetTexture("grass.png");
    tex_water = Assets::GetTexture("water.png");

    GenerateMap();

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

void Map::DrawMap()
{
    int terrain_type = 0;
    for (int row = 0; row < MAP_SIZE_Y; row++)
    {
        for (int col = 0; col < MAP_SIZE_X; col++)
        {
            terrain_type = m_map[row][col];

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
    unsigned int seed;
    std::cout << "Enter a seed: ";
    std::cin >> seed;
    std::cout << std::endl;

    Generate(m_map, seed);
}

void Map::Generate(std::vector<std::vector<int> > &genmap)
{
    // No seed has been specified, generate a map using the default seed.
    const unsigned int seed = 42;

    Generate(genmap, seed);
}

void Map::Generate(std::vector<std::vector<int> > &genmap,
                   const unsigned int &seed)
{
    // Resize the map vector to avoid our beloved, the segfault.
    genmap.resize(MAP_SIZE_Y, std::vector<int>(MAP_SIZE_X));

    Perlin pn(seed);

    // Iterate through the empty map vector, inserting perlin values.
    for (int i = 0; i < MAP_SIZE_Y; i++) {
        for (int j = 0; j < MAP_SIZE_X; j++) {
            double x = (double) j / ((double) MAP_SIZE_X);
            double y = (double) i / ((double) MAP_SIZE_Y);

            double n = pn.Noise(x * 10.0f, y * 10.0f, 0.8f);

            std::cout << n << ", ";

            if (n < 0.35f)
                genmap[i][j] = 0;

            else if (n >= 0.35f && n < 0.6f)
                genmap[i][j] = 2;

            else
                genmap[i][j] = 1;
        }
    }

    std::cout << std::endl;
}
