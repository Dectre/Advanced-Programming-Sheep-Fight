#include "Health.h"

Health::Health(float x, float y) : health(100) {
    this->initHealthLine(x, y);
}

void Health::initHealthLine(float x, float y) {
    this->healthLine.setSize(sf::Vector2f(50, (500 * health) / 100));
    this->healthLine.setFillColor(sf::Color::Green);
    this->healthLine.setOutlineColor(sf::Color(150, 75, 0));
    this->healthLine.setOutlineThickness(0);
    this->healthLine.setPosition(x, y); // Fixed position.
    this->healthOutline.setSize(sf::Vector2f(50, 500));
    this->healthOutline.setFillColor(sf::Color::Transparent);
    this->healthOutline.setOutlineColor(sf::Color::Black);
    this->healthOutline.setOutlineThickness(10);
    this->healthOutline.setPosition(x, y); // Fixed position.
}

void Health::updateHealth(int healthValue) {
    this->health = healthValue;
    healthLine.setSize(sf::Vector2f(50, (500 * health) / 100));

}

void Health::render(sf::RenderTarget &target) {
    target.draw(healthLine);
    target.draw(healthOutline);

}