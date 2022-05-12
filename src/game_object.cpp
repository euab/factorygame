#include "game_object.h"
#include "assets.h"

GameObject::GameObject() { }

GameObject::GameObject(const char* texsheet, int pos_x, int pos_y)
{
    // We are making a new game entity
    obj_tex = Assets::GetTexture(texsheet);

    x = pos_x;
    y = pos_y;
}

void GameObject::Update() 
{
    src_rect.h = 8;
    src_rect.w = 8;
    src_rect.x = 0;
    src_rect.y = 0;

    dst_rect.x = x;
    dst_rect.y = y;
    dst_rect.h = src_rect.h * 2;
    dst_rect.w = src_rect.w * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, &src_rect, &dst_rect);
}

void GameObject::Move(int dx, int dy)
{
    x += dx;
    y += dy;
}

void GameObject::OnRender() { }

void GameObject::OnUpdate() { }
