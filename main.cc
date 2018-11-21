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
        // create a grid of size n
        if (command == "left") {
            game.move("left", 1);
        } else if (command == "right") {
            int step;
            cin >> step;
            game.move("right", step);
        } else if (command == "down") {
            game.move("down", 1);
        } else if (command == "rotate") {
            game.rotate(true, 1);
        } else if (command == "drop") {
            game.drop();
        } else if (command == "level") {
            int level;
            cin >> level;
            game.setLevel(level);
        }
        // n steps
        else if (command == "steps") {

        // print
        } else if (command == "print") {
            
        }
    } 
}