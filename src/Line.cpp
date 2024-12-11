#include "Line.h"

void Line::update() {
    this->updateAnimalsCollision();
    this->moveAnimals();
    this->animalsAnimation();
}

void Line::addAnimalToTeam1(Animal* animal, int linePointer) {
    this->team1Animals.push_back(animal);
    float y = (lineRectY);
    for (int i = 0; i < linePointer; i++) {
        y += lineRectHeight + lineDistance[i];
    }
    animal->setPosition(playerOneStartPoint,y);
}

void Line::addAnimalToTeam2(Animal* animal, int linePointer) {
    this->team2Animals.push_back(animal);
    float y = (lineRectY);
    for (int i = 0; i < linePointer; i++) {
        y += lineRectHeight + lineDistance[i];
    }
    animal->setPosition(playerTwoStartPoint,y);
}

void Line::moveAnimals() {
    for (Animal* animal : team1Animals) {
        animal->move();
    }
    for (Animal* animal : team2Animals) {
        animal->move();
    }
}

void Line::animalsAnimation() {
    for (Animal* animal : this->team1Animals) {
        animal->update();
    }
    for (Animal* animal : this->team2Animals) {
        animal->update();

    }
}

bool Line::handleTeamCollision(vector<Animal*> animalsTeam, vector<Animal*> enemiesTeam, Animal* animal, size_t index) {
    sf::FloatRect animalBounds = animal->getBounds();
    if (!enemiesTeam.empty()) {
        sf::FloatRect enemiesTeamBounds = enemiesTeam[0]->getBounds();
        if (animalBounds.intersects(enemiesTeamBounds))

            return true;
    }
    if (animalsTeam.size() > 1 and index != 0) {
        sf::FloatRect animalsTeamBounds = animalsTeam[index - 1]->getBounds();
        if (animalBounds.intersects(animalsTeamBounds) && animalsTeam[index-1]->getFightStatus())
            return true;
    }
    return false;
}

bool Line::checkAnimalCollision(Animal* animal) {
    auto it1 = std::find(team1Animals.begin(), team1Animals.end(), animal);
    if (it1 != team1Animals.end()) {
        size_t index = distance(team1Animals.begin(), it1);
        return handleTeamCollision(team1Animals, team2Animals, animal, index);
    }
    auto it2 = std::find(team2Animals.begin(), team2Animals.end(), animal);
    if (it2 != team2Animals.end()) {
        size_t index = std::distance(team2Animals.begin(), it2);
        return handleTeamCollision(team2Animals, team1Animals, animal, index);
    }
}

int Line::getTeamPower(vector<Animal*> animals) {
    int sum = 0;
    for (Animal* animal : animals)
        if (animal->getFightStatus()) {
            sum += animal->getPower();
        }
    return sum;
}
void Line::handleSpeed() {
    int team1Power = getTeamPower(team1Animals);
    int team2Power = getTeamPower(team2Animals);
    Direction fightDirection =  team1Power > team2Power ? RIGHT : LEFT;
    int fightSpeed = abs(team1Power - team2Power) * defaultSpeed;
    for (Animal* animal : team1Animals)
        if (animal->getFightStatus()) {
            animal->setSpeed(fightSpeed);
            animal->changeDirection(fightDirection);
        }
    for (Animal* animal : team2Animals)
        if (animal->getFightStatus()) {
            animal->setSpeed(fightSpeed);
            animal->changeDirection(fightDirection);
        }
}
void Line::updateAnimalsCollision(){
    for (Animal* animal : this->team1Animals) {
        if(checkAnimalCollision(animal) and !animal->getFightStatus()) {
            animal->animalIsFighting();
            animal->changeTexture();
            this->handleSpeed();
        }
    }
    for (Animal* animal : this->team2Animals) {
        if (checkAnimalCollision(animal) and !animal->getFightStatus()) {
            animal->animalIsFighting();
            animal->changeTexture();
            this->handleSpeed();
        }
    }
}


void Line::render(sf::RenderTarget& target) {
    for (Animal* animal : this->team1Animals)
        animal->render(target);
    for (Animal* animal : this->team2Animals)
        animal->render(target);
}

