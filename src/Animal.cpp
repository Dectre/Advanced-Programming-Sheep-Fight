#include "Animal.h"

void Animal::move() {
    this->sprite.move(this->speed * this->direction,0);
}

void Animal::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Animal::setScale(PixelSize animalWidth, PixelSize animalHeight, int mirror) {
    const sf::Vector2f spriteSize(
            sprite.getTexture()->getSize().x * sprite.getScale().x / this->numOfAnimations,
            sprite.getTexture()->getSize().y * sprite.getScale().y);
    this->sprite.setScale(mirror * animalWidth / spriteSize.x , animalHeight / spriteSize.y);
}

void Animal::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Animal::initSprite() {
    this->defaultTexture = moveTexture;
    this->sprite.setTexture(this->moveTexture);
    this->sprite.setTextureRect(handleAnimation());
}

void Animal::changeTexture() {
    this->defaultTexture = standTexture;
    this->numOfAnimations = numOfStandingAnimations;
    this->sprite.setTexture(this->standTexture);
    this->sprite.setTextureRect(handleAnimation());
}

void Animal::update() {
    this->sprite.setTextureRect(handleAnimation());
}

sf::IntRect Animal::handleAnimation() {
    const sf::Vector2u textureSize = this->defaultTexture.getSize();
    int eachAnimationSize = textureSize.x / this->numOfAnimations;
    sf::Time animationTimeElapsed = animationClock.getElapsedTime();
    if (animationTimeElapsed.asMilliseconds() >= this->animationTime) {
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
    this->setScale(pigWidth, pigHeight, -1);
}

void WhitePig::initVariables() {
    this->speed = defaultSpeed;
    this->direction = RIGHT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
    this->numOfAnimations = numOfWhitePigMovingAnimations;
    this->numOfStandingAnimations = numOfWhitePigStandingAnimations;
    this->animationTime = whitePigAnimationTime;

}

void WhitePig::initTexture() {
    if (!this -> moveTexture.loadFromFile(WHITE_PIG_MOVE))
        cerr << "Could not load White Pig moving texture";
    if (!this -> standTexture.loadFromFile(WHITE_PIG_STAND))
        cerr << "Could not load White Pig standing texture";
    if (!this -> queueTexture.loadFromFile(WHITE_PIG_QUEUE))
        cerr << "Could not load White Pig queue texture";
}

WhiteGoat::WhiteGoat() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->setScale(goatWidth, goatHeight, -1);

}

void WhiteGoat::initVariables() {
    this->speed = defaultSpeed;
    this->direction = RIGHT;
    this->power = goatPower;
    this->damage = goatDamage;
    this->displayProbability = goatDisplayProbability;
    this-> numOfAnimations = numOfWhiteGoatMovingAnimations;
    this->numOfStandingAnimations = numOfWhiteGoatStandingAnimations;
    this->animationTime = whiteGoatAnimationTime;
}

void WhiteGoat::initTexture() {
    if (!this -> moveTexture.loadFromFile(WHITE_GOAT_MOVE))
        cerr << "Could not load White Goat moving texture";
    if (!this -> standTexture.loadFromFile(WHITE_GOAT_STAND))
        cerr << "Could not load White Goat standing texture";
    if (!this -> queueTexture.loadFromFile(WHITE_GOAT_QUEUE))
        cerr << "Could not load White Goat queue texture";
}

WhiteSheep::WhiteSheep() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->setScale(sheepWidth, sheepHeight, -1);

}

void WhiteSheep::initVariables() {
    this->speed = defaultSpeed;
    this->direction = RIGHT;
    this->power = sheepPower;
    this->damage = sheepDamage;
    this->displayProbability = sheepDisplayProbability;
    this-> numOfAnimations = numOfWhiteSheepMovingAnimations;
    this->numOfStandingAnimations = numOfWhiteSheepStandingAnimations;
    this->animationTime = whiteSheepAnimationTime;
}

void WhiteSheep::initTexture() {
    if (!this -> moveTexture.loadFromFile(WHITE_SHEEP_MOVE))
        cerr << "Could not load White Sheep moving texture";
    if (!this -> standTexture.loadFromFile(WHITE_SHEEP_STAND))
        cerr << "Could not load White Sheep standing texture";
    if (!this -> queueTexture.loadFromFile(WHITE_SHEEP_QUEUE))
        cerr << "Could not load White Sheep queue texture";
}

BlackPig::BlackPig() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->setScale(pigWidth, pigHeight, 1);
    this->sprite.setPosition(1080,0);
}

void BlackPig::initVariables() {
    this->speed = defaultSpeed;
    this->direction = LEFT;
    this->power = pigPower;
    this->damage = pigDamage;
    this->displayProbability = pigDisplayProbability;
    this->numOfAnimations = numOfBlackPigMovingAnimations;
    this->numOfStandingAnimations = numOfBlackPigStandingAnimations;
    this->animationTime = blackPigAnimationTime;
}

void BlackPig::initTexture() {
    if (!this -> moveTexture.loadFromFile(BLACK_PIG_MOVE))
        cerr << "Could not load Black Pig moving texture";
    if (!this -> standTexture.loadFromFile(BLACK_PIG_STAND))
        cerr << "Could not load Black Pig standing texture";
    if (!this -> queueTexture.loadFromFile(BLACK_PIG_QUEUE))
        cerr << "Could not load Black Pig queue texture";

}

BlackGoat::BlackGoat() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->setScale(goatWidth, goatHeight, 1);
    this->sprite.setPosition(1080,0);
}

void BlackGoat::initVariables() {
    this->speed = defaultSpeed;
    this->direction = LEFT;
    this->power = goatPower;
    this->damage = goatDamage;
    this->displayProbability = goatDisplayProbability;
    this-> numOfAnimations = numOfBlackGoatMovingAnimations;
    this->numOfStandingAnimations = numOfBlackGoatStandingAnimations;
    this->animationTime = blackGoatAnimationTime;
}

void BlackGoat::initTexture() {
    if (!this -> moveTexture.loadFromFile(BLACK_GOAT_MOVE))
        cerr << "Could not load Black Goat moving texture";
    if (!this -> standTexture.loadFromFile(BLACK_GOAT_STAND))
        cerr << "Could not load Black Goat standing texture";
    if (!this -> queueTexture.loadFromFile(BLACK_GOAT_QUEUE))
        cerr << "Could not load Black Goat queue texture";
}

BlackSheep::BlackSheep() : Animal() {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->setScale(sheepWidth, sheepHeight, 1);
}

void BlackSheep::initVariables() {
    this->speed = defaultSpeed;
    this->direction = LEFT;
    this->power = sheepPower;
    this->damage = sheepDamage;
    this->displayProbability = sheepDisplayProbability;
    this-> numOfAnimations = numOfBlackSheepMovingAnimations;
    this->numOfStandingAnimations = numOfBlackSheepStandingAnimations;
    this->animationTime = blackSheepAnimationTime;
    this->sprite.setPosition(1080,0);
}

void BlackSheep::initTexture() {
    if (!this -> moveTexture.loadFromFile(BLACK_SHEEP_MOVE))
        cerr << "Could not load Black Sheep moving texture";
    if (!this -> standTexture.loadFromFile(BLACK_SHEEP_STAND))
        cerr << "Could not load Black Sheep standing texture";
    if (!this -> queueTexture.loadFromFile(BLACK_SHEEP_QUEUE))
        cerr << "Could not load Black Sheep queue texture";
}