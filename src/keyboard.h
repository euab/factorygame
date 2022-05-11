#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>

enum Scancode
{
    K_UKNOWN = 0,

    K_A = 4,
    K_B = 5,
    K_C = 6,
    K_D = 7,
    K_E = 8,
    K_F = 9,
    K_G = 10,
    K_H = 11,
    K_I = 12,
    K_J = 13,
    K_K = 14,
    K_L = 15,
    K_M = 16,
    K_N = 17,
    K_O = 18,
    K_P = 19,
    K_Q = 20,
    K_R = 21,
    K_S = 22,
    K_T = 23,
    K_U = 24,
    K_V = 25,
    K_W = 26,
    K_X = 27,
    K_Y = 28,
    K_Z = 29,

    K_1 = 30,
    K_2 = 31,
    K_3 = 32,
    K_4 = 33,
    K_5 = 34,
    K_6 = 35,
    K_7 = 36,
    K_8 = 37,
    K_9 = 38,
    K_0 = 39,
};

class Keyboard
{
public:
    static bool IsDown(Scancode key);

private:
    static const Uint8 *keyboardState;
};

#endif
