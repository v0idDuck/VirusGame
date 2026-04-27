#include "player.h"

Player::Player(int x, int y) {
    this->lastMove = 0;
    this->moveDelay = 85;
    _x = x;
    _y = y;
    _symbol = '@';
    }

void Player::Move(int dx, int dy, GameMap& map, bool noCollision) {
    if (GetTickCount64() - lastMove < moveDelay) return;
    lastMove = GetTickCount64();

    int newX = _x + dx;
    int newY = _y + dy;

    if (!map.IsWall(newX, newY) || (noCollision)) {
        _x = newX;
        _y = newY;
    }

 }
