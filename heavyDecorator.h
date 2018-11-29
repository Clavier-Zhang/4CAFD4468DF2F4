#ifndef _HEAVYDECORATOR_H_
#define _HEAVYDECORATOR_H_
#include "abstractDecorator.h"
class HeavyDecorator : public AbstractDecorator {
    
        std::shared_ptr<AbstractPlayer> getBasePlayer();
    
   public:
        HeavyDecorator(std::shared_ptr<AbstractPlayer>, Game *g);
        
        void drop() override;

        int rotate(bool, int) override;

        int move(std::string, int) override;

        std::string getGridRow(int) override;

        std::string getGridPoint(int, int) override;

        void setCurrentBlock(char) override;

        // Methods for destroying the decorator without destroying underlying component

        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        
        void nullifyUnderlyingPlayer() override;
};
#endif
