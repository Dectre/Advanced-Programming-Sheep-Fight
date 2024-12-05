#ifndef SHEEPFIGHT_GAME_H
#define SHEEPFIGHT_GAME_H

#include "Manual.h"

class Game {
public:
    Game();
    ~Game();

    void run();
    void render();
    void updatePollEvents();
private:
    sf::RenderWindow* window;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    void initWindow();
    void initBackgroundTexture();
    void initBackgroundSprite();
};


#endif //SHEEPFIGHT_GAME_H
