#include "Line.h"

void Line::moveAnimals() {
    for (Animal* animal : team1Animals) {
        if (!checkAnimalCollision(animal))
            animal->move();
    }
}

bool Line::checkAnimalCollision(Animal* animal) {
    sf::FloatRect animalBounds = animal->getBounds();
    // White Sheep Only
    for (Animal* blackAnimal : this->team2Animals) {
        sf::FloatRect blackAnimalBounds = blackAnimal->getBounds();
        if (animalBounds.intersects(blackAnimalBounds))
            return true;
    }
    return false;
}

void Line::update() {

}

void Line::render(sf::RenderTarget& target) {
    for (Animal* animal : this->team1Animals) {
        animal->render(target);
    }
}