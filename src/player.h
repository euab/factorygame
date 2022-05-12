#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

class Player : public GameObject
{
public:
    Player(const char* texsheet, int pos_x, int pos_y) : GameObject(texsheet, pos_x, pos_y) { };
    ~Player();

    void OnUpdate();
    void OnRender();

private:
    void MovePlayer(const int dx, const int dy);
};

#endif // PLAYER_H
