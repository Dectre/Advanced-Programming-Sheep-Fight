#ifndef SHEEPFIGHT_INDICATOR_H
#define SHEEPFIGHT_INDICATOR_H

#include "Manual.h"

class Indicator {
public:
    Indicator(int team);
    void render(sf::RenderTarget& target);
    void setPosition(const float x, const float y);
    void indicatorMove(Direction dir){ this->pointTo = (this->pointTo + dir + numOfLines) % numOfLines;}
    int getPoint() {return pointTo;}
    void handlePosition();
    void Show() { this->isShowing = true;}
    void Hide() { this->isShowing = false;}
private:
    void initVariables();
    void initTexture();
    void initSprite(int team);
    void setScale();
    sf::Sprite sprite;
    sf::Texture redTexture;
    sf::Texture blueTexture;
    int pointTo;
    bool isShowing = false;
};


#endif //SHEEPFIGHT_INDICATOR_H
