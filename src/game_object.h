#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game.h"
#include "vec2.h"

class GameObject
{
    public:
        GameObject();
        GameObject(const char* texsheet, int pos_x, int pos_y);
        ~GameObject();

        void Update();
        void Render();

        void Move(const Vector2 &delta);

        virtual void OnUpdate();
        virtual void OnRender();

    private:
        Vector2 pos;

        SDL_Texture* obj_tex;
        SDL_Rect src_rect, dst_rect;
};

#endif // GAME_OBJECT_H
