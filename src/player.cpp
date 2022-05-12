#include "player.h"
#include "keyboard.h"

void Player::MovePlayer(const int dx, const int dy)
{
    Move(dx, dy);
}

void Player::OnUpdate()
{
    if (Keyboard::IsDown(K_W))
        Move(0, -1);
    if (Keyboard::IsDown(K_A))
        Move(-1, 0);
    if (Keyboard::IsDown(K_S))
        Move(0, 1);
    if (Keyboard::IsDown(K_D))
        Move(1, 0);
    
    Update();
}

void Player::OnRender()
{
    Render();
}
