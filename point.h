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
        void setType(std::string type);
        void setID(int n);
        void reset();
        int getX();
        int getY();
        int getID();
        std::string getType();
        void resetId(); // sets id to -1 once its block is removed from inactiveBlocks
};
#endif
