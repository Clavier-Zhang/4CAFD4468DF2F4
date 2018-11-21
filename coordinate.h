#ifndef _COORDINATE_H_
#define _COORDINATE_H_
class Coordinate {
    private:
        int x = 0;
        int y = 0;
    public:
        Coordinate(int x, int y);
        int getX();
        int getY();
};
#endif