#ifndef SHEEPFIGHT_MANUAL_H
#define SHEEPFIGHT_MANUAL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
typedef const int PixelSize;
typedef const string Path;

PixelSize windowWidth = 1080;
PixelSize windowHeight = 720;

enum Direction {LEFT = -1, RIGHT = 1, UP=-1, DOWN=1};

enum PLAYER_NUM {WHITE_PLAYER=1, BLACK_PLAYER=2};

Path BACKGROUND = "sprites/background/background.png";
Path TEAM1_POINTER = "sprites/red-gradient.png";
Path TEAM2_POINTER = "sprites/blue-gradient.png";
Path WHITE_PIG_MOVE = "sprites/white-pig/move.png";
Path WHITE_PIG_STAND = "sprites/white-pig/stand.png";
Path WHITE_PIG_QUEUE = "sprites/white-pig/queue.png";
Path BLACK_PIG_MOVE = "sprites/black-pig/move.png";
Path BLACK_PIG_STAND = "sprites/black-pig/stand.png";
Path BLACK_PIG_QUEUE = "sprites/black-pig/queue.png";
Path WHITE_GOAT_MOVE = "sprites/white-goat/move.png";
Path WHITE_GOAT_STAND = "sprites/white-goat/stand.png";
Path WHITE_GOAT_QUEUE = "sprites/white-goat/queue.png";
Path BLACK_GOAT_MOVE = "sprites/black-goat/move.png";
Path BLACK_GOAT_STAND = "sprites/black-goat/stand.png";
Path BLACK_GOAT_QUEUE = "sprites/black-goat/queue.png";
Path WHITE_SHEEP_MOVE = "sprites/white-sheep/move.png";
Path WHITE_SHEEP_STAND = "sprites/white-sheep/stand.png";
Path WHITE_SHEEP_QUEUE = "sprites/white-sheep/queue.png";
Path BLACK_SHEEP_MOVE = "sprites/black-sheep/move.png";
Path BLACK_SHEEP_STAND = "sprites/black-sheep/stand.png";
Path BLACK_SHEEP_QUEUE = "sprites/black-sheep/queue.png";

const int numOfWhitePigMovingAnimations = 4;
const int numOfWhitePigStandingAnimations = 4;
const int whitePigAnimationTime = 100;

const int numOfBlackPigMovingAnimations = 3;
const int numOfBlackPigStandingAnimations = 6;
const int blackPigAnimationTime = 133;

const int numOfWhiteGoatMovingAnimations = 8;
const int numOfWhiteGoatStandingAnimations = 8;
const int whiteGoatAnimationTime = 66;

const int numOfBlackGoatMovingAnimations = 8;
const int numOfBlackGoatStandingAnimations = 8;
const int blackGoatAnimationTime = 66;

const int numOfWhiteSheepMovingAnimations = 3;
const int numOfWhiteSheepStandingAnimations = 4;
const int whiteSheepAnimationTime = 100;

const int numOfBlackSheepMovingAnimations = 3;
const int numOfBlackSheepStandingAnimations = 4;
const int blackSheepAnimationTime = 100;

const int pigDamage = 5;
const int goatDamage = 3;
const int sheepDamage = 8;
const float pigSpeed = 2;
const float goatSpeed = 1.5;
const float sheepSpeed = 1;
const int pigPower = 1;
const int goatPower = 2;
const int sheepPower = 3;
const int pigDisplayProbability = 5;
const int goatDisplayProbability = 3;
const int sheepDisplayProbability = 2;
const int numOfLines = 4;
const int queueSize=3;

PixelSize healthBarHeight=400;
PixelSize healthBarWidth=20;
const sf::Color healthBarColor(11, 102, 35);
const int playerOneHealthBarXPos=38;
const int playerTwoHealthBarXPos= windowWidth - 103;
const int HealthBarYPos = (windowHeight - healthBarHeight) / 2;
const int healthBarOutlineThickness = 5;

PixelSize lineRectWidth = 815;
PixelSize lineRectHeight = 85;
const vector<int> lineDistance = {65, 60, 60};
const int lineRectY = 105;

const int pigWidth = 90;
const int pigHeight = 70;

const int goatWidth = 74;
const int goatHeight= 86;

const int sheepWidth = 90;
const int sheepHeight = 70;

const int queueXpos=400;
const int whitePlayerqueueYPos=20;
const int blackPlayerqueueYPos=640;
const int spaceBetweenQueueBubbles=100;
const int queueHeight=70;
const int queueWidth=80;
const int bubbleRadiusOffset=15;

const int playerOneStartPoint = 110;
const int playerTwoStartPoint = windowWidth - 150;


const float animalCooldownDuration = 2;

#endif //SHEEPFIGHT_MANUAL_H