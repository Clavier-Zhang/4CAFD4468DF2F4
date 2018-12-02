#ifndef _BLINDDECORATOR_H_
#define _BLINDDECORATOR_H_
#include "abstractDecorator.h"
class BlindDecorator : public AbstractDecorator {
    public:
        BlindDecorator(std::shared_ptr<AbstractPlayer> , Game *g, Xwindow * w);
        // add the points of blocks to grid, update the block in drop(), 
        ~BlindDecorator();

        void drop() override;

        int rotate(bool, int) override;

        int move(std::string, int) override;

        std::string getGridRow(int) override;

        std::string getGridPoint(int, int) override;

        void setCurrentBlock(char) override;

        // Methods for destroying the decorator without destroying underlying component

        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        
        void nullifyUnderlyingPlayer() override;

        std::shared_ptr<AbstractPlayer> getBasePlayer();
};
#endif
