#include "render.h"

void SetCursor(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Render::DrawMap(GameMap& map) {
    for (int y = 0; y < map.Height(); y++) {
        SetCursor(0, y);
       for (int x = 0; x < map.Width(); x++) {
           char tile = map.GetTile(x, y);
             if (tile == '#') SetColor(15);  
            else SetColor(7);              
                std::cout << tile;
            }
        }
        SetColor(7);  
    }

void Render::DrawEntity(int x, int y, char symbol, int color) {
    SetCursor(x, y);
    SetColor(color);
    std::cout << symbol;
    SetColor(7);


}
void GameOver() {
    system("cls");

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(handle, &csbi);
    int w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    SetCursor(w / 2 - 4, h / 2);
    SetConsoleTextAttribute(handle, 12);
    std::cout << "GAME OVER";

    SetConsoleTextAttribute(handle, 7);
    SetCursor(w / 2 - 10, h / 2 + 2);
    std::cout << "Press any key to exit...";

    _getch();
}
void Victory() {
    system("cls");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    SetCursor(w / 2 - 5, h / 2);
    SetColor(10); 
    std::cout << "YOU WIN!";

    SetCursor(w / 2 - 10, h / 2 + 2);
    SetColor(7);
    std::cout << "Press any key to continue...";

    _getch();
}

void Render::DrawHUD(int infected, int total) {
    SetCursor(0, 26);  
    SetColor(10);     
    std::cout << "INFECTED: " << infected << "/" << total << "   ";
    SetCursor(18, 26);
    if(infected >= total) { std::cout << "NOW FIND EXIT!";  }
    SetCursor(0, 27);
	std::cout << "Use arrows or WASD to move. Press ESC to quit.";
    SetColor(7);
}
void Render::DrawVision(GameMap& map, Player& player, int radius,
    Enemy& windef, Enemy& drweb, Scanner& scanner,
    std::vector<File>& files, std::vector<Firewall>& firewalls,
    Exit& exit, bool fullVision) {
    static bool lastFullVision = false;
    if (fullVision ) {
        DrawMap(map);
    }
    else {
  
        for (int dy = -radius; dy <= radius; dy++) {
            for (int dx = -radius; dx <= radius; dx++) {
                int x = player._x + dx;
                int y = player._y + dy;
                if (x < 0 || y < 0 || x >= map.Width() || y >= map.Height()) continue;
                SetCursor(x, y);
                SetColor(7);
                std::cout << map.GetTile(x, y);
            }
        }
    }
    lastFullVision = fullVision;
    
    auto inRadius = [&](int x, int y) {
        return abs(x - player._x) <= radius && abs(y - player._y) <= radius;
        };

    if (inRadius(windef._x, windef._y) || (fullVision))
        Render::DrawEntity(windef._x, windef._y, windef._symbol, 12);
    if (inRadius(drweb._x, drweb._y) || (fullVision))
        Render::DrawEntity(drweb._x, drweb._y, drweb._symbol, 12);
    if (inRadius(scanner._x, scanner._y) || (fullVision))
        Render::DrawEntity(scanner._x, scanner._y, scanner._symbol, 13);
    if (inRadius(exit._x, exit._y) || (fullVision))
        Render::DrawEntity(exit._x, exit._y, exit._symbol, 9);
    for (auto& f : files)
        if ((inRadius(f._x, f._y) || (fullVision)) && !f.infected)
            Render::DrawEntity(f._x, f._y, f._symbol, 14);

    
    Render::DrawEntity(player._x, player._y, player._symbol, 10);
}