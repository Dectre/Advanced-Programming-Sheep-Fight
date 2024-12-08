#ifndef SHEEPFIGHT_HEALTH_H
#define SHEEPFIGHT_HEALTH_H

#include "Manual.h"

class Health {
public:
    Health(bool isLeft, float x, float y);
    void render(sf::RenderTarget &target);
    void updateHealth(int healthValue);

private:
    int health;
    sf::RectangleShape healthLine;

    void initHealthLine(float x, float y, bool isLeft);
};

#endif //SHEEPFIGHT_HEALTH_H
