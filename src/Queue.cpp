#include "Queue.h"

Queue::Queue(sf::Vector2f firstBubblePos, float verticalSpacing) {
    srand(static_cast<unsigned>(time(nullptr)));

    for (size_t i = 0; i < maxQueueSize; ++i) {
        bubblePositions[i] = sf::Vector2f(firstBubblePos.x, firstBubblePos.y + i * verticalSpacing);
    }

    for (size_t i = 0; i < maxQueueSize; ++i) {
        this->animalQueue.push_back(this->generateAnimal());
    }
};

Queue::~Queue() {
    for (auto& animal : this->animalQueue) {
        delete animal;
    }
};



Animal* Queue::generateAnimal() {
    vector<int> animalPool;
    animalPool.insert(animalPool.end(), 5, 0); // 5 WhitePigs
    animalPool.insert(animalPool.end(), 3, 1); // 3 WhiteGoats
    animalPool.insert(animalPool.end(), 2, 2); // 2 WhiteSheep

    int randomIndex = rand() % animalPool.size();
    int animalType = animalPool[randomIndex];

    switch (animalType) {
        case 0: return new WhitePig();
        case 1: return new WhiteGoat();
        case 2: return new WhiteSheep();
        default: return nullptr;
    }
};

vector <Animal*> Queue::getAnimalQueue(){
    return animalQueue;
}

