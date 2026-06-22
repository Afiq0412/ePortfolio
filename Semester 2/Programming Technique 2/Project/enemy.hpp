#ifndef ENEMY_H
#define ENEMY_H
#include "opponent.hpp"

class Enemy : public Opponent
{
    protected:
        int numOfEnemy;

    public:
        Enemy(int x, int y, float r, int lvl, int _numOfEnemy);
        void draw() const;
        void undraw() const;
        void setLevel();
        int getLevel() const;
        int winnerHp();       
};

#endif