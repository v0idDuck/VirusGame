#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Map.h"
#include "Render.h"
#include "Player.h"
#include "Enemy.h"
#include "firewall.h"
#include "scanner.h"
#include "file.h"
#include "exit.h"
#include "menu.h"
#include "settings.h"
#include "cheatmenu.h"
static CheatMenu cheat;

void game() {
    srand(time(0));

    int infected = 0;
    GameMap map;
    if (Settings::useCustomMap) {
        if (!map.LoadFromFile("levels/custom.txt")) {

            SetCursor(0, 0);
            std::cout << "custom.txt not found! Using default map.\n";
            Sleep(1500);
            system("cls");
        }
    }
    Render render;
    Player player(1, 1);
    Enemy windef(map);
    Enemy drweb(map);
    std::vector<Firewall> firewalls;
    for (int i = 0; i < 5; i++) {  
        firewalls.push_back(Firewall(map));
    }
    Scanner scanner(map);
    std::vector<File> files;
    for (int i = 0; i < Settings::fileCount; i++) {
        files.push_back(File(map));
    }
    Exit exit(map);
    

    
    

    while (true) {
        int oldWindefX = windef._x, oldWindefY = windef._y;
        int oldDrwebX = drweb._x, oldDrwebY = drweb._y;
        int oldScannerX = scanner._x, oldScannerY = scanner._y;

        
        if (_kbhit()) {
            int key = _getch();
            if (key == 224) {
                key = _getch();
                if (key == 72) player.Move(0, -1, map, cheat.noCollision);
                if (key == 80) player.Move(0, 1, map, cheat.noCollision);
                if (key == 75) player.Move(-1, 0, map, cheat.noCollision);
                if (key == 77) player.Move(1, 0, map, cheat.noCollision);
            }
            // WASD
            if (key == 'w' || key == 'W') player.Move(0, -1, map, cheat.noCollision);
            if (key == 's' || key == 'S') player.Move(0, 1, map, cheat.noCollision);
            if (key == 'a' || key == 'A') player.Move(-1, 0, map, cheat.noCollision);
            if (key == 'd' || key == 'D') player.Move(1, 0, map, cheat.noCollision);

            if (key == 0xC0 || key == '`') {
                if (Settings::cheatsEnabled) {
                    system("cls");
                    cheat.Show();
                }
            }

            if (key == 27) break;
        }

        
        windef.Update(player, map);
        drweb.Update(player, map);
		scanner.Update(player, map);
        
        if (oldWindefX != windef._x || oldWindefY != windef._y)
            render.DrawEntity(oldWindefX, oldWindefY, map.GetTile(oldWindefX, oldWindefY), 7);
        if (oldDrwebX != drweb._x || oldDrwebY != drweb._y)
            render.DrawEntity(oldDrwebX, oldDrwebY, map.GetTile(oldDrwebX, oldDrwebY), 7);
        if (oldScannerX != scanner._x || oldScannerY != scanner._y)
            render.DrawEntity(oldScannerX, oldScannerY, map.GetTile(oldScannerX, oldScannerY), 7);
      if (((player._x == windef._x && player._y == windef._y) ||
        (player._x == drweb._x && player._y == drweb._y) || (player._x == scanner._x && player._y == scanner._y)) && (!cheat.noGameOver)) {
            GameOver();
            break;
}
      for (auto& f : files) {
          if (player._x == f._x && player._y == f._y && !f.infected) {
              f.infected = true;
              infected++;
          }
      }
        
        render.DrawVision(map, player, Settings::visionRadius, windef, drweb, scanner, files, firewalls, exit, cheat.fullVision);
        render.DrawHUD(infected, files.size());

        if (player._x == exit._x && player._y == exit._y) {
            if (infected == (int)files.size()) {
                Victory();
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return;
}
int main() {
    Menu menu;
    Settings settings;
    CONSOLE_CURSOR_INFO ci = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    

    while (true) {
        int choice = menu.Show();

        if (choice == 0) {
            system("cls");
            game();
        }
        else if (choice == 1) {
            
            settings.Show();
        }
        else {
            break;
        }
    }
}