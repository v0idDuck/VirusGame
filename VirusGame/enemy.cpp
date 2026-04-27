#include "enemy.h"

Enemy::Enemy(GameMap& map) {
    do {
        _x = rand() % map.Width();
        _y = rand() % map.Height();
    } while (map.IsWall(_x, _y));
    _symbol = 'A';
}

bool Enemy::HasLineOfSight(int tx, int ty, GameMap& map) {
    int x0 = _x, y0 = _y;
    int dx = abs(tx - x0), dy = abs(ty - y0);
    int sx = (tx > x0) ? 1 : -1;
    int sy = (ty > y0) ? 1 : -1;
    int err = dx - dy;

    while (x0 != tx || y0 != ty) {
        if (map.IsWall(x0, y0)) return false;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
    return true;
}


void Enemy::Update(Player& player, GameMap& map) {
    if (GetTickCount64() - lastMove < Settings::enemySpeed) return;
    lastMove = GetTickCount64();

    int distance = abs(player._x - _x) + abs(player._y - _y);
    bool canSeePlayer = (distance <= 15) && HasLineOfSight(player._x, player._y, map);

    int dx = 0, dy = 0;

    if (canSeePlayer) {
        // Основное направление к игроку
        if (abs(player._x - _x) > abs(player._y - _y)) {
            dx = (player._x > _x) ? 1 : -1;
        }
        else {
            dy = (player._y > _y) ? 1 : -1;
        }

        // Если основной путь заблокирован — пробуем перпендикуляр
        if (map.IsWall(_x + dx, _y + dy)) {
            int sides[2][2];
            if (dx != 0) { // двигались по X, пробуем Y
                sides[0][0] = 0; sides[0][1] = 1;
                sides[1][0] = 0; sides[1][1] = -1;
            }
            else {       // двигались по Y, пробуем X
                sides[0][0] = 1; sides[0][1] = 0;
                sides[1][0] = -1; sides[1][1] = 0;
            }
            dx = 0; dy = 0;
            for (auto& s : sides) {
                if (!map.IsWall(_x + s[0], _y + s[1])) {
                    dx = s[0]; dy = s[1];
                    break;
                }
            }
        }
    }
    else {
        // Вне зоны видимости — рандомное блуждание, но не в стену
        int dirs[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
        for (int attempt = 0; attempt < 4; attempt++) {
            int r = rand() % 4;
            if (!map.IsWall(_x + dirs[r][0], _y + dirs[r][1])) {
                dx = dirs[r][0]; dy = dirs[r][1];
                break;
            }
        }
    }

    if (!map.IsWall(_x + dx, _y + dy)) {
        _x += dx;
        _y += dy;
    }
}

