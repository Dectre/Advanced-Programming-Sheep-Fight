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


const string BACKGROUND = "sprites/background/background.png";
const vector<string> SHEEP = {"sprites/background/background.png"}

#endif //SHEEPFIGHT_MANUAL_H