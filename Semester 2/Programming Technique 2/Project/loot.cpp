#include <graphics.h>
#include "loot.hpp"

Loot::Loot(int x, int y, float r, int lvl): Opponent(x,y,r,lvl){}

void Loot::draw() const
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    fillellipse(positionX, positionY, radius, radius);
}

void Loot::undraw() const
{
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(positionX, positionY, radius, radius);
}

void Loot::setLevel()
{
    level = 10 + rand() % 30;
}

int Loot::winnerHp()
{
    return 10; //playerHp + level;
}