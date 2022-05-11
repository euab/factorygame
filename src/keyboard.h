#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

enum Scancode
{
    K_UKNOWN = 0,

    K_W = 26
};

class Keyboard
{
public:
    static bool IsDown(Scancode key);

private:
    static const Uint8 *keyboardState;
};

#endif
