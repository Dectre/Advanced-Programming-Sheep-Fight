#ifndef SHEEPFIGHT_MANUAL_H
#define SHEEPFIGHT_MANUAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef const int PixelSize;
typedef const string Path;

PixelSize windowWidth = 1080;
PixelSize windowHeight = 720;

enum Direction {LEFT = -1 , RIGHT = 1, UP=1, DOWN=-1};

Path BACKGROUND = "sprites/background/background.png";
Path WHITE_PIG_MOVE = "sprites/white-pig/move.png";
Path WHITE_PIG_STAND = "sprites/white-pig/stand.png";
Path BLACK_PIG_MOVE = "sprites/black-pig/move.png";
Path BLACK_PIG_STAND = "sprites/black-pig/stand.png";

const int numOfWhitePigMovingAnimations = 4;
const int numOfBlackPigMovingAnimations = 3;
const int pigDamage = 2;
const int goatDamage = 5;
const int sheepDamage = 8;
const float pigSpeed = 2;
const float goatSpeed = 2.5;
const float sheepSpeed = 1;
const int pigPower = 5;
const int goatPower = 10;
const int sheepPower = 15;
const int pigDisplayProbability = 5;
const int goatDisplayProbability = 3;
const int sheepDisplayProbability = 2;
const int numOfLines = 4;
const int queueSize=3;
const int healthBarHeight=500;
const int healthBarWidth=50;
const sf::Color healthBarColor(11, 102, 35);
const int healthBarXPos=30;

PixelSize lineRectWidth = 815;
PixelSize lineRectHeight = 85;
PixelSize lineDistance = 70;
const int lineRectX = 115;
const int lineRectY = 100 + 3 * lineRectHeight + lineDistance + 60 + 60;


#endif //SHEEPFIGHT_MANUAL_H