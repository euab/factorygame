#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* tmp_surf = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmp_surf);
    SDL_FreeSurface(tmp_surf);

    return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src_rect, SDL_Rect dst_rect)
{
    SDL_RenderCopy(Game::renderer, tex, &src_rect, &dst_rect);
}
