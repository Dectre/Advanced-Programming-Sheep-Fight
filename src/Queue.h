#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"

class Queue {
private:
    vector<sf::Texture> animalTextures;
    vector<Animal*> animalQueue;

    void initQueue(int player);
    vector<sf::Sprite> queueSprites;
    vector<sf::Sprite> bubbleSprites;
    sf::Texture bubbleTexture;

    void initPositions(int player);
    void initVariables();
    void generateAnimal(int player, int index);
    sf::Sprite* handleSprite(int player);
    int getRandomAnimal();
    void setScale();


public:
    Queue(int player);
    ~Queue();
    void render(sf::RenderTarget& target);
    void update(int player);
    Animal* getFirstAnimal() {return animalQueue[0];}
};

#endif //SHEEPFIGHT_QUEUE_H