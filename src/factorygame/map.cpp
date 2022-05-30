#include "engine/engine.h"
#include "factorygame/map.h"
#include "engine/assets.h"
#include "engine/generation/perlin.h"
#include "engine/legacy/texturemanager.h"
#include <iostream>

Map::Map(Engine &engine) : m_engine(engine)
{
    // Load in terrain textures
    tex_dirt = m_engine.assets().GetTexture("dirt.png");
    tex_grass = m_engine.assets().GetTexture("grass.png");
    tex_water = m_engine.assets().GetTexture("water.png");

    GenerateMap();

    src_rect.x = src_rect.y = 0;
    src_rect.w = dst_rect.w = 32;
    src_rect.h = dst_rect.h = 32;
    dst_rect.x = dst_rect.y = 0;

    DrawMap();
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
                case TERRAIN_TYPE_WATER:
                    TextureManager::Draw(m_engine.renderer(), tex_water, src_rect, dst_rect);
                    break;
                
                case TERRAIN_TYPE_DIRT:
                    TextureManager::Draw(m_engine.renderer(), tex_dirt, src_rect, dst_rect);
                    break;
                
                case TERRAIN_TYPE_GRASS:
                    TextureManager::Draw(m_engine.renderer(), tex_grass, src_rect, dst_rect);
                
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

void Map::Generate(std::vector<std::vector<TerrainType> > &genmap)
{
    // No seed has been specified, generate a map using the default seed.
    const unsigned int seed = 42;

    Generate(genmap, seed);
}

void Map::Generate(std::vector<std::vector<TerrainType> > &genmap,
                   const unsigned int &seed)
{
    // Resize the map vector to avoid our beloved, the segfault.
    genmap.resize(MAP_SIZE_Y, std::vector<TerrainType>(MAP_SIZE_X));

    Perlin pn(seed);

    // Iterate through the empty map vector, inserting perlin values.
    for (int i = 0; i < MAP_SIZE_Y; i++) {
        for (int j = 0; j < MAP_SIZE_X; j++) {
            double x = (double) j / ((double) MAP_SIZE_X);
            double y = (double) i / ((double) MAP_SIZE_Y);

            double n = pn.Noise(x * 10.0f, y * 10.0f, 0.8f);

            if (n < 0.35f)
                genmap[i][j] = TERRAIN_TYPE_WATER;

            else if (n >= 0.35f && n < 0.6f)
                genmap[i][j] = TERRAIN_TYPE_GRASS;

            else
                genmap[i][j] = TERRAIN_TYPE_DIRT;
        }
    }
}
