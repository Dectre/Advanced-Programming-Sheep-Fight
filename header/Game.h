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
    void initEndGameTexts();
    void initLines();
    void initMusic();

    void updatePollEvents();
    void updateInput(sf::Event event);
    void update();
    void movePlayerIndicator(Player* player, Direction dir);


public:
    Game();
    ~Game();

    sf::Font font;
    bool player1WonGame;
    bool player2WonGame;

    sf::Music gameMusic;

    sf::Text player1WinMessage;
    sf::Text player2WinMessage;

    void run();
    void render();
    void reduceHealthFromPlayer1(int damage) { this->playerOne->reduceHealth(damage); }
    void reduceHealthFromPlayer2(int damage) { this->playerTwo->reduceHealth(damage); }
};

#endif //SHEEPFIGHT_GAME_H

