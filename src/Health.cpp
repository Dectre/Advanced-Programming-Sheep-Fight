#include "Health.h"

Health::Health(bool isLeft, float x, float y) : health(100) {
    this->initHealthLine(x, y, isLeft);
}

void Health::initHealthLine(float x, float y, bool isLeft) {
    healthLine.setSize(sf::Vector2f(50, (500 * health) / 100));
    healthLine.setFillColor(sf::Color::Green);
    healthLine.setOutlineColor(sf::Color(150, 75, 0));
    healthLine.setOutlineThickness(0);
    healthLine.setPosition(x, y); // Fixed position.
}

void Health::updateHealth(int healthValue) {
    health = healthValue;
    healthLine.setSize(sf::Vector2f(50, (500 * health) / 100));
}

void Health::render(sf::RenderTarget &target) {
    target.draw(healthLine);
}