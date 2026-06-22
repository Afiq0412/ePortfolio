#ifndef OPPONENT_H
#define OPPONENT_H
#include "element.hpp"

class Opponent : public Element
{
    protected:
        int level;

    public:
        Opponent(int x, int y, float r, int _level);
        virtual void setLevel() = 0;
        virtual void draw() const = 0;
        virtual void undraw() const=0;
        int getLevel() const;
        bool isMouseClicked(int mx, int my) const;
};

#endif