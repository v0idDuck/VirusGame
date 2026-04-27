#pragma once
#include "Entity.h"
#include "Map.h"
#include <Windows.h>

class Player : public Entity {
private:
    DWORD lastMove;
    int moveDelay;
public:
    Player(int x, int y);

    void Move(int dx, int dy, GameMap& map, bool noCollision);
};