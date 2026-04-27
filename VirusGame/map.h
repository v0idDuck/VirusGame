#pragma once
#include <string>
#include <vector>
#include <fstream>

class GameMap {

public:
    std::vector<std::string> tiles;
    int Width();
    int Height();

    GameMap();
    bool LoadFromFile(const std::string& path);
    char GetTile(int x, int y);
    void SetTile(int x, int y, char c);
    bool IsWall(int x, int y);
};