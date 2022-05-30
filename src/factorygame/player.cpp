#include "factorygame/player.h"
#include "engine/io/keyboard.h"
#include "engine/vec2.h"

void Player::OnUpdate()
{
    if (Keyboard::IsDown(K_W))
        Move(Vector2::V_UP);
    if (Keyboard::IsDown(K_A))
        Move(Vector2::V_LEFT);
    if (Keyboard::IsDown(K_S))
        Move(Vector2::V_DOWN);
    if (Keyboard::IsDown(K_D))
        Move(Vector2::V_RIGHT);
    
    Update();
}

void Player::OnRender()
{
    Render();
}
