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

void Game::initHealthBars() {
    this->leftPlayerHealth = new Health(healthBarXPos, windowHeight / 2 - 250);
    this->rightPlayerHealth= new Health(windowWidth-2*healthBarXPos-healthBarWidth, windowHeight / 2 - 250);
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
    this->lines[0]->addAnimalToTeam2( new BlackPig() );
    lineRect.setSize(sf::Vector2f (lineRectWidth,lineRectHeight));
    lineRect.setFillColor(sf::Color::Transparent);
    lineRect.setOutlineColor(sf::Color::White);
    lineRect.setOutlineThickness(3);
    lineRect.setPosition(lineRectX, lineRectY);
    while (this->window->isOpen()) {
        this->updatePollEvents();
        this->update();
        this->render();
    }
}

void Game::update() {
    for (Line* line: lines) {
        line->update();
    }
    leftPlayerHealth->updateHealth(leftPlayer.getHealth());
    rightPlayerHealth->updateHealth(rightPlayer.getHealth());

}
void Game::render() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    for (Line* line: lines) {
        line->render(*this->window);
    }
    this->window->draw(lineRect);
    this->leftPlayerHealth->render(*this->window);
    this->rightPlayerHealth->render(*this->window);
    this->window->display();
}



Game::Game() {
    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    this->initQueues();
    this->initHealthBars();
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line());
    }
}

Game::~Game() {
    delete this->window;
}