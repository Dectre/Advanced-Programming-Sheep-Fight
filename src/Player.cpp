#include "Player.h"

void Player::setLinePointer(int direction){
    linePointer=(direction+linePointer)%4;
}

int Player::getHealth(){return health;};
