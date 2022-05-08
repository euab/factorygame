#include "entity.h"
#include "texture_manager.h"

Entity::Entity(const char* texsheet)
{
    // We are making a new game entity
    obj_tex = TextureManager::LoadTexture(texsheet);
}

void Entity::Update() 
{
    x = 0;
    y = 0;

    src_rect.h = 32;
    src_rect.w = 32;
    src_rect.x = 0;
    src_rect.y = 0;

    dst_rect.x = x;
    dst_rect.y = y;
    dst_rect.h = src_rect.h * 2;
    dst_rect.w = src_rect.w * 2;
}

void Entity::Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, &src_rect, &dst_rect);
}
