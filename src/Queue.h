#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
#include "Player.h"

class Queue {
private:
    vector<sf::Texture> animalTextures;
    vector<Animal*> animalQueue;
    vector<sf::Sprite> queueSprites;

    void initPositions(int player);
    void initVariables();
    void initQueue(int player);
    void generateAnimal(int player, int index);
    sf::Sprite* handleSprite(int player);
    int getRandomAnimal();
    void setScale();
    vector<sf::Sprite> bubbleSprites;
    sf::Texture bubbleTexture;

public:
    Queue(int player);
    ~Queue();
    void render(sf::RenderTarget& target);
    void update(int player);
    Animal* getFirstAnimal();
};

#endif //SHEEPFIGHT_QUEUE_H