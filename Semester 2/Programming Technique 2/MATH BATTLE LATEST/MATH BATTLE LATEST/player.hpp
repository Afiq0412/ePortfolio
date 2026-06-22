#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "element.hpp"

class Player : public Element {
protected: 

public:

    Player(int health);
    void draw() override;
};

#endif
