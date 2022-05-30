#ifndef ENGINE_IO_MOUSE_H
#define ENGINE_IO_MOUSE_H

#include <iostream>
#include <SDL2/SDL.h>

#include "engine/vec2.h"

enum MouseButton
{
    MOUSE_LEFT = 1,
    MOUSE_MIDDLE,
    MOUSE_RIGHT
};

enum MouseWheel
{
    WHEEL_UP = 1,
    WHEEL_DOWN
};

class Mouse
{
public:
    static Vector2 GetPos();
    static Vector2 GetWheel();

    static bool IsDown(MouseButton m_button);

private:
    static int _wheel_x, _wheel_y;
};

inline Vector2 Mouse::GetPos()
{
    static int x, y;
    SDL_GetMouseState(&x, &y);
    return Vector2(x, y);
}

inline Vector2 Mouse::GetWheel()
{
    return Vector2(_wheel_x, _wheel_y);
}

inline bool Mouse::IsDown(MouseButton m_button)
{
    Uint8 state = SDL_GetMouseState(nullptr, nullptr);
    return (state & SDL_BUTTON(static_cast<int> (m_button)));
}

#endif // ENGINE_IO_MOUSE_H
