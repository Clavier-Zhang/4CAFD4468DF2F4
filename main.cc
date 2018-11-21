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
    while (cin >> command) {
        // create a grid of size n
        if (command == "left") {
            game.move("left", 1);
        } else if (command == "right") {
            game.move("right", 1);
        } else if (command == "down") {
            game.move("down", 1);
        } else if (command == "rotate") {
            game.rotate(true, 1);
        }
        // one step
        else if (command == "step") {

        }
        // n steps
        else if (command == "steps") {

        // print
        } else if (command == "print") {
            
        }
    } 
}