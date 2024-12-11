#include "Player.h"


Player::Player(int playerNumber) {
    initVariables(playerNumber);
};

void Player::render(sf::RenderTarget& target) {
    this->health->render(target);
    this->indicator->render(target);
}
void Player::initVariables(int playerNumber) {
    this->startPointX = playerNumber == WHITE_PLAYER ? playerOneStartPoint : playerTwoStartPoint;
    this->healthBarX = playerNumber == WHITE_PLAYER ? playerOneHealthBarXPos : playerTwoHealthBarXPos;
    this->indicator = new Indicator(this, playerNumber);
    this->health = new Health(this);
}


