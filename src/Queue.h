#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Queue {
private:
    vector<Animal*> animalQueue;
    sf::Vector2f bubblePositions[3];
    size_t maxQueueSize = 3;

public:
    Queue(sf::Vector2f firstBubblePos, float verticalSpacing); //need to be constants
    ~Queue();
    void render(sf::RenderTarget& target);
    vector <Animal*> getAnimalQueue();
    Animal* generateAnimal();
};

#endif //SHEEPFIGHT_QUEUE_H
