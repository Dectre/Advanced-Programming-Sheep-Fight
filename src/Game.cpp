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
    this->playerOneQueue = new Queue(WHITE_PLAYER);
    this->playerTwoQueue = new Queue(BLACK_PLAYER);
}

void Game::updatePollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
        updateInput(event);
    }
}

void Game::updateInput(sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::W) {
            this->playerOne->showIndicator();
            this->playerOne->moveIndicator(UP);
        }
        if (event.key.code == sf::Keyboard::S) {
            this->playerOne->showIndicator();
            this->playerOne->moveIndicator(DOWN);
        }
        if (event.key.code == sf::Keyboard::Up) {
            this->playerTwo->showIndicator();
            this->playerTwo->moveIndicator(UP);
        }
        if (event.key.code == sf::Keyboard::Down) {
            this->playerTwo->showIndicator();
            this->playerTwo->moveIndicator(DOWN);
        }
        if (event.key.code == sf::Keyboard::Space) {
            this->playerOne->hideIndicator();
            this->playerOneQueue->update(WHITE_PLAYER);
        }
        if (event.key.code == sf::Keyboard::Enter) {
            this->playerTwo->hideIndicator();
            this->playerTwoQueue->update(BLACK_PLAYER);
        }
    }
}


void Game::run() {
    this->lines[0]->addAnimalToTeam1(new WhitePig() );
    this->lines[0]->addAnimalToTeam2( new BlackPig() );
    this->lines[0]->addAnimalToTeam1(new WhiteGoat() );
    this->lines[0]->addAnimalToTeam2( new BlackGoat() );
    this->lines[0]->addAnimalToTeam1(new WhiteSheep() );
    this->lines[0]->addAnimalToTeam2( new BlackSheep() );
    //this->testInd1 = new Indicator(playerOne , 1);
    //this->testInd2 = new Indicator(playerTwo, 2);
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
    this->playerOne->getHealth()->updateHealthbar();
    this->playerTwo->getHealth()->updateHealthbar();

}
void Game::render() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    for (Line* line: lines) {
        line->render(*this->window);
    }
    this->playerOne->render(*this->window);
    this->playerTwo->render(*this->window);
    this->playerOneQueue->render(*this->window);
    this->playerTwoQueue->render(*this->window);

    this->window->display();
}



Game::Game() {
    this->playerOne = new Player(1);
    this->playerTwo = new Player(2);
    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line());
    }
    this->initQueues();
}

Game::~Game() {
    delete this->window;
}