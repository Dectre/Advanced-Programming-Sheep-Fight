#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H

#include "Health.h"
#include "Player.h"
#include "Queue.h"

#include "Line.h"


class Game {
private:
    sf::RenderWindow* window;
    Health* playerOneHealth;  // Health bar for left player.
    Health* playerTwoHealth; // Health bar for right player.
    Player playerOne;
    Player playerTwo;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Queue* playerOneQueue;
    Queue* playerTwoQueue;

    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
    void initLines();
    void initHealthBars();
    void initQueues();
    void updatePollEvents();
    void updateInput();
    void update();

public:
    Game();
    ~Game();

    void run();
    void render();
};

#endif //SHEEPFIGHT_GAME_H

#include "Queue.h"


