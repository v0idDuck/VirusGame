#pragma once
#include "entity.h"
#include "map.h"
#include "player.h"
#include "settings.h"
#include <Windows.h>
#include <ctime>

class Enemy : public Entity {
private:
    ULONGLONG lastMove = 0;
public:
    Enemy(GameMap& map);
    void Update(Player& player, GameMap& map);
    bool HasLineOfSight(int tx, int ty, GameMap& map);
};