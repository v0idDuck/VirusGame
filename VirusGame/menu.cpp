#include "menu.h"

void Menu::SetCursor(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Menu::SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int Menu::Show() {
    system("cls");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    
    SetCursor(w / 2 - 5, h / 2 - 3);
    SetColor(10);  
    std::cout << "VIRUS GAME";
    SetColor(7);

    while (true) {
    
        SetCursor(w / 2 - 4, h / 2);
        SetColor(selected == 0 ? 10 : 7);
        std::cout << "> PLAY";

        SetCursor(w / 2 - 4, h / 2 + 1);
        SetColor(selected == 1 ? 10 : 7);
        std::cout << "> SETTINGS";

        SetCursor(w / 2 - 4, h / 2 + 2);
        SetColor(selected == 2 ? 10 : 7);
        std::cout << "> EXIT";

        SetColor(7);

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && selected > 0) selected--;  
            if (key == 80 && selected < 2) selected++; 
        }
        if (key == 'w' || key == 'W') if (selected > 0) selected--;
        if (key == 's' || key == 'S') if (selected < 2) selected++;
        if (key == 13) return selected;  
    }
}