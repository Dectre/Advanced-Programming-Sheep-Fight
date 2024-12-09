#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H

#include "Health.h"
#include "Player.h"
#include "Queue.h"

#include "Line.h"


class Game {
private:

    sf::RenderWindow* window;
    Health* leftPlayerHealth;  // Health bar for left player.
    Health* rightPlayerHealth; // Health bar for right player.
    Player leftPlayer;
    Player rightPlayer;
    sf::RectangleShape lineRect;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Queue* leftPlayerQueue;  // Queue for Player 1
    Queue* rightPlayerQueue; // Queue for Player 2

    vector<Line*> lines;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
    void initLines();
    void initHealthBars();
    void initQueues();
    void updatePollEvents();
    void update();

public:
    Game();
    ~Game();

    void run();
    void render();
};

#endif //SHEEPFIGHT_GAME_H

#include "Queue.h"


