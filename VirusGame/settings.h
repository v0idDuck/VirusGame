#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Settings {
private:
    int selected = 0;

    void SetCursor(int x, int y);

    void SetColor(int color);

public:

    static int enemySpeed;    
    static int visionRadius;  
    static int fileCount;       
    static bool cheatsEnabled;  
    static bool useCustomMap;
    static std::string customMapPath;

    void Show();
};
