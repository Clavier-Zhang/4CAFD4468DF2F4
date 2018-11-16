#ifndef _POINT_H_
#define _POINT_H_
#include <string>
class Point {
    private:
        int x;
        int y;
        // for window display
        std::string colour;
        // for bash display, can be Z
        std::string type;
    public:
        void draw();
};
#endif