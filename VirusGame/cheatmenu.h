#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

class CheatMenu {
private:
    void SetCursor(int x, int y);
    void SetColor(int color);

public:
    bool noGameOver = false;
    bool noCollision = false;
    bool fullVision = false;

    void Show();
};