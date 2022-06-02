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

    tex_test_ore = m_engine.assets().GetTexture("ore.png");

    GenerateMap();

    src_rect.x = src_rect.y = 0;
    src_rect.w = dst_rect.w = 32;
    src_rect.h = dst_rect.h = 32;
    dst_rect.x = dst_rect.y = 0;

    srcRectOre.w = dstRectOre.w = 32;
    srcRectOre.h = dstRectOre.h = 32;
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
    int oreT = 0;

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

    for (int row = 0; row < MAP_SIZE_Y; row++) {
        for (int col = 0; col < MAP_SIZE_X; col++) {
            oreT = m_mapOre[row][col];

            dstRectOre.x = col * 32;
            dstRectOre.y = row * 32;

            switch(oreT)
            {
                case ORE_TYPE_IRON:
                    TextureManager::Draw(m_engine.renderer(), tex_test_ore, srcRectOre, dstRectOre);
                    break;
                
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
    generateOre(m_mapOre, seed);
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

// make perlin map for ore
// load tile map
// check if tile is not water if so apply ore if perlin greater than 0.9.
void Map::generateOre(std::vector<std::vector<OreType>> &genOreMap,
                      const unsigned int &seed)
{
    genOreMap.resize(MAP_SIZE_Y, std::vector<OreType>(MAP_SIZE_X));
    Perlin pn(seed);

    for (int i = 0; i < MAP_SIZE_Y; i++) {
        for (int j = 0; j < MAP_SIZE_X; j++) {
            TerrainType terrT = m_map[i][j];

            // We don't want ore in water (that would just be mean).
            if (terrT == TERRAIN_TYPE_WATER) {
                genOreMap[i][j] = ORE_TYPE_NONE;
                continue;
            }
            
            double x = (double) i / ((double) MAP_SIZE_X);
            double y = (double) j / ((double) MAP_SIZE_Y);

            double n = pn.Noise(x * 10.0f, y * 10.0f, 0.8f);

            if (n >= 0.35f && n < 0.37f) {
                genOreMap[i][j] = ORE_TYPE_IRON;
            }
            
            else
                genOreMap[i][j] = ORE_TYPE_NONE;
        }
    }
}
