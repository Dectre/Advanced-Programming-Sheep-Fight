#include "Line.h"


void Line::update() {
    this->moveAnimals();
    this->animalsAnimation();
}

void Line::moveAnimals() {
    for (Animal* animal : team1Animals) {
        if (!checkAnimalCollision(animal))
            animal->move();
    }
    for (Animal* animal : team2Animals) {
        if (!checkAnimalCollision(animal))
            animal->move();
    }
}
void Line::animalsAnimation() {
    for (Animal* animal : team1Animals) {
        animal->update();
    }
    for (Animal* animal : team2Animals) {
        animal->update();
    }
}

bool Line::checkAnimalCollision(Animal* animal) {
    /*sf::FloatRect animalBounds = animal->getBounds();
    // White Sheep Only
    for (Animal* blackAnimal : this->team2Animals) {
        sf::FloatRect blackAnimalBounds = blackAnimal->getBounds();
        if (animalBounds.intersects(blackAnimalBounds))
            return true;
    }
    return false;*/
    return false;
}

void Line::render(sf::RenderTarget& target) {
    for (Animal* animal : this->team1Animals)
        animal->render(target);
    for (Animal* animal : this->team2Animals)
        animal->render(target);
}