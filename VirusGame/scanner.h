#pragma once
#include "Entity.h"
#include "Map.h"
#include "Player.h"
#include <Windows.h>
#include <ctime>

class Scanner : public Entity {
private:
    ULONGLONG lastMove;
    int moveDelay; 

public:
    Scanner(GameMap& map);

    void Update(Player& player, GameMap& map);
};