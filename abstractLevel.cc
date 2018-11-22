#include "abstractLevel.h"
#include <cstdlib>


using namespace std;

AbstractLevel::AbstractLevel(int level, std::string sequence, bool isRandom )
    : level{level}, sequence{sequence}, isRandom{isRandom} {}

AbstractLevel::~AbstractLevel() {}

char AbstractLevel::generateChar(double bI, double bJ,double bL, double bT, double bS, double bZ, double bO){
    double prob= ((double)rand()/(RAND_MAX));
    double intv=bI;
    if (prob <= intv){
        return 'I';
    }
    intv+=bJ;

    if ( prob<=intv){
        return 'J';
    }
    intv+=bL;

    if ( prob<= intv){
        return 'L';
    }
    intv+=bT;
    
    if (prob <= intv){
        return 'T';
    }
    intv+=bS;

    if ( prob <= intv){
        return 'S';
    }

    intv+= bZ;

    if (prob <= intv){
        return 'Z';
    }

    
    return 'O';
}

int AbstractLevel::getLevel() {
    return this->level;
}



