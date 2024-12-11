#include "Indicator.h"
#include "Player.h"

Indicator::Indicator(Player* player, int team) {
    this->initVariables(player);
    this->initTexture();
    this->initSprite(team);
    this->setScale();
}

void Indicator::initVariables(Player* plyr) {
    this-> player = plyr;
    this->pointTo = -1;
}
void Indicator::initTexture() {
    if (!this -> redTexture.loadFromFile(TEAM1_POINTER))
        cerr << "Could not load Red Gradient texture";
    if (!this -> blueTexture.loadFromFile(TEAM2_POINTER))
        cerr << "Could not load Blue Gradient texture";
}

void Indicator::initSprite(int team) {
    if (team == WHITE_PLAYER){
        this->sprite.setTexture(redTexture);
        this->sprite.setColor(sf::Color(255,0,0,100));
    }
    else {
        this->sprite.setTexture(blueTexture);
        this->sprite.setScale(-1, 1);
        this->sprite.setColor(sf::Color(255, 255, 255, 100));
    }
}

void Indicator::setScale() {
    const sf::Vector2f spriteSize(
            sprite.getTexture()->getSize().x * sprite.getScale().x,
            sprite.getTexture()->getSize().y * sprite.getScale().y);
    float xScale = lineRectWidth / spriteSize.x / 2;
    float yScale = lineRectHeight / spriteSize.y;
    this->sprite.setScale(xScale, yScale);
}

void Indicator::handlePosition() {
    float distance;
    for (int i = 0; i < pointTo; i++)
        distance += lineDistance[i];
    float x = this->player->getStartPoint();
    float y = lineRectY + pointTo * (lineRectHeight) + distance;
    setPosition(x,y);
}

void Indicator::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Indicator::render(sf::RenderTarget& target) {
    if (this->isShowing){
        handlePosition();
        target.draw(sprite);
    }
}