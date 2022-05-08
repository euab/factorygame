#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* renderer)
{
    SDL_Surface* tmp_surf = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmp_surf);
    SDL_FreeSurface(tmp_surf);

    return tex;
}
