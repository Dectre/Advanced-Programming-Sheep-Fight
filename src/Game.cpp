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
        updateInput(event);
    }
}

void Game::movePlayerIndicator(Player *player, Direction dir) {
    if (player->checkIndicatorStatus())
        player->moveIndicator(dir);
    player->showIndicator();
}

void Game::updateInput(sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Space) {
            if (this->playerOne->checkIndicatorStatus()) {
                if (playerOneCooldownClock.getElapsedTime().asSeconds() >= animalCooldownDuration) {
                    this->playerOne->hideIndicator();
                    lines[playerOne->getIndicatorPointer()]->addAnimalToTeam1(this->playerOne->getFirstAnimalFromQueue());
                    this->playerOne->updateQueue(WHITE_PLAYER);
                    playerOneCooldownClock.restart();
                }
            }
        }

        if (event.key.code == sf::Keyboard::Enter) {
            if (this->playerTwo->checkIndicatorStatus()) {
                if (playerTwoCooldownClock.getElapsedTime().asSeconds() >= animalCooldownDuration) {
                    this->playerTwo->hideIndicator();
                    lines[playerTwo->getIndicatorPointer()]->addAnimalToTeam2(this->playerTwo->getFirstAnimalFromQueue());
                    this->playerTwo->updateQueue(BLACK_PLAYER);
                    playerTwoCooldownClock.restart();
                }
            }
        }

        if (event.key.code == sf::Keyboard::W) {
            movePlayerIndicator(playerOne, UP);
        }
        if (event.key.code == sf::Keyboard::S) {
            movePlayerIndicator(playerOne, DOWN);
        }

        if (event.key.code == sf::Keyboard::Up) {
            movePlayerIndicator(playerTwo, UP);
        }
        if (event.key.code == sf::Keyboard::Down) {
            movePlayerIndicator(playerTwo, DOWN);
        }
    }
}



void Game::run() {
    this->lines[0]->addAnimalToTeam1(new WhitePig() );
    this->lines[0]->addAnimalToTeam2( new BlackPig() );
    /*this->lines[0]->addAnimalToTeam1(new WhiteGoat() );
    this->lines[0]->addAnimalToTeam2( new BlackGoat() );
    this->lines[0]->addAnimalToTeam1(new WhiteSheep() );
    this->lines[0]->addAnimalToTeam2( new BlackSheep() );*/
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
    playerOneCooldownClock.restart();
    playerTwoCooldownClock.restart();
}

Game::~Game() {
    delete this->window;
}