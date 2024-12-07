#include "Game.h"


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight),
                                        "Sheep Fight");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initBackgroundTexture() {
    if (!this -> backgroundTexture.loadFromFile(BACKGROUND))
        cerr << "Could not load background texture";
}

void Game::initBackgroundSprite() {
    this->backgroundSprite.setTexture(this->backgroundTexture);
    float backgroundSizeX = backgroundTexture.getSize().x;
    float backgroundSizeY = backgroundTexture.getSize().y;
    this->backgroundSprite.setScale(windowWidth / backgroundSizeX, windowHeight/ backgroundSizeY);
}
void Game::updatePollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::run() {
    while (this->window->isOpen()) {
        this->updatePollEvents();
        this->render();
    }
}

void Game::render() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    //leftPlayerHealth->render(*this->window);
    //rightPlayerHealth->render(*this->window);
    this->window->display();
}
void Game::initHealthBars() {
    leftPlayerHealth = new Health(true, 50, 110);
    rightPlayerHealth = new Health(false, 980, 110);
}

/*void Game::updateHealthBars() {
    leftPlayerHealth->updateHealth();
    rightPlayerHealth->updateHealth();
}*/

Game::Game() {
    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    //this->initHealthBars();
}


Game::~Game() {
    delete this->window;
    //delete leftPlayerHealth;
    //delete rightPlayerHealth;
}