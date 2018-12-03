#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "game.h"
#include <ncurses.h>
using namespace std;

// Global values to determine initial state of the game
bool isGraphical = true;
string seq="";
string scpt1="sequence1.txt";
string scpt2="sequence2.txt";
int startLvl=0;
int seed=-1;

// add possible short version commands into map
// notice we will not add unambiguous commands shorthand
vector<string> baseCommands = {
    "left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", 
    "I", "J", "L", "O", "S", "T", "Z", 
    "random", "norandom", "sequence", "restart" // this line need to be checked later
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

//if there is a sequence of commands, use the sequence. Otherwise, cin into string cmd
void determineInput(string & cmd){
    if (seq.length()>0){
        istringstream iss{seq};
        iss>>cmd;
        seq=seq.substr((int)cmd.length()+1,(int)seq.length());
    }else{
        cin >> cmd;
    }
}

void setInitialState(int argc, char * argv[]){
    string s;
    for (int i =1; i< argc; ++i){
        s=argv[i];
        cout<<s<<endl;
        if (s == "-text"){
            isGraphical=false;
        }else if(s == "-seed"){
            if (i+1 <argc){
                ++i;
                s= argv[i];
                seed = stoi(s);
            }
        }else if(s == "-scriptfile1"){
            if (i+1 <argc){
                ++i;
                scpt1 = argv[i];
            }
        }else if(s == "-scriptfile2"){
            if (i+1 <argc){
                ++i;
                scpt2 = argv[i];
            }
        }else if (s == "-startlevel"){
            if (i+1 <argc){
                ++i;
                s=argv[i];
                startLvl = stoi(s);
            }
        }
    }
}


int main (int argc, char * argv[]) {
    setInitialState(argc, argv);
    // possible short version commands
    map<string, string> commandMap;
    // duplicates means the string in this vector (short version command)
    // can not be used, use this vector to remove them in the map
    vector<string> duplicates;
    // start to add possible short command
    for (string &baseCommand : baseCommands) {
        string possibleCommand = "";
        for (int i = 0; i < static_cast<int>(baseCommand.length()); i++) {
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

    if ( seed >-1)
        srand(seed);
    else
        srand(time(NULL));
    string command;
    unique_ptr<Game>game{new Game(isGraphical, startLvl,scpt1,scpt2)};
    game->print();

    // key feature
    int key;
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    // end of key feature

    // Command interpreter
    while (!game->gameOver() && !cin.eof()) {
        if (game->isNeedSpecial()) {// needs error checking
            string action;
            cout << "Please enter a special action" << endl;
            while (true) {
                determineInput(action);
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    continue;
                }

                if (validSpecialAction(action)) break;
                cout << "Invalid action. Please enter 'blind', 'heavy', or 'force.'" << endl;
            }

            if (action == "force") {
                string block;
                cout << "Please enter a block to force." << endl;

                while (true) {
                    determineInput(block);
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    if (validBlock(block[0]) && (int) block.length() == 1) break;
                    cout << "Invalid block. Please enter I, J, L, T, S, Z, or O." << endl;
                }        
                game->force(block[0]); 
            } else if /*((action == "heavy")||(action == "blind")){*/(action == "heavy") {
               // game->enableSpecialAction(action);
               game->enableSpecialAction(action);
               game->enableSpecialAction(action);
            } else if (action == "blind") {
               game->enableSpecialAction(action);
            }
            cout<<"printing game"<<endl;
            game->print();
            cout<<"done printing"<<endl;
        }

        // error checking

        // key feature
        key = getch();
        if (key == KEY_RIGHT) {
            game->move("right", 1);
            cout << "right" << endl;
            continue;
        }
        if (key == KEY_LEFT) {
            game->move("left", 1);
            cout << "left" << endl;
            continue;
        }
        if (key == KEY_DOWN) {
            game->move("down", 1);
            cout << "down" << endl;
            continue;
        }
        if (key == KEY_UP) {
            game->drop(1);
            cout << "drop" << endl;
            continue;
        }
        // end of key feature

        string word;
        if(game->getNumDrop() >1){
            word = "drop";
            game->setNumDrop(game->getNumDrop()-1);
        }else{
            determineInput(word);
        }

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            continue;
        }

        // analyze the word, convert it to command and number
        string rawCommand = "";
        string numText = "";
        for (int i = 0; i < static_cast<int>(word.length()); i++) {
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
            if (game->getNumDrop() == 1 && step > 0)  game->setNumDrop(step);
            else if (step == 0){ 
                continue;
            } 
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
            determineInput(randomFile);
            // use this file
            game->setRandom(false,randomFile);
        } else if (translatedCmd == "random") {
            game->setRandom(true);
        } else if (translatedCmd == "sequence") {
            string sequenceFile;
            cin >> sequenceFile;
            ifstream file{sequenceFile};
            string txtCmd;
            while(file>>txtCmd){
                seq+=txtCmd;
                seq+=" ";
            }
        } else if ((translatedCmd == "I")||(translatedCmd == "J")||(translatedCmd == "L")||
                (translatedCmd == "O")||(translatedCmd == "T")||(translatedCmd == "S")||(translatedCmd == "Z")) {
            game->force(translatedCmd[0]);
        } else if (translatedCmd == "restart") {
            game->restart(startLvl);
        }
        game->print();
    } 

}
