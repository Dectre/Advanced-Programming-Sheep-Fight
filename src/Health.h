#ifndef SHEEPFIGHT_HEALTH_H
#define SHEEPFIGHT_HEALTH_H

#include "Manual.h"

class Health {
public:
    //HEALTH BARS REDUCING IS NOT FIXED
    Health(float x, float y);
    void render(sf::RenderTarget &target);
    void updateHealth(int healthValue);

private:
    int health;
    sf::RectangleShape healthLine;
    sf::RectangleShape healthOutline;
    void initHealthLine(float x, float y);
};

#endif //SHEEPFIGHT_HEALTH_H
