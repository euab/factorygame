#ifndef ENGINE_LEGACY_TEXTUREMANAGER_H
#define ENGINE_LEGACY_TEXTUREMANAGER_H

#include <SDL2/SDL.h>

class TextureManager
{
    public:
        static SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char* filename);
        static void Draw(SDL_Renderer *renderer, SDL_Texture* tex, SDL_Rect src_rect, SDL_Rect dst_rect);
};

#endif // ENGINE_LEGACY_TEXTUREMANAGER_H
