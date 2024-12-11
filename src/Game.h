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

    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();

    void initLines();

    void updatePollEvents();
    void updateInput(sf::Event event);
    void update();
    void movePlayerIndicator(Player* player, Direction dir);
    void CheckWin();

public:
    Game();
    ~Game();


    void run();
    void render();
    void reduceHealthFromPlayer1(int damage) { this->playerOne->reduceHealth(damage); }
    void reduceHealthFromPlayer2(int damage) { this->playerTwo->reduceHealth(damage); }
};

#endif //SHEEPFIGHT_GAME_H

