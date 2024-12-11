#ifndef SHEEPFIGHT_LINE_H
#define SHEEPFIGHT_LINE_H

#include "Manual.h"
#include "Animal.h"

class Line {
public:
    void addAnimalToTeam1(Animal* animal, int linePointer);
    void addAnimalToTeam2(Animal* animal, int linePointer);
    void moveAnimals();
    void sortTeams();
    bool handleTeamCollision(vector<Animal*> animalsTeam, vector<Animal*> enemiesTeam, Animal* animal, size_t index);
    bool checkAnimalCollision(Animal* animal);
    void setPosition(int pointer);
    bool checkFrontAnimals();
    void updateAnimalsCollision();
    void handleSpeed();
    void handleFight();
    int getTeamPower(vector<Animal*> animals);
    void checkReachingEndOfTheLine();
    void animalsAnimation();
    void update();
    void render(sf::RenderTarget& target);
private:
    vector<Animal*> team1Animals;
    vector<Animal*> team2Animals;
};


#endif //SHEEPFIGHT_LINE_H
