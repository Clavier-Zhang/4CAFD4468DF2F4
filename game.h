#ifndef _GAME_H_
#define _GAME_H_
#include "abstractPlayer.h"
#include <memory>
#include <iostream>
class Game {
    private:
        // // player one
        std::shared_ptr<AbstractPlayer> playerOne;
        // // player two
        std::shared_ptr<AbstractPlayer> playerTwo;
        // // player in the current turn
        AbstractPlayer* currentPlayer;
        // status of game
        bool isOver = false;
        bool needSpecial = false;
    public:
        // initialize two players
        Game();
        // player's operation
        // do not need to check, call currentPlayer's method directly
        void setLevel(int level);
        void move(std::string type = "down", int step = 1);
        void rotate(bool counter = false, int step = 1);
        void drop();
        // more command to be determined
        void gameOver();
        void turnOver();
        void specialAction();
        // print
        void print();
        // modify later
        std::string getNextBlockFirstRow(std::string type);
        std::string getNextBlockSecondRow(std::string type);
};
#endif