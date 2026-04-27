#include "scanner.h"



    
   


    Scanner::Scanner(GameMap& map) {
        this->lastMove = 0;   
        this->moveDelay = 350;
        
        do {
            _x = rand() % map.Width();
            _y = rand() % map.Height();
        } while (map.IsWall(_x, _y));
        _symbol = 'S';
    }

    void Scanner::Update(Player& player, GameMap& map) {
        if (GetTickCount64() - lastMove < moveDelay) return;
        lastMove = GetTickCount64();

        int dx = 0, dy = 0;

        
        if (abs(player._x - _x) > abs(player._y - _y)) {
            dx = (player._x > _x) ? 1 : -1;
        }
        else {
            dy = (player._y > _y) ? 1 : -1;
        }

        
        if (map.IsWall(_x + dx, _y + dy)) {
            int sides[2][2];
            if (dx != 0) {
                sides[0][0] = 0; sides[0][1] = 1;
                sides[1][0] = 0; sides[1][1] = -1;
            }
            else {
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

        if (!map.IsWall(_x + dx, _y + dy)) {
            _x += dx;
            _y += dy;
        }
    }