#include "engine/engine.h"
#include "engine/legacy/texturemanager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Deprecated.
SDL_Texture* TextureManager::LoadTexture(SDL_Renderer *renderer, const char* texture)
{
    SDL_Surface* tmp_surf = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmp_surf);
    SDL_FreeSurface(tmp_surf);

    return tex;
}

void TextureManager::Draw(SDL_Renderer *renderer, SDL_Texture* tex, SDL_Rect src_rect,
                          SDL_Rect dst_rect)
{
    SDL_RenderCopy(renderer, tex, &src_rect, &dst_rect);
}
