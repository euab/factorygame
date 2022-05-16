#include "game_object.h"
#include "assets.h"

GameObject::GameObject() { }

GameObject::GameObject(const char* texsheet, int pos_x, int pos_y)
{
    // We are making a new game entity
    obj_tex = Assets::GetTexture(texsheet);
    pos = Vector2(pos_x, pos_y);
}

void GameObject::Update() 
{
    src_rect.h = 8;
    src_rect.w = 8;
    src_rect.x = 0;
    src_rect.y = 0;

    dst_rect.x = static_cast<int>(pos.x);
    dst_rect.y = static_cast<int>(pos.y);
    dst_rect.h = src_rect.h * 2;
    dst_rect.w = src_rect.w * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, obj_tex, &src_rect, &dst_rect);
}

void GameObject::Move(const Vector2 &delta)
{
    pos += delta;
}

void GameObject::OnRender() { }

void GameObject::OnUpdate() { }
