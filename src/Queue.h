#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Queue {
private:
    vector<Animal*> animalQueue;
    void initQueue();
    void initTexture();
    Animal* generateAnimal();
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Queue();
    ~Queue();
    void render(sf::RenderTarget& target);
    void update();
    Animal* getFirstAnimal();
};

#endif //SHEEPFIGHT_QUEUE_H
