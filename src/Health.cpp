#include "Health.h"
#include "Player.h"

Health::Health(Player* player) {
    this->health = 100;
    this->initHealthLine(player->getHealthBarX(), HealthBarYPos);

    if (!this->font.loadFromFile("fonts/font.ttf")) {
        std::cerr << "Error loading font file!" << std::endl;
    }
    this->healthText.setFont(this->font);
    this->healthText.setCharacterSize(20);
    this->healthText.setFillColor(sf::Color::Black);
    this->healthText.setString(std::to_string(this->health));
    this->healthText.setPosition(player->getHealthBarX(), HealthBarYPos - 30);
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

    if (!this->font.loadFromFile("fonts/font.ttf")) {
        std::cerr << "Error loading font file!" << std::endl;
    }

    this->healthText.setFont(this->font);
    this->healthText.setCharacterSize(20);
    this->healthText.setFillColor(sf::Color::Black);
    this->healthText.setString(std::to_string(this->health));

    sf::FloatRect textBounds = this->healthText.getLocalBounds();
    float textCenterX = textBounds.width / 2;
    float textCenterY = textBounds.height / 2;

    this->healthText.setOrigin(textCenterX, textCenterY);
    this->healthText.setPosition(x + (healthBarWidth / 2), windowHeight/2);
    this->healthText.setRotation(90);
}




void Health::updateHealthbar() {
    this->healthLine.setSize(sf::Vector2f(healthBarWidth, healthBarHeight * this->health / 100));
    this->healthText.setString(std::to_string(this->health));
}


void Health::render(sf::RenderTarget &target) {
    target.draw(healthLine);
    target.draw(healthOutline);
    target.draw(healthText);
}
