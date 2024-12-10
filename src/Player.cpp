#include "Player.h"

void Player::setIndicator(int direction) {
}

Player::Player(int playerNumber) {
    initVariables(playerNumber);
};

void Player::initVariables(int playerNumber) {
    this->indicator = new Indicator(playerNumber);
}
