#include "exit.h"

Exit::Exit(GameMap& map) {
    _symbol = '>';
    _x = map.Width() - 2;
    _y = map.Height() / 2;
}