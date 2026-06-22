#include <graphics.h>
#include <cmath>
#include "opponent.hpp"

Opponent::Opponent(int x, int y, float r, int _level): level(_level), Element(x,y,r) {}

bool Opponent::isMouseClicked(int mx, int my) const
{
    int d = pow(mx-positionX,2)+pow(my-positionY,2);
    return  pow(d,2) <= radius;
}

int Opponent::getLevel() const
{
    return level;
}
