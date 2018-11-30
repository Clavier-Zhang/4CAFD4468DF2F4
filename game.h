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
        //AbstractPlayer* currentPlayer;
        std::shared_ptr<AbstractPlayer> currentPlayer;
        // status of game
        bool isOver = false;
        bool needSpecial = false;
        const int MAX_LEVEL = 4;
        const int MIN_LEVEL = 0;

        AbstractPlayer *createDecoratedPlayer(std::string, std::shared_ptr<AbstractPlayer>);
        void takeOffDecorations();

    public:
        // initialize two players
        Game();
        ~Game();
        void restart(); // TODO clears the board and starts a new game
        // player's operation
        // do not need to check, call currentPlayer's method directly
        void setLevel(int level);
        void move(std::string type = "down", int step = 1);
        void rotate(bool counter = false, int step = 1);
        void drop(int step = 1);
        void levelUp(int step = 1);
        void levelDown(int step = 1);
        // more command to be determined
        bool gameOver();
        bool isNeedSpecial();
        void setGameOver();
        void turnOver();
        void specialAction();
        void force(char);

        void enableSpecialAction(std::string);
        // print
        void print();
        // modify later
        std::string getNextBlockFirstRow(std::string type);
        std::string getNextBlockSecondRow(std::string type);
        int getLevel(); // gets currentPlayer's level
};
#endif
