#pragma once

#ifndef FACTORYGAME_MAP_H
#define FACTORYGAME_MAP_H

#include "engine/defs.h"

#include <SDL2/SDL.h>
#include <vector>

#define MAP_SIZE_X DEFAULT_RESOLUTION_X / 32
#define MAP_SIZE_Y DEFAULT_RESOLUTION_Y / 32

enum TerrainType
{
    TERRAIN_TYPE_WATER,
    TERRAIN_TYPE_DIRT,
    TERRAIN_TYPE_GRASS,
};

class Map
{
    public:
        Map(Engine &m_engine);
        ~Map();

        void LoadMap(int arr[MAP_SIZE_Y][MAP_SIZE_X]);
        void DrawMap();
        void GenerateMap();

        void Generate(std::vector<std::vector<TerrainType> > &genmap);
        void Generate(std::vector<std::vector<TerrainType> > &genmap,
                      const unsigned int &seed);

    private:
        SDL_Rect src_rect, dst_rect;
        SDL_Texture* tex_dirt;
        SDL_Texture* tex_grass;
        SDL_Texture* tex_water;

        // For baseline purposes the array will be stored in a 2D array.
        std::vector<std::vector<TerrainType> > m_map;

        Engine &m_engine;
};

#endif // FACTORYGAME_MAP_H
