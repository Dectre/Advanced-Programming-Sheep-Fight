#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"
#include "Line.h"
#include "Indicator.h"

class Player {
public:
    Player(int playerNumber);
    int getHealth(){return health;}
    void setIndicator(int direction);
private:

    void initVariables(int playerNumber);
    Indicator* indicator;
    int health;
};

#endif //SHEEPFIGHT_PLAYER_H
