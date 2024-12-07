#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"

class Player {
private:
    int health; // Health value (0 to 100).

public:
    Player();
    int getHealth();
    void setHealth(int h);
};

#endif //SHEEPFIGHT_PLAYER_H
