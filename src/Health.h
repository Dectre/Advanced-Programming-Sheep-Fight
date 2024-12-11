#ifndef SHEEPFIGHT_HEALTH_H
#define SHEEPFIGHT_HEALTH_H

#include "Manual.h"
#include <SFML/Graphics.hpp>

class Player;

class Health {
public:
    Health(Player* player);
    void render(sf::RenderTarget &target);
    void updateHealthbar();
    int getHealth() { return health; }
    void reduce(int damage) { this->health = this->health - damage >= 0 ? this->health - damage : 0; }

private:
    int health;
    sf::RectangleShape healthLine;
    sf::RectangleShape healthOutline;
    sf::Font font;
    sf::Text healthText;

    void initHealthLine(float x, float y);
};

#endif //SHEEPFIGHT_HEALTH_H
