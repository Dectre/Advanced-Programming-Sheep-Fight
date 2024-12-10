#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
#include "Player.h"
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

class Queue {
private:
    vector<Animal*> animalQueue;
    map<string, sf::Texture> animalTextures;
    sf::Sprite sprite;

    void initQueue(int player);
    Animal* generateAnimal(int player);
    vector<sf::Sprite> queueSprites;


public:
    Queue(int player);
    ~Queue();
    void render(sf::RenderTarget& target);
    void update(int player);
    Animal* getFirstAnimal();
};

#endif //SHEEPFIGHT_QUEUE_H