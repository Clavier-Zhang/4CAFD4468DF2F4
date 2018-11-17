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
        void draw();
        void undraw();
        void getX();
        void getY();
        void getType();
};
// text output
std::ostream& operator<<(std::ostream &out, const Point &p);
#endif