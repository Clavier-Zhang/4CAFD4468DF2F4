#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "game.h"
using namespace std;

bool isGraphical = true;
// add possible short version commands into map
// notice we will not add unambiguous commands shorthand
vector<string> baseCommands = {
    "left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", 
    "I", "J", "L", "O", "S", "T", "Z", 
    "random", "norandom", "sequence" // this line need to be checked later
    };

bool validSpecialAction(string action) {
    if (action == "force") return true;
    if (action == "heavy") return true;
    if (action == "blind") return true;
    return false;
}

bool validBlock(char c) {
 switch (c) {
  case 'S' : return true;
  case 's' : return true;
  case 'Z' : return true;
  case 'z' : return true;
  case 'I' : return true;
  case 'i' : return true;
  case 'J' : return true;
  case 'j' : return true;
  case 'L' : return true;
  case 'l' : return true;
  case 'O' : return true;
  case 'o' : return true;
  case 'T' : return true;
  case 't' : return true;
  default : return false;
 }
}

int main () {

    // possible short version commands
    map<string, string> commandMap;
    // duplicates means the string in this vector (short version command)
    // can not be used, use this vector to remove them in the map
    vector<string> duplicates;
    // start to add possible short command
    for (string &baseCommand : baseCommands) {
        string possibleCommand = "";
        for (int i = 0; i < baseCommand.length(); i++) {
            possibleCommand += baseCommand[i];
            if (commandMap.count(possibleCommand) != 0) {
                duplicates.emplace_back(possibleCommand);
            }
            pair<string, string> commandPair{possibleCommand, baseCommand};
            commandMap.insert(commandPair);
        }
    }
    // remove duplicated (ambiguous) commands
    for (string &duplicate : duplicates) {
        commandMap.erase(duplicate);
    }

    // test for commandMap
    // for (const auto &p : commandMap) {
    //     cout << p.first << " " << p.second << endl;
    // }


    srand(time(NULL));
    string command;
    unique_ptr<Game>game{new Game(isGraphical)};
    game->print();

    // Command interpreter
    while (!game->gameOver() && !cin.eof()) {
      
        if (game->isNeedSpecial()) {// needs error checking
            string action;
            cout << "Please enter a special action" << endl;
       
            while (true) {
                cin >> action;
                if (cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
                }
                
                if (validSpecialAction(action)) break;
                cout << "Invalid action. Please enter 'blind', 'heavy', or 'force.'" << endl;
            }

            if (action == "force") {
                char block;
                cout << "Please enter a block to force." << endl;
                
                while (true) {
                cin >> block;
                if (cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
                }
                
                if (validBlock(block)) break;
                cout << "Invalid block. Please enter I, J, L, T, S, Z, or O." << endl;
                }        
                game->force(block); 
            } else if ((action == "heavy")||(action == "blind")) {
                game->enableSpecialAction(action);
            }
            game->print();
       }

       // error checking
        
        string word;
        cin >> word;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            continue;
        }

        // analyze the word, convert it to command and number
        string rawCommand = "";
        string numText = "";
        for (int i = 0; i < word.length(); i++) {
            if ( '0' <= word[i] && word[i] <= '9') {
                numText += word[i];
            } else {
                rawCommand += word[i];
            }
        }

        // convert the rawCommand to interpretedCommand using commandMap
        //  if unsucceffsul, invalid input
        string translatedCmd = "";
        translatedCmd = commandMap[rawCommand];
        if (translatedCmd == "") {
            cout << "the input is invalid" << endl;
            continue;
        }
        int step = 1;
        if (numText != "") step = stoi(numText);

        if (translatedCmd == "left") {
            game->move("left", step);
        } else if (translatedCmd == "right") {
            game->move("right", step);
        } else if (translatedCmd == "down") {
            game->move("down", step);
        } else if (translatedCmd == "drop") {
            game->drop(step);
        } else if (translatedCmd == "clockwise") {
            game->rotate(false, step);
        } else if (translatedCmd == "counterclockwise") {
            game->rotate(true, step);
        } else if (translatedCmd == "levelup") {
            game->levelUp(step);
        } else if (translatedCmd == "leveldown") {
            game->levelDown(step);
        } else if (translatedCmd == "norandom") {
            string randomFile;
            cin >> randomFile;
            // use this file
        } else if (translatedCmd == "random") {
        } else if (translatedCmd == "sequence") {
            string sequenceFile;
            cin >> sequenceFile;
        } else if ((translatedCmd == "I")||(translatedCmd == "J")||(translatedCmd == "L")||
        (translatedCmd == "O")||(translatedCmd == "T")||(translatedCmd == "S")||(translatedCmd == "Z")) {
        } else if (translatedCmd == "restart") {
            game->restart();
        }
    } 

}
