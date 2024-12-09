#include "Queue.h"

Queue::Queue() {
    initQueue();
    //initTexture();
    //initSprite();
};
void Queue::initQueue(){
    for (int i=0;i<queueSize;i++){
        this->animalQueue.push_back(generateAnimal());}

};

void Queue::initTexture(){

};

Queue::~Queue() {
    for (auto& animal : this->animalQueue) {
        delete animal;
    }
};



Animal* Queue::generateAnimal() {
    vector<int> animalPool;
    animalPool.insert(animalPool.end(), pigDisplayProbability, 0); // 5 WhitePigs
    animalPool.insert(animalPool.end(), goatDisplayProbability, 1); // 3 WhiteGoats
    animalPool.insert(animalPool.end(), sheepDisplayProbability, 2); // 2 WhiteSheep

    int randomIndex = rand() % animalPool.size();
    int animalType = animalPool[randomIndex];

    switch (animalType) {
        case 0: return new WhitePig();
        //case 1: return new WhiteGoat();
        //case 2: return new WhiteSheep();
        default: return nullptr;
    }
};

Animal* Queue::getFirstAnimal(){
    return animalQueue[0];
}
void Queue::update(){
        animalQueue.insert(animalQueue.begin(), generateAnimal());
        animalQueue.pop_back();
}
