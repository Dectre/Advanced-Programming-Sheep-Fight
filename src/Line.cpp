#include "Line.h"
#include "Game.h"

Line::Line(Game* g) {
    this->game = g;
};

void Line::update() {
    this->updateAnimalsCollision();
    this->moveAnimals();
    this->animalsAnimation();
    this->checkReachingEndOfTheLine();
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

bool Line::checkTeamIntersect(vector<Animal*> animals, sf::FloatRect placementZone) {
    for (Animal* animal : animals) {
        if (placementZone.intersects(animal->getBounds())) {
            return false;
        }
    }
}

bool Line::canTeam1AddAnimal(int linePointer) {
    float y = lineRectY;
    for (int i = 0; i < linePointer; i++) {
        y += lineRectHeight + lineDistance[i];
    }
    sf::FloatRect placementZone(playerOneStartPoint, y, pigWidth, pigHeight);
    checkTeamIntersect(team1Animals, placementZone);
    checkTeamIntersect(team2Animals, placementZone);
    return true;
}

bool Line::canTeam2AddAnimal(int linePointer) {
    float y = lineRectY;
    for (int i = 0; i < linePointer; i++) {
        y += lineRectHeight + lineDistance[i];
    }
    sf::FloatRect placementZone(playerTwoStartPoint, y,pigWidth, pigHeight);
    for (Animal* animal : team2Animals) {
        if (placementZone.intersects(animal->getBounds())) {
            return false;
        }
    }
    return true;
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
    float fightSpeed = abs(team1Power - team2Power) * pushSpeed;
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

void Line::team1EndLines() {
    for (int i = 0 ; i < this->team1Animals.size(); i++) {
        if (this->team1Animals[i]->getPosition().x < playerOneStartPoint) {
            delete this->team1Animals[i];
            this->team1Animals.erase(this->team1Animals.begin() + i);
        }
        if (this->team1Animals[i]->getPosition().x > playerTwoStartPoint) {
            this->game->reduceHealthFromPlayer2(this->team1Animals[i]->getDamage());
            delete this->team1Animals[i];
            this->team1Animals.erase(this->team1Animals.begin() + i);
        }
    }
}
void Line::team2EndLines() {
    for (int i = 0 ; i < this->team2Animals.size(); i++){
        if (this->team2Animals[i]->getPosition().x > playerTwoStartPoint){
            delete this->team2Animals[i];
            this->team2Animals.erase(this->team2Animals.begin() + i);
        }
        if (this->team2Animals[i]->getPosition().x < playerOneStartPoint){
            this->game->reduceHealthFromPlayer1(this->team2Animals[i]->getDamage());
            delete this->team2Animals[i];
            this->team2Animals.erase(this->team2Animals.begin() + i);
        }
    }
}
void Line::checkReachingEndOfTheLine(){
    team1EndLines();
    team2EndLines();
}

void Line::render(sf::RenderTarget& target) {
    for (Animal* animal : this->team1Animals)
        animal->render(target);
    for (Animal* animal : this->team2Animals)
        animal->render(target);
}

