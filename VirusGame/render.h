#pragma once
#include <iostream>
#include <Windows.h>
#include "Map.h"
#include <conio.h>
#include "entity.h"
#include "enemy.h"
#include "player.h"
#include "exit.h"
#include "file.h"
#include "firewall.h"
#include "scanner.h"
#include "cheatmenu.h"

class GameMap;

void SetCursor(int x, int y);
void SetColor(int color);

class Render {
public:
    
    void DrawMap(GameMap& map);

    
    void DrawEntity(int x, int y, char symbol, int color);

    void DrawHUD(int infected, int total);

    void DrawVision(GameMap& map, Player& player, int radius,
        Enemy& windef, Enemy& drweb, Scanner& scanner,
        std::vector<File>& files, std::vector<Firewall>& firewalls,
        Exit& exit, bool fullVision );
};

void GameOver();
void Victory();