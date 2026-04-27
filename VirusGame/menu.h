#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Menu {
private:
    int selected = 0;

    void SetCursor(int x, int y);

    void SetColor(int color);

public:
    int Show();
};