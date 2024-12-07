#include "Player.h"

Player::Player() : health(100) {}

int Player::getHealth(){
    return health;
}

void Player::setHealth(int h) {
    health = h;
}
