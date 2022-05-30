#include "engine/io/keyboard.h"

const Uint8 *(Keyboard::keyboardState) = SDL_GetKeyboardState(nullptr);

bool Keyboard::IsDown(Scancode key)
{
  return keyboardState[key];
}
