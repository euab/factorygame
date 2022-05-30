#ifndef FACTORYGAME_PLAYER_H
#define FACTORYGAME_PLAYER_H

#include "engine/gameobject.h"
#include "engine/engine.h"

class Player : public GameObject
{
public:
    Player(Engine &engine, const char* texsheet, int pos_x, int pos_y) : 
        GameObject(engine, texsheet, pos_x, pos_y) { };
    ~Player();

    void OnUpdate();
    void OnRender();

private:
    void MovePlayer(const int dx, const int dy);
};

#endif // PLAYER_H
