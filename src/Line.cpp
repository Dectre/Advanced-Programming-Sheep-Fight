#include "Line.h"


void Line::update() {
    this->updateAnimalsCollision();
    this->moveAnimals();
    this->animalsAnimation();
}

void Line::sortTeams() {

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

void Line::handleSpeed() {
    int sumOfTeam1Speeds = 0;
    int sumOfTeam1Power = 0;
    int sumOfTeam2Power = 0;
    int sumOfTeam2Speeds = 0;
    for (Animal* animal : team1Animals)
        if (animal->getFightStatus()) {
            sumOfTeam1Speeds += animal->getDefaultSpeed() * RIGHT;
            sumOfTeam1Power += animal->getPower();
        }
    for (Animal* animal : team2Animals)
        if (animal->getFightStatus()) {
            sumOfTeam2Speeds += animal->getDefaultSpeed() * LEFT;
            sumOfTeam2Power += animal->getPower();
        }
    int fightSpeed = sumOfTeam1Speeds + sumOfTeam2Speeds;
    cout << fightSpeed << endl;
    Direction fightDirection =  sumOfTeam1Power > sumOfTeam2Power ? RIGHT : LEFT;
    fightSpeed = abs(fightSpeed);
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
            this->handleSpeed();
        }
    }
    for (Animal* animal : this->team2Animals) {
        if (checkAnimalCollision(animal) and !animal->getFightStatus()) {
            animal->animalIsFighting();
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