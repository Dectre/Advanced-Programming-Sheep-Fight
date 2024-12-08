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

typedef const string Path;
const int windowWidth = 1080;
const int windowHeight = 720;

enum Direction {LEFT = -1 , RIGHT = 1};

Path BACKGROUND = "sprites/background/background.png";
Path WHITE_PIG_MOVE = {"sprites/white_pig/move.png"};
Path WHITE_PIG_STAND = {"sprites/white_pig/stand.png"};

const int pigDamage = 2;
const int goatDamage = 5;
const int sheepDamage = 8;
const int pigSpeed = 8;
const int goatSpeed = 10;
const int sheepSpeed = 5;
const int pigPower = 5;
const int goatPower = 10;
const int sheepPower = 15;
const int pigDisplayProbability = 5;
const int goatDisplayProbability = 3;
const int sheepDisplayProbability = 2;


#endif //SHEEPFIGHT_MANUAL_H