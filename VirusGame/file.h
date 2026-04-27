#pragma once
#include "Entity.h"
#include "Map.h"

class File : public Entity {
public:
    bool infected = false;

    File(GameMap& map);
};