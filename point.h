#ifndef _POINT_H_
#define _POINT_H_
#include <string>
#include <iostream>
class Point {
    private:
        int x;
        int y;
        // for bash display, can be Z
        std::string type;
    public:
        Point(int x, int y, std::string type);
        void draw();
        void undraw();
        void setType(std::string type);
        void reset();
        int getX();
        int getY();
        std::string getType();
};
#endif