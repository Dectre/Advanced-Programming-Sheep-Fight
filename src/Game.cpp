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

void Game::initMusic() {
    if (!this->gameMusic.openFromFile(MUSIC))
    {
        cerr << "Error Openning Music File!" << endl;
    }
    this->gameMusic.setLoop(true);
    this->gameMusic.play();
}

void Game::updatePollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
        if (!player1WonGame && !player2WonGame)
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
                if (playerOneCooldownClock.getElapsedTime().asMilliseconds() >= animalCooldownDuration  and
                    lines[playerOne->getIndicatorPointer()]->canTeam1AddAnimal(playerOne->getIndicatorPointer())) {
                    this->playerOne->hideIndicator();
                    lines[playerOne->getIndicatorPointer()]->addAnimalToTeam1(this->playerOne->getFirstAnimalFromQueue(), playerOne->getIndicatorPointer());
                    this->playerOne->updateQueue(WHITE_PLAYER);
                    playerOneCooldownClock.restart();
                }

            }
        }

        if (event.key.code == sf::Keyboard::Enter) {
            if (this->playerTwo->checkIndicatorStatus()) {
                if (playerTwoCooldownClock.getElapsedTime().asMilliseconds() >= animalCooldownDuration and
                lines[playerTwo->getIndicatorPointer()]->canTeam2AddAnimal(playerTwo->getIndicatorPointer())) {
                    this->playerTwo->hideIndicator();
                    lines[playerTwo->getIndicatorPointer()]->addAnimalToTeam2(this->playerTwo->getFirstAnimalFromQueue(), playerTwo->getIndicatorPointer());
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
    while (this->window->isOpen()) {
        this->updatePollEvents();
        this->update();
        this->render();
    }
}

void Game::update() {
    if (!player1WonGame && !player2WonGame) {
        for (Line *line: lines) {
            line->update();
        }
        this->playerOne->update();
        this->playerTwo->update();
        if (this->playerOne->getHealthNumber() <= 0) this->player2WonGame = true;
        if (this->playerTwo->getHealthNumber() <= 0) this->player1WonGame = true;
    }
}
void Game::render() {
    if (!player1WonGame && !player2WonGame) {
        this->window->clear();
        this->window->draw(this->backgroundSprite);
        for (Line *line: lines) {
            line->render(*this->window);
        }
        this->playerOne->render(*this->window);
        this->playerTwo->render(*this->window);
        this->window->display();
    }
    else {
        this->window->clear();
        this->window->draw(this->backgroundSprite);
        this->playerOne->getHealth()->render(*this->window);
        this->playerTwo->getHealth()->render(*this->window);
        if (player1WonGame) this->window->draw(this->player1WinMessage);
        else this->window->draw(this->player2WinMessage);
        this->window->display();
    }
}

void Game::initLines() {
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line(this));
    }
}
Game::Game() {
    this->playerOne = new Player(1);
    this->playerTwo = new Player(2);
    this->player1WonGame = false;
    this->player2WonGame = false;
    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    this->initLines();
    this->initMusic();
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line(this));
    }
    playerOneCooldownClock.restart();
    playerTwoCooldownClock.restart();
    initEndGameTexts();
}

void Game::initEndGameTexts() {
    if (!font.loadFromFile(FONT1)) {
        std::cerr << "Font loading failed!" << std::endl;
    }

    player1WinMessage.setFont(font);
    player1WinMessage.setCharacterSize(130);
    player1WinMessage.setOutlineThickness(20);
    player1WinMessage.setOutlineColor(sf::Color::Black);
    player1WinMessage.setFillColor(sf::Color::White);
    player1WinMessage.setString(player1WinText);
    sf::FloatRect player1Bounds = player1WinMessage.getLocalBounds();
    player1WinMessage.setOrigin(player1Bounds.left + player1Bounds.width / 2,
                                player1Bounds.top + player1Bounds.height / 2);
    player1WinMessage.setPosition(windowWidth / 2, windowHeight / 2);

    player2WinMessage.setFont(font);
    player2WinMessage.setCharacterSize(130);
    player2WinMessage.setOutlineThickness(20);
    player2WinMessage.setOutlineColor(sf::Color::White);
    player2WinMessage.setFillColor(sf::Color::Black);
    player2WinMessage.setString(player2WinText);
    sf::FloatRect player2Bounds = player2WinMessage.getLocalBounds();
    player2WinMessage.setOrigin(player2Bounds.left + player2Bounds.width / 2,
                                player2Bounds.top + player2Bounds.height / 2);
    player2WinMessage.setPosition(windowWidth / 2, windowHeight / 2);
}

Game::~Game() {
    delete this->window;
}