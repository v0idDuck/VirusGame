#pragma once
#include "Entity.h"
#include "Map.h"

class Exit : public Entity {
public:
    Exit(GameMap& map);
};