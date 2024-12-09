#include "Animal.h"

void Animal::move() {
    this->sprite.move(this->speed * this->direction,0);
}

void Animal::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Animal::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}

void Animal::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Animal::initSprite() {
    this->sprite.setTexture(this->moveTexture);
    this->sprite.setTextureRect(handleAnimation());
}

void Animal::update() {
    this->sprite.setTextureRect(handleAnimation());
}

sf::IntRect Animal::handleAnimation() {
    const sf::Vector2u textureSize = this->moveTexture.getSize();
    int eachAnimationSize = textureSize.x / this->numOfAnimations;
    sf::Time animationTimeElapsed = animationClock.getElapsedTime();
    if (animationTimeElapsed.asMilliseconds() >= 100) {
        animationClock.restart();
        currentAnimationCoefficient = (currentAnimationCoefficient + 1) % numOfAnimations;
    }
    sf::IntRect rect;
    rect.left = eachAnimationSize * currentAnimationCoefficient;
    rect.width = eachAnimationSize;
    rect.height = textureSize.y;
    return rect;
}

WhitePig::WhitePig() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->sprite.setScale(-1.f,1.f);
    this->sprite.setScale(-50/49, 50/49);
}

void WhitePig::initVariables() {
    this->speed = pigSpeed;
    this->direction = RIGHT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
    this->numOfAnimations = numOfWhitePigMovingAnimations;

}

void WhitePig::initTexture() {
    if (!this -> moveTexture.loadFromFile(WHITE_PIG_MOVE))
        cerr << "Could not load White Pig moving texture";
    if (!this -> standTexture.loadFromFile(WHITE_PIG_STAND))
        cerr << "Could not load White Pig standing texture";
    /*if (!this -> queueTexture.loadFromFile(WHITE_PIG_QUEUE))
        cerr << "Could not load White Pig standing texture";*/
}


void WhiteGoat::initVariables() {
    this->speed = goatSpeed;
    this->direction = RIGHT;
    this->power = goatPower;
    this->damage = goatDamage;
    this->displayProbability = goatDisplayProbability;
}

void WhiteSheep::initVariables() {
    this->speed = sheepSpeed;
    this->direction = RIGHT;
    this->power = sheepPower;
    this->damage = sheepDamage;
    this->displayProbability = sheepDisplayProbability;
}

BlackPig::BlackPig() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->sprite.setPosition(1080,0);

}

void BlackPig::initVariables() {
    this->speed = pigSpeed;
    this->direction = LEFT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
    this->numOfAnimations = numOfBlackPigMovingAnimations;
}

void BlackPig::initTexture() {
    if (!this -> moveTexture.loadFromFile(BLACK_PIG_MOVE))
        cerr << "Could not load Black Pig moving texture";
    if (!this -> standTexture.loadFromFile(BLACK_PIG_STAND))
        cerr << "Could not load Black Pig standing texture";

}

void BlackGoat::initVariables() {
    this->speed = goatSpeed;
    this->direction = LEFT;
    this->power = goatPower;
    this->damage = goatDamage;
    this->displayProbability = goatDisplayProbability;
}

void BlackSheep::initVariables() {
    this->speed = sheepSpeed;
    this->direction = LEFT;
    this->power = sheepPower;
    this->damage = sheepDamage;
    this->displayProbability = sheepDisplayProbability;
}