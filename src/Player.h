#ifndef SHEEPFIGHT_PLAYER_H
#define SHEEPFIGHT_PLAYER_H

#include "Manual.h"
#include "Indicator.h"
#include "Health.h"
#include "Queue.h"

class Player {
public:
    Player(int playerNumber);

    int getHealthNumber(){return this->health->getHealth();}
    Health* getHealth() {return this->health; }
    float getStartPointX() { return this->startPointX;}
    float getHealthBarX() { return this->healthBarX;}

    void showIndicator() { this->indicator->show(); }
    void hideIndicator() { this->indicator->hide(); }
    bool checkIndicatorStatus() {return this->indicator->getStatus(); }
    void moveIndicator(Direction dir) {this->indicator->move(dir);}
    int getIndicatorPointer() { return this->indicator->getPoint(); }

    Animal* getFirstAnimalFromQueue() { return this->queue->getFirstAnimal(); }
    void updateQueue(int playerNumber) { this->queue->update(playerNumber); }
    float getQueueYpos(){ return this->queueY;}
    void render(sf::RenderTarget& target);
private:
    void initVariables(int playerNumber);
    Indicator* indicator;
    Health* health;
    Queue* queue;
    float startPointX;
    float healthBarX;
    float queueY;

};

#endif //SHEEPFIGHT_PLAYER_H
