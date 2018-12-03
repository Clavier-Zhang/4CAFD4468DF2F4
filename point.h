#ifndef _POINT_H_
#define _POINT_H_
#include <string>
#include <iostream>
#include "window.h"
class Game;
class Point {
    private:
        int x;
        int y;
        int id = -1; // default ID to indicate it is not yet a member of inactiveBlocks
        // (once the block to which point belongs is added to inactiveBlocks, it gains 
        // the ID of the block to which is belongs
        // for bash display, can be Z
        std::string type;
        Game *g;
        // who it belongs to
        int playerNum;
        Xwindow *w;
    public:
        Point(int x, int y, std::string type, int playerNum, Xwindow *w);
        
        // Setters
        void setType(std::string type, bool isBlind = false); // sets type and draws point if graphics are enabled
        void setID(int n); // gives point ID n, only called when adding a block to inactiveBlocks
        void reset(bool isBlind);
        void resetId(); // sets id to -1 once its block is removed from inactiveBlocks
        
        // Getters
        int getX();
        int getY();
        int getID();
        std::string getType();
};
#endif
