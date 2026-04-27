#include "file.h"

File::File(GameMap& map) {
    do {
        _x = rand() % map.Width();
        _y = rand() % map.Height();
    } while (map.IsWall(_x, _y));
    _symbol = 'f';
}