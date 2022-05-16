#pragma once

#ifndef MAP_H
#define MAP_H

#include "game.h"
#include "defs.h"

#define MAP_SIZE_X DEFAULT_RESOLUTION_X / 32
#define MAP_SIZE_Y DEFAULT_RESOLUTION_Y / 32

class Map
{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[MAP_SIZE_Y][MAP_SIZE_X]);
        void DrawMap();
        void GenerateMap();

    private:
        SDL_Rect src_rect, dst_rect;
        SDL_Texture* tex_dirt;
        SDL_Texture* tex_grass;
        SDL_Texture* tex_water;

        // For baseline purposes the array will be stored in a 2D array.
        int map[MAP_SIZE_Y][MAP_SIZE_X];
};

#endif // MAP_H
