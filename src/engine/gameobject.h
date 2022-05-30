#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "engine/vec2.h"
#include "engine/engineforward.h"

#include <SDL2/SDL.h>

class GameObject
{
    public:
        GameObject(Engine &engine);
        GameObject(Engine &engine, const char* texsheet, int pos_x, int pos_y);
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

        Engine &m_engine;
};

#endif // GAME_OBJECT_H
