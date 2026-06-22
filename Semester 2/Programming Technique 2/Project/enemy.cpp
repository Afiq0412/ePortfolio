#include <graphics.h>
#include "enemy.hpp"

Enemy::Enemy(int x, int y, float r, int lvl, int _numOfEnemy): numOfEnemy(_numOfEnemy), Opponent(x,y,r,lvl){}

void Enemy::draw() const
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(positionX, positionY, radius, radius);
}

void Enemy::undraw() const
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(positionX, positionY, radius, radius);
}

void Enemy::setLevel()
{
    level = 15 + rand() % 50;
}

int Enemy::winnerHp()
{
    return ; //playerHp + level;
}