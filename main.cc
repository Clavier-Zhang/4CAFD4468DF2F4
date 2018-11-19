#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "game.h"
using namespace std;


int main () {
    string s;
    Game game;
    game.print();
    game.setLevel(2);
    game.print();

    // Command interpreter
    while (cin >> s) {
        // create a grid of size n
        if (s == "new") {

        }
        // start init mode
        else if (s == "init") {
            while (true) {


            }
        }
        // one step
        else if (s == "step") {

        }
        // n steps
        else if (s == "steps") {

        // print
        } else if (s == "print") {
            
        }
    } 
}