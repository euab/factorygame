#pragma once

#include "game.h"

class TextureManager
{
    public:
        static SDL_Texture* LoadTexture(const char* filename);
        static void Draw(SDL_Texture* tex, SDL_Rect src_rect, SDL_Rect dst_rect);
};
