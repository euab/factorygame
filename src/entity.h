#ifndef ENTITY_H
#define ENTITY_H

#include "game.h"

class Entity
{
    public:
        Entity(const char* texsheet);
        ~Entity();

        void Update();
        void Render();

    private:
        int x;
        int y;

        SDL_Texture* obj_tex;
        SDL_Rect src_rect, dst_rect;
};

#endif // ENTITY_H
