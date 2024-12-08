#include "Animal.h"

void Animal::move() {
    this->sprite.move(this->speed * this->direction,0);
}

void Animal::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Animal::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}

void Animal::initSprite() {
    this->sprite.setTexture(moveTexture);
}

WhitePig::WhitePig() : Animal() {
    this->initVariables();
    this->initSprite();
    this->initTexture();
}

void WhitePig::initVariables() {
    this->speed = pigSpeed;
    this->direction = RIGHT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
}

void WhitePig::initTexture() {
    if (!this -> moveTexture.loadFromFile(WHITE_PIG_MOVE))
        cerr << "Could not load White Pig moving texture";
    if (!this -> standTexture.loadFromFile(WHITE_PIG_STAND))
        cerr << "Could not load White Pig standing texture";
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

void BlackPig::initVariables() {
    this->speed = pigSpeed;
    this->direction = LEFT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
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
