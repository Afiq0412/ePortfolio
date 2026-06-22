#ifndef LOOT_H
#define LOOT_H
#include "opponent.hpp"

class Loot : public Opponent
{
    protected:

    public:
        Loot(int x, int y, float r, int lvl);
        void draw() const;
        void undraw() const;
        void setLevel();
        int getLevel() const;
        int winnerHp();
};

#endif