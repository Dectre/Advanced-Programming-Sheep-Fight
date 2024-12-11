#ifndef SHEEPFIGHT_INDICATOR_H
#define SHEEPFIGHT_INDICATOR_H

#include "Manual.h"

class Player;

class Indicator {
public:
    Indicator(Player* player, int team);
    void render(sf::RenderTarget& target);
    void setPosition(const float x, const float y);
    void move(Direction dir){ this->pointTo = (this->pointTo + dir + numOfLines) % numOfLines;}
    int getPoint() {return pointTo;}
    void handlePosition();
    void show() { this->isShowing = true;}
    void hide() { this->isShowing = false;}
private:
    void initVariables(Player* player);
    void initTexture();
    void initSprite(int team);
    void setScale();
    sf::Sprite sprite;
    sf::Texture redTexture;
    sf::Texture blueTexture;
    int pointTo;
    Player* player;
    bool isShowing = false;
};


#endif //SHEEPFIGHT_INDICATOR_H
