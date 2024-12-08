#ifndef SHEEPFIGHT_ANIMAL_H
#define SHEEPFIGHT_ANIMAL_H

#include "Manual.h"

class Animal {
public:
    int getPower() { return this->power; }
    int getDamage() { return this->damage; }
    float getDisplayProbability() { return this->displayProbability; };
    sf::FloatRect getBounds() { return this->sprite.getGlobalBounds(); }
    void changeDirection(Direction newDirection) { this->direction = newDirection; }
    void move();
    void setScale(const float xScale, const float yScale);
    void initSprite();
    void render(sf::RenderTarget& target);
    sf::IntRect handleAnimation();
    void setPosition(const float x, const float y);
    void animalIsFighting() { this-> isFighting = true; }
    void update();
protected:
    sf::Clock animationClock;
    int numOfAnimations;
    int currentAnimationCoefficient;
    sf::Sprite sprite;
    sf::Texture standTexture;
    sf::Texture moveTexture;
    float speed;
    Direction direction;
    int power;
    int damage;
    float displayProbability;
    bool isFighting = false;
};

class WhitePig : public Animal {
public:
    WhitePig();
private:
    void initVariables();
    void initTexture();
};

class WhiteGoat : public Animal {
public:
    WhiteGoat();
private:
    void initVariables();
    void initTexture();
};

class WhiteSheep : public Animal {
public:
    WhiteSheep();
private:
    void initVariables();
    void initTexture();
};

class BlackPig : public Animal {
public:
    BlackPig();
private:
    void initVariables();
    void initTexture();
};

class BlackGoat : public Animal {
public:
    BlackGoat();
private:
    void initVariables();
    void initTexture();
};

class BlackSheep : public Animal {
public:
    BlackSheep();
private:
    void initVariables();
    void initTexture();
};


#endif //SHEEPFIGHT_ANIMAL_H
