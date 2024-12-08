#ifndef SHEEPFIGHT_LINE_H
#define SHEEPFIGHT_LINE_H

#include "Manual.h"
#include "Animal.h"

class Line {
public:
    void addAnimalToTeam1(Animal* animal) { this->team1Animals.push_back(animal); }
    void addAnimalToTeam2(Animal* animal) { this->team2Animals.push_back(animal); }
    void moveAnimals();
    bool checkAnimalCollision(Animal* animal);
    bool checkFrontAnimals();
    void comparePower();
    void incTeam1Power(int pow) { this->team1Power += pow; }
    void incTeam2Power(int pow) { this->team2Power += pow; }
    void handleSpeed();
    void handleFight();
    int getTeam1Power();
    int getTeam2Power();
    void checkReachingEndOfTheLine();
    void animalsAnimation();
    void update();
    void render(sf::RenderTarget& target);
private:
    map<string, float> position;
    vector<Animal*> team1Animals;
    vector<Animal*> team2Animals;
    int team1Power;
    int team2Power;
};


#endif //SHEEPFIGHT_LINE_H
