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

void Game::initQueues() {
    this->leftPlayerQueue = new Queue(sf::Vector2f(50.f, 50.f), 80.f);
    this->rightPlayerQueue = new Queue(sf::Vector2f(900.f, 50.f), 80.f);
}


void Game::updatePollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::run() {
    this->lines[0]->addAnimalToTeam1(new WhitePig() );
    while (this->window->isOpen()) {
        this->updatePollEvents();
        this->render();
    }
}

void Game::render() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    for (Line* line: lines) {
        line->render(*this->window);
    }
    this->window->display();
}

void Game::updateQueues() {
    for (auto changedQueue : {leftPlayerQueue, rightPlayerQueue}){
        auto currentAnimalQueue=changedQueue->getAnimalQueue();
        if (currentAnimalQueue.empty()) {
        delete currentAnimalQueue[0];
        currentAnimalQueue.erase(currentAnimalQueue.begin());
    }
    if (currentAnimalQueue.size() < maxQueueSize) {
        currentAnimalQueue.push_back(changedQueue->generateAnimal());
    }
}};

Game::Game() {


    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line());
    }
}
    this->initQueues();


Game::~Game() {
    delete this->window;
}