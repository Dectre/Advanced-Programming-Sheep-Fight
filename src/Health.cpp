#include "Health.h"

Health::Health(float x, float y) : health(50) {
    this->initHealthLine(x, y);
}

void Health::initHealthLine(float x, float y) {
    this->healthLine.setSize(sf::Vector2f(healthBarWidth, (healthBarHeight * health) / 100));
    this->healthLine.setFillColor(healthBarColor);
    this->healthLine.setOutlineColor(healthBarColor);
    this->healthLine.setOutlineThickness(0);
    this->healthLine.setPosition(x, y);
    this->healthOutline.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
    this->healthOutline.setFillColor(sf::Color::Transparent);
    this->healthOutline.setOutlineColor(sf::Color::Black);
    this->healthOutline.setOutlineThickness(10);
    this->healthOutline.setPosition(x, y);
}

void Health::updateHealth(int healthValue) {
    this->health = healthValue;
    healthLine.setSize(sf::Vector2f(healthBarWidth, healthBarHeight*healthValue/100));

}

void Health::render(sf::RenderTarget &target) {
    target.draw(healthLine);
    target.draw(healthOutline);

}