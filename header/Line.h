#ifndef SHEEPFIGHT_LINE_H
#define SHEEPFIGHT_LINE_H

#include "Manual.h"
#include "Animal.h"

class Game;

class Line {
public:
    Line(Game* game);
    void addAnimalToTeam1(Animal* animal, int linePointer);
    void addAnimalToTeam2(Animal* animal, int linePointer);
    void moveAnimals();
    bool handleTeamCollision(vector<Animal*> animalsTeam, vector<Animal*> enemiesTeam, Animal* animal, size_t index);
    bool checkAnimalCollision(Animal* animal);
    bool checkTeamIntersect(vector<Animal*> animals, sf::FloatRect placementZone);
    bool canTeam1AddAnimal(int pointer);
    bool canTeam2AddAnimal(int pointer);
    void updateAnimalsCollision();
    void handleSpeed();
    int getTeamPower(vector<Animal*> animals);
    void team1EndLines();
    void team2EndLines();
    void checkReachingEndOfTheLine();
    void animalsAnimation();
    void update();
    void render(sf::RenderTarget& target);
private:
    Game* game;
    vector<Animal*> team1Animals;
    vector<Animal*> team2Animals;
};


#endif //SHEEPFIGHT_LINE_H
