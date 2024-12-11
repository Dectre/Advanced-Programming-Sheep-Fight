#include "Queue.h"

Queue::Queue(int player) {
    initVariables();
    initQueue(player);
};

void Queue::initVariables() {
    for (int i = 0; i < queueSize ; i++){
        this->animalQueue.push_back(new Animal());
        this->queueSprites.push_back(*new sf::Sprite());

    }
}

void Queue::initPositions(int player){
    for (size_t i = 0; i < this->queueSprites.size(); ++i) {
        if (player == WHITE_PLAYER) {
            this->queueSprites[i].setPosition(queueXpos + i * spaceBetweenQueueBubbles, queueYPos);
        } else if (player == BLACK_PLAYER) {
            this->queueSprites[i].setPosition(queueXpos + i * spaceBetweenQueueBubbles, windowHeight - queueYPos);
        }
    }
}
void Queue::initQueue(int player) {
    animalTextures.resize(queueSize);
    generateAnimal(player, 0);
    generateAnimal(player, 1);
    generateAnimal(player, 2);
    initPositions(player);
}

int Queue::getRandomAnimal() {
    vector<int> animalPool;
    animalPool.insert(animalPool.end(), pigDisplayProbability, 0); // 5 WhitePigs
    animalPool.insert(animalPool.end(), goatDisplayProbability, 1); // 3 WhiteGoats
    animalPool.insert(animalPool.end(), sheepDisplayProbability, 2); // 2 WhiteSheep

    int randomIndex = rand() % animalPool.size();
    return animalPool[randomIndex];
}

void Queue::generateAnimal(int player, int index = 2) {
    int animalType = getRandomAnimal();
    if (player == WHITE_PLAYER) {
        switch (animalType) {
            case 0: {
                this->animalQueue[index] = new WhitePig();
                break;
            };
            case 1: {
                this->animalQueue[index] = new WhiteGoat();
                break;
            }
            case 2: {
                this->animalQueue[index] = new WhiteSheep();
                break;
            }
        }
    }
    if (player == BLACK_PLAYER) {
        switch (animalType) {
            case 0: {
                this->animalQueue[index] = new BlackPig();
                break;
            };
            case 1: {
                this->animalQueue[index] = new BlackGoat();
                break;
            }
            case 2: {
                this->animalQueue[index] = new BlackSheep();
                break;
            }
        }
    }
    animalTextures[index] = animalQueue[index]->getQueueTexture();
    queueSprites[index].setTexture(animalTextures[index]);
}

Animal* Queue::getFirstAnimal(){
    return animalQueue[0];
}

sf::Sprite* handleSprite(int player) {
    sf::Sprite* sprite = new sf::Sprite();
}

void Queue::update(int player){
    this->animalQueue[0] = animalQueue[1];
    this->animalQueue[1] = animalQueue[2];

    generateAnimal(player, 2);


    for (size_t i = 0; i < this->queueSprites.size(); ++i) {
        if (player == WHITE_PLAYER) {
            this->queueSprites[i].setPosition(queueXpos + i * spaceBetweenQueueBubbles, queueYPos);
        } else if (player == BLACK_PLAYER) {
            this->queueSprites[i].setPosition(queueXpos + i * spaceBetweenQueueBubbles, windowHeight - queueYPos);
        }
    }
}


void Queue::render(sf::RenderTarget& target) {
    for (auto sprite : this->queueSprites) {
        target.draw(sprite);
    }
}

Queue::~Queue() {
    for (auto& animal : this->animalQueue) {
        delete animal;
    }
};