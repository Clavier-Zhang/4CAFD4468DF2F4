#ifndef _HEAVYDECORATOR_H_
#define _HEAVYDECORATOR_H_
#include "abstractDecorator.h"
class HeavyDecorator : public AbstractDecorator {
        std::shared_ptr<AbstractPlayer> getBasePlayer();
   public:
        HeavyDecorator(std::shared_ptr<AbstractPlayer>, Game *g, Xwindow *w);
        ~HeavyDecorator();

        void drop(bool) override;
        int rotate(bool, int, bool isBlind=false) override;
        int move(std::string, int, bool isBlind=false) override;

        std::string getGridRow(int) override;
        std::string getGridPoint(int, int) override;

        void setCurrentBlock(char) override;

        // Methods for destroying the decorator without destroying underlying component

        std::shared_ptr<AbstractPlayer> getUnderlyingPlayer() override;
        void nullifyUnderlyingPlayer() override;
        void setUnderlyingPlayer(std::shared_ptr<AbstractPlayer>) override;
        
        void drawGridPoint(int x, int y, int col) override ;
        
        int getLevel() override;
        int getHighScore() override;
        int getNumDrop() override;
        int getCurrentScore() override;

        void setLevel(int) override;
        void setHighScore(int) override;
        void setNumDrop(int)override;
        void setRandom(bool rand, std::string file) override;
};
#endif
