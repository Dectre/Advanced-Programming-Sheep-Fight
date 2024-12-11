#include "Health.h"
#include "Player.h"

Health::Health(Player* player) {
    this->health = 100;
    this->initHealthLine(player->getHealthBarX(),HealthBarYPos);
}

void Health::initHealthLine(float x, float y) {
    this->healthLine.setSize(sf::Vector2f(healthBarWidth, (healthBarHeight * health) / 100));
    this->healthLine.setFillColor(healthBarColor);
    this->healthLine.setOutlineColor(healthBarColor);
    this->healthLine.setPosition(x, y);
    this->healthOutline.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
    this->healthOutline.setFillColor(sf::Color::Transparent);
    this->healthOutline.setOutlineColor(sf::Color::Black);
    this->healthOutline.setOutlineThickness(healthBarOutlineThickness);
    this->healthOutline.setPosition(x, y);
}

void Health::updateHealthbar() {
    healthLine.setSize(sf::Vector2f(healthBarWidth, healthBarHeight*this->health/100));

}

void Health::render(sf::RenderTarget &target) {
    target.draw(healthLine);
    target.draw(healthOutline);

}