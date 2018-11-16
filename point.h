#ifndef _POINT_H_
#define _POINT_H_
#include <string>
#include <iostream>
#include "window.h"
class Point {
    private:
        int x;
        int y;
        // for window display
        std::string colour;
        // for bash display, can be Z
        std::string type;
        // window
        Window *xw;
    public:
        void draw();
        void undraw();
};
// text output
std::ostream& operator<<(std::ostream &out, const Point &p);
#endif