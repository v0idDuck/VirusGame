#include "cheatmenu.h"
void CheatMenu::SetCursor(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CheatMenu::SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void CheatMenu::Show() {
    SetCursor(0, 0);
    SetColor(10);
    std::cout << "[CHEAT] voidmenu by v0idDuck\n";
    SetColor(7);
    std::cout << "0. noGameOver  = " << (noGameOver ? "true " : "false") << "\n";
    std::cout << "1. noCollision = " << (noCollision ? "true " : "false") << "\n";
    std::cout << "2. fullVision  = " << (fullVision ? "true " : "false") << "\n\n";
    std::cout << "select number (ESC to close): ";

    while (true) {
        int key = _getch();
        if (key == 27) break;  // ESC закрыть
        if (key == '0') { noGameOver = !noGameOver;  break; }
        if (key == '1') { noCollision = !noCollision; break; }
        if (key == '2') { fullVision = !fullVision;  break; }
    }

    
    SetCursor(0, 0);
    SetColor(7);
    for (int i = 0; i < 6; i++)
        std::cout << "                                        \n";
}