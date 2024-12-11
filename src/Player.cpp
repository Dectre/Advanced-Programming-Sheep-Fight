#include "Player.h"

void Player::setIndicator(int direction) {
}

Player::Player(int playerNumber) {
    initVariables(playerNumber);
};

void Player::initVariables(int playerNumber) {
    if (playerNumber == WHITE_PLAYER) this->startPointX = playerOneStartPoint;
    else this->startPointX = playerTwoStartPoint;
    this->indicator = new Indicator(this, playerNumber);
}
