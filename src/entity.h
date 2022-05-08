#ifndef ENTITY_H
#define ENTITY_H

#include "game.h"

class Entity
{
    public:
        Entity(const char* texsheet, SDL_Renderer* renderer);
        ~Entity();

        void Update();
        void Render();

    private:
        int x;
        int y;

        SDL_Texture* obj_tex;
        SDL_Rect src_rect, dst_rect;
        SDL_Renderer* m_renderer;
};

#endif // ENTITY_H
