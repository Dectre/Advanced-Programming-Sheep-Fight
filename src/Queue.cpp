#include "Queue.h"

Queue::Queue(int player) {
    initQueue(player);
};
void Queue::initQueue(int player){
    for (int i = 0; i < queueSize; i++) {
        Animal* animal = generateAnimal(player);
        this->animalQueue.push_back(animal);

        sf::Sprite sprite;
        sprite.setTexture(animal->getQueueTexture());
        if (player==1){
            sprite.setPosition(queueXpos+i*spaceBetweenQueueBubbles, queueYPos);}
        if (player==2){
            sprite.setPosition(queueXpos+i*spaceBetweenQueueBubbles, windowHeight-queueYPos);
        }

        this->queueSprites.push_back(sprite);
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
    Animal* newAnimal = nullptr;
    if (player==1){
        switch (animalType) {
            case 0: { newAnimal =  new WhitePig(); break;};
            case 1: {newAnimal=new WhiteGoat(); break;}
            case 2: {newAnimal=new WhiteSheep(); break;}
            default: return nullptr;
        }}
    if (player==2){
        switch (animalType) {
            case 0: { newAnimal = new BlackPig(); break;};
            case 1: {newAnimal=new BlackGoat(); break;}
            case 2: {newAnimal=new BlackSheep(); break;}
            default: return nullptr;    }}
    if (newAnimal) {
        string textureKey = string(player == 1 ? "White" : "Black") + (animalType == 0 ? "Pig" : animalType == 1 ? "Goat" : "Sheep");
        newAnimal->setTexture(animalTextures[textureKey]);
    }
    return newAnimal;
};

Animal* Queue::getFirstAnimal(){
    return animalQueue[0];
}
void Queue::update(int player){
    delete this->animalQueue.back();
    this->animalQueue.pop_back();
    this->queueSprites.pop_back();

    Animal* newAnimal = generateAnimal(player);
    this->animalQueue.insert(this->animalQueue.begin(), newAnimal);

    sf::Sprite newSprite;
    newSprite.setTexture(newAnimal->getQueueTexture());
    newSprite.setPosition(30, 20);

    this->queueSprites.insert(this->queueSprites.begin(), newSprite);
    if (player==1){
        for (size_t i = 0; i < this->queueSprites.size(); ++i) {
            this->queueSprites[i].setPosition(queueXpos+i*spaceBetweenQueueBubbles, queueYPos);
        }
    }
    if (player==2){
        for (size_t i = 0; i < this->queueSprites.size(); ++i) {
            this->queueSprites[i].setPosition(queueXpos+i*spaceBetweenQueueBubbles, windowHeight-queueYPos);
        }
    }


}

void Queue::render(sf::RenderTarget& target) {
    for (auto& sprite : this->queueSprites) {
        target.draw(sprite);
    }
}