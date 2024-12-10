#include "Queue.h"

Queue::Queue() {
    initQueue();
    //initTexture();
    //initSprite();
};
void Queue::initQueue(int player){
    for (int i=0;i<queueSize;i++){
        this->animalQueue.push_back(generateAnimal(player));}

};

void Queue::initTexture(){
    for (auto& animal : this->animalQueue) {
        if ()
            cerr << "Could not load White Pig moving texture";
    }
};

Queue::~Queue() {
    for (auto& animal : this->animalQueue) {
        delete animal;
    }
};



Animal* Queue::generateAnimal(int player) {
    vector<int> animalPool;
    animalPool.insert(animalPool.end(), pigDisplayProbability, 0); // 5 WhitePigs
    animalPool.insert(animalPool.end(), goatDisplayProbability, 1); // 3 WhiteGoats
    animalPool.insert(animalPool.end(), sheepDisplayProbability, 2); // 2 WhiteSheep

    int randomIndex = rand() % animalPool.size();
    int animalType = animalPool[randomIndex];
if (player==1){
    switch (animalType) {
        case 0: return new WhitePig();
            case 1: return new WhiteGoat();
            case 2: return new WhiteSheep();
        default: return nullptr;
    }}
if (player==2){
    switch (animalType) {
        case 0: return new BlackPig();
        case 1: return new BlackGoat();
        case 2: return new BlackSheep();
        default: return nullptr;
    }}
};

Animal* Queue::getFirstAnimal(){
    return animalQueue[0];
}
void Queue::update(){
    animalQueue.insert(animalQueue.begin(), generateAnimal());
    animalQueue.pop_back();
}
