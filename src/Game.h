#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H
#include "Player.h"
#include "Queue.h"
#include "Line.h"


class Game {
private:

    sf::RenderWindow* window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Clock playerOneCooldownClock;
    sf::Clock playerTwoCooldownClock;

    Player* playerOne;
    Player* playerTwo;

    Queue* playerOneQueue;
    Queue* playerTwoQueue;

    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();

    void initLines();
    void initQueues();
    void updatePollEvents();
    void updateInput(sf::Event event);
    void update();
    void movePlayerIndicator(Player* player, Direction dir);

public:
    Game();
    ~Game();

    void run();
    void render();
};

#endif //SHEEPFIGHT_GAME_H

