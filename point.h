#ifndef _POINT_H_
#define _POINT_H_
#include <string>
#include <iostream>
#include "window.h"
class Point {
    private:
        int x;
        int y;
        // for bash display, can be Z
        std::string type;
        // window
        Xwindow *xw;
    public:
        Point(int x, int y, std::string type, Xwindow *xw);
        void draw();
        void undraw();
        int getX();
        int getY();
        std::string getType();
};
#endif