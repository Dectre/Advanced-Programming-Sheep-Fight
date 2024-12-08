#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H

#include "Health.h"
#include "Player.h"


class Game {
private:
    sf::RenderWindow* window;
    Health* leftPlayerHealth;  // Health bar for left player.
    Health* rightPlayerHealth; // Health bar for right player.
    //Player leftPlayer;
    //Player rightPlayer;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
    void initHealthBars();

    void updatePollEvents();
    void updateHealthBars();

public:
    Game();
    ~Game();

    void run();
    void render();
};

#endif //SHEEPFIGHT_GAME_H
