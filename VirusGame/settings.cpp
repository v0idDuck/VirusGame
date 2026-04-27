#include "settings.h"

int Settings::enemySpeed = 250;
int Settings::visionRadius = 8;
int Settings::fileCount = 10;
bool Settings::cheatsEnabled = false;
bool Settings::useCustomMap;
std::string Settings::customMapPath;
void Settings::SetCursor(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Settings::SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Settings::Show() {
    system("cls");

    while (true) {
        SetCursor(0, 0);
        SetColor(10);
        std::cout << "SETTINGS\n\n";
        SetColor(7);

        SetColor(selected == 0 ? 10 : 7);
        std::cout << "0. Enemy speed:   " << enemySpeed << " ms\n";

        SetColor(selected == 1 ? 10 : 7);
        std::cout << "1. Vision radius: " << visionRadius << " \n";

        SetColor(selected == 2 ? 10 : 7);
        std::cout << "2. File count:    " << fileCount << " \n";

        SetColor(selected == 3 ? 10 : 7);
        std::cout << "3. Cheats:        " << (cheatsEnabled ? "ON " : "OFF") << "\n";

        SetColor(selected == 4 ? 10 : 7);
        std::cout << "4. Custom map:    " << (useCustomMap ? "ON " : "OFF") << "\n";
		std::cout << "   (place custom.txt in levels/)\n";

        SetColor(7);
        std::cout << "\nW/S - navigate  A/D - change  ESC - back\n";

        int key = _getch();

        if (key == 27) break;  // ESC назад

        if (key == 'w' || key == 'W') if (selected > 0) selected--;
        if (key == 's' || key == 'S') if (selected < 4) selected++;

        if (key == 'a' || key == 'A') {
            if (selected == 0 && enemySpeed < 800) enemySpeed += 50;
            if (selected == 1 && visionRadius > 3) visionRadius--;
            if (selected == 2 && fileCount > 3)    fileCount--;
            if (selected == 3) cheatsEnabled = !cheatsEnabled;
            if (selected == 4) useCustomMap = !useCustomMap;
        }
        if (key == 'd' || key == 'D') {
            if (selected == 0 && enemySpeed > 100) enemySpeed -= 50;
            if (selected == 1 && visionRadius < 20) visionRadius++;
            if (selected == 2 && fileCount < 20)    fileCount++;
            if (selected == 3) cheatsEnabled = !cheatsEnabled;
            if (selected == 4) useCustomMap = !useCustomMap;
        }
    }
    system("cls");
}