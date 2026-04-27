#include "firewall.h"


    Firewall::Firewall(GameMap& map) {
        
        do {
            _x = rand() % map.Width();
            _y = rand() % map.Height();
        } while (map.IsWall(_x, _y));
        _symbol = 'F';

     
        map.SetTile(_x, _y, 'F');
    }

    void Firewall::Update(GameMap& map) {
     }
