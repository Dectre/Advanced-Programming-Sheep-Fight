#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"
#include "Line.h"
#include "Indicator.h"

class Player {
public:
    Player(int playerNumber);
    int getHealth(){return this->health;}
    void setIndicator(int direction);
    float getStartPoint() {return this->startPointX;}
private:

    void initVariables(int playerNumber);
    Indicator* indicator;
    int health;
    float startPointX;
};

#endif //SHEEPFIGHT_PLAYER_H
