#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"
#include "Line.h"
class Player {
public:
    int getHealth();
    void setLinePointer(int direction);

private:
    int health=10;
    int linePointer;
};

#endif //SHEEPFIGHT_PLAYER_H
