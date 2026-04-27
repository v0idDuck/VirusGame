#include "map.h"

GameMap::GameMap() {
    tiles = {
        "###############################################################################################################",
        "#             #                #                 #                          #                                 #",
        "#             #                                 #                            #                                #",
        "#             #                  #             #                              #                               #",
        "#             #                   #                                                                           #",
        "#             #                    #         #                                  #                             #",
        "#             #                     #       #                                    #                            #",
        "#                                    #     #             ################         ########  ########   ###### #",
        "##  ###### ####                ###################       #              #         #                           #",
        "#                              #                 #       #              #         #                           #",
        "#                              #                 #       #              #         #                           #",
        "#                              #                         #              #                                     #",
        "#############  #########       #                 #       #              #         #                           #",
        "#                      #       #                 #       #              #         #                           #",
        "#                      #       #                 #                      #         ######## ######### ##########",
        "#                      #       #                 #       #              #         #                           #",
        "#                      #       #                 #       #              #         #                           #",
        "#                      #                         #       #              #         #                           #",
        "#                              #                 #       #              #         #                           #",
        "#                      #       #                 #       ################                                     #",
        "#                      #       #                 #                                #                           #",
        "#                      #       #                                                  #                           #",
        "#                      #       #                 #                                #                           #",
        "#                      #       #                 #                                #                           #",
        "###############################################################################################################",
    };
}

int GameMap::Width() { return tiles[0].length(); }
int GameMap::Height() { return tiles.size(); }

char GameMap::GetTile(int x, int y) { return tiles[y][x]; }
void GameMap::SetTile(int x, int y, char c) {
    tiles[y][x] = c;
}
bool GameMap::IsWall(int x, int y) { 
    if (x < 0 || y < 0 || x >= Width() || y >= Height())
        return true;
    return tiles[y][x] == '#' || tiles[y][x] == 'F';
}
bool GameMap::LoadFromFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return false;

    tiles.clear();
    std::string line;
    while (std::getline(file, line)) {
        tiles.push_back(line);
    }
    return true;
}