#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game.h"

class GameObject
{
    public:
        GameObject(const char* texsheet, int pos_x, int pos_y);
        ~GameObject();

        void Update();
        void Render();

    private:
        int x;
        int y;

        SDL_Texture* obj_tex;
        SDL_Rect src_rect, dst_rect;
};

#endif // GAME_OBJECT_H