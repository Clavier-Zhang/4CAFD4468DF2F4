#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "game.h"
using namespace std;


int main () {
    string command;
    Game game;
    game.print();
    // Command interpreter
    while (!game.gameOver()) {
        cin >> command;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            continue;
        }
        if (command == "left") {
            int step;
            cin >> step;
            game.move("left", step);
        } else if (command == "right") {
            int step;
            cin >> step;
            game.move("right", step);
        } else if (command == "down") {
            int step;
            cin >> step;
            game.move("down", step);
        } else if (command == "drop") {
            game.drop();
        } else if (command == "level") {
            int level;
            cin >> level;
            game.setLevel(level);
        }
    } 
}