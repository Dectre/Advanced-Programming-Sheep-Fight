#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Queue {
private:
    vector<Animal*> animalQueue;
    vector <sf::Texture> animalTextures;
    void initQueue(int player);
    void initTexture();
    Animal* generateAnimal(int player);
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Queue();
    ~Queue();
    void render(sf::RenderTarget& target);
    void update();
    int player;
    Animal* getFirstAnimal();


};

#endif //SHEEPFIGHT_QUEUE_H