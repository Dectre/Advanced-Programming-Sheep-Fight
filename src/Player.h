#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"
#include "Indicator.h"
#include "Health.h"

class Player {
public:
    Player(int playerNumber);
    int getHealthNumber(){return this->health->getHealth();}
    Health* getHealth() {return this->health; }
    float getStartPointX() { return this->startPointX;}
    float getHealthBarX() { return this->healthBarX;}
    void showIndicator() { this->indicator->show(); }
    void hideIndicator() { this->indicator->hide(); }
    void moveIndicator(Direction dir) {this->indicator->move(dir);}
    void render(sf::RenderTarget& target);
private:
    void initVariables(int playerNumber);
    Indicator* indicator;
    Health* health;
    float startPointX;
    float healthBarX;
};

#endif //SHEEPFIGHT_PLAYER_H
