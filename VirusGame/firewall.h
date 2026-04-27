#pragma once
#pragma once
#include "Entity.h"
#include "Map.h"
#include <ctime>

class Firewall : public Entity {
public:
    Firewall(GameMap& map);

    void Update(GameMap& map);
};