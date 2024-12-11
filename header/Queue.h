#ifndef SHEEPFIGHT_QUEUE_H
#define SHEEPFIGHT_QUEUE_H

#include "Animal.h"
class Player;

class Queue {
private:
    vector<sf::Texture> animalTextures;
    vector<Animal*> animalQueue;

    void initQueue(int playerNumber, Player* player);
    vector<sf::Sprite> queueSprites;
    vector<sf::Sprite> bubbleSprites;
    sf::Texture bubbleTexture;

    void initPositions(Player* player, int playerNumber);
    void initVariables();
    void generateAnimal(int player, int index);
    int getRandomAnimal();
    void setScale(int playerNumber);


public:
    Queue(int playerNumber, Player* player);
    ~Queue();
    void render(sf::RenderTarget& target);
    void update(int player);
    Animal* getFirstAnimal() {return animalQueue[0];}
};

#endif //SHEEPFIGHT_QUEUE_H