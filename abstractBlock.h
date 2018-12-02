#ifndef _ABSTRACTBLOCK_H_
#define _ABSTRACTBLOCK_H_
#include <string>
#include <vector>
class AbstractLevel;
class Point;
class AbstractPlayer;
class AbstractBlock {
       // When a block is added to the map inactiveBlocks (in abstractcPlayer), its key
       // is an ID; upon addition, each point in the block gets this ID so it can be
       // efficiently retrieved later
       static int curId; // increments every time
    // set protected, so can be called in concrete block and draw
    protected:
        // have four points in the vector
        // each time we move or rotate block, 
        // we edit the points in the vector
        std::vector<Point*> points;
        std::string type;
        // 4 pairs of number to store init positions
        std::vector<std::pair<int, int>> positions;
        int score = 0;
    public:
        AbstractBlock(std::string type, int score);
        virtual ~AbstractBlock();
        virtual void initialize(AbstractPlayer *p) = 0;
        bool addPoint(std::pair<int, int> &c, AbstractPlayer *p, bool isBlind=false);
        void addPoints(std::vector<std::pair<int, int>>& coordinates, AbstractPlayer *p, bool isBlind=false);
        void removeAllPoint(bool isBlind=false);
        void removeOnePoint(Point *p);
        std::string getType();
        std::vector<Point*>& getPoints();
        bool contain(Point *p);
        int getScore();
        std::vector<std::pair<int, int>> & getPositions();
        std::pair<int, int> getLowerLeft();
        void setID(int id);
        static int getCurId();
        static void incrementCurId();
};
#endif
