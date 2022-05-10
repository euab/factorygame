#pragma once

#ifndef MAP_H
#define MAP_H

#include "game.h"

class Map
{
    public:
        Map();
        ~Map();

        void LoadMap(int arr[20][25]);
        void DrawMap();

    private:
        SDL_Rect src_rect, dst_rect;
        SDL_Texture* tex_dirt;
        SDL_Texture* tex_grass;
        SDL_Texture* tex_water;

        // For baseline purposes the array will be stored in a 2D array.
        int map[20][25];
};

#endif // MAP_H
