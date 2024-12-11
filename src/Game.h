#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H
#include "Player.h"
#include "Health.h"
#include "Indicator.h"
#include "Queue.h"
#include "Line.h"


class Game {
private:

    sf::RenderWindow* window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    Player* playerOne;
    Player* playerTwo;

    Queue* playerOneQueue;
    Queue* playerTwoQueue;
    Indicator* testInd1;
    Indicator* testInd2;
    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
    void initLines();
    void initQueues();
    void updatePollEvents();
    void updateInput(sf::Event event);
    void update();

public:
    Game();
    ~Game();

    void run();
    void render();
};

#endif //SHEEPFIGHT_GAME_H

#include "Queue.h"


