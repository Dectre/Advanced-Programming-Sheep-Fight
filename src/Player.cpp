#include "Player.h"

Player::Player(int playerNumber) {
    initVariables(playerNumber);
};

void Player::render(sf::RenderTarget& target) {
    this->health->render(target);
    this->indicator->render(target);
    this->queue->render(target);
}
void Player::initVariables(int playerNumber) {
    this->startPointX = playerNumber == WHITE_PLAYER ? playerOneStartPoint : playerTwoStartPoint;
    this->healthBarX = playerNumber == WHITE_PLAYER ? playerOneHealthBarXPos : playerTwoHealthBarXPos;
    this->queueY = playerNumber == WHITE_PLAYER ? whitePlayerqueueYPos : blackPlayerqueueYPos;
    this->indicator = new Indicator(this, playerNumber);
    this->health = new Health(this);
    this->queue = new Queue(playerNumber, this);
}

void Player::update() {
    this->health->updateHealthbar();
}


