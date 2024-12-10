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
    Health* playerOneHealth;  // Health bar for left player.
    Health* playerTwoHealth; // Health bar for right player.
    Player* playerOne;
    Player* playerTwo;
    sf::RectangleShape lineRect;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Queue* playerOneQueue;
    Queue* playerTwoQueue;
    Indicator* testInd;
    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
    void initLines();
    void initHealthBars();
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


