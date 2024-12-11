#include "Queue.h"
#include "Player.h"

Queue::Queue(int playerNumber, Player *player) {
    initVariables();
    initQueue(playerNumber, player);
};

void Queue::initVariables() {
    if (!bubbleTexture.loadFromFile("sprites/queue-bubble.png")) {
        std::cerr << "Error: Could not load bubble texture.\n";
        return;
    }

    for (int i = 0; i < queueSize; ++i) {
        this->animalQueue.push_back(new Animal());
        this->queueSprites.push_back(sf::Sprite());

        sf::Sprite bubbleSprite;
        bubbleSprite.setTexture(bubbleTexture);
        bubbleSprites.push_back(bubbleSprite);
    }
}


void Queue::setScale() {
    for (auto &sprite: queueSprites) {
        if (sprite.getTexture() != nullptr) {
            const sf::Vector2f textureSize(
                    sprite.getTexture()->getSize().x,
                    sprite.getTexture()->getSize().y
            );
            float scaleX = queueWidth / textureSize.x;
            float scaleY = queueHeight / textureSize.y;
            sprite.setScale(scaleX, scaleY);
        }
    }
    for (auto &bubble: bubbleSprites) {
        const sf::Vector2f bubbleTextureSize(
                bubbleTexture.getSize().x,
                bubbleTexture.getSize().y
        );
        float scaleX = (queueWidth + bubbleRadiusOffset) / bubbleTextureSize.x;
        float scaleY = (queueHeight + bubbleRadiusOffset) / bubbleTextureSize.y;
        bubble.setScale(scaleX, scaleY);
    }
}


void Queue::initPositions(Player *player) {
    for (size_t i = 0; i < this->queueSprites.size(); ++i) {
        float xPos = queueXpos + i * spaceBetweenQueueBubbles;
        float yPos = player->getQueueYpos();

        this->queueSprites[i].setPosition(xPos, yPos);

        this->bubbleSprites[i].setPosition(xPos, yPos);
    }
}


void Queue::initQueue(int playerNumber, Player *player) {
    animalTextures.resize(queueSize);
    for (int i = 0; i < queueSize; i++) {
        if (playerNumber == WHITE_PLAYER) {
            this->animalQueue[i] = new WhitePig();
        } else {
            this->animalQueue[i] = new BlackPig();
        }
        animalTextures[i] = animalQueue[i]->getQueueTexture();
        queueSprites[i].setTexture(animalTextures[i]);
    }
    setScale();
    initPositions(player);
}

int Queue::getRandomAnimal() {
    vector<int> animalPool;
    animalPool.insert(animalPool.end(), pigDisplayProbability, 0);
    animalPool.insert(animalPool.end(), goatDisplayProbability, 1);
    animalPool.insert(animalPool.end(), sheepDisplayProbability, 2);

    int randomIndex = rand() % animalPool.size();
    return animalPool[randomIndex];
}

void Queue::generateAnimal(int playerNumber, int index = 2) {
    int animalType = getRandomAnimal();
    if (playerNumber == WHITE_PLAYER) {
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
    if (playerNumber == BLACK_PLAYER) {
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

void Queue::update(int player) {

    this->animalQueue[0] = animalQueue[1];
    this->animalQueue[1] = animalQueue[2];


    generateAnimal(player, 2);


    for (size_t i = 0; i < this->queueSprites.size(); ++i) {

        animalTextures[i] = animalQueue[i]->getQueueTexture();
        queueSprites[i].setTexture(animalTextures[i]);

        if (queueSprites[i].getTexture() != nullptr) {
            const sf::Texture *texture = queueSprites[i].getTexture();
            sf::Vector2u textureSize = texture->getSize();


            queueSprites[i].setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));


            float scaleX = queueWidth / static_cast<float>(textureSize.x);
            float scaleY = queueHeight / static_cast<float>(textureSize.y);
            queueSprites[i].setScale(scaleX, scaleY);
        }


        float xPos = queueXpos + i * spaceBetweenQueueBubbles;
        float yPos = (player == WHITE_PLAYER) ? whitePlayerqueueYPos : blackPlayerqueueYPos;

        this->queueSprites[i].setPosition(xPos, yPos);
        this->bubbleSprites[i].setPosition(xPos, yPos);
    }
}


void Queue::render(sf::RenderTarget &target) {
    for (const auto &bubble: this->bubbleSprites) {
        target.draw(bubble);
    }

    for (const auto &sprite: this->queueSprites) {
        target.draw(sprite);
    }
}


Queue::~Queue() {
    for (auto &animal: this->animalQueue) {
        delete animal;
    }
};