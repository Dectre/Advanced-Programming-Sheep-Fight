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

void Game::initHealthBars() {
    this->playerOneHealth = new Health(healthBarXPos, windowHeight / 2 - 250);
    this->playerTwoHealth= new Health(windowWidth - 2 * healthBarXPos - healthBarWidth, windowHeight / 2 - 250);
}


void Game::updatePollEvents() {
    sf::Event event;
    while (this->window->pollEvent(event)) {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
        this->playerOne.setLinePointer(UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->playerOne.setLinePointer(DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->playerTwo.setLinePointer(UP);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ){
        this->playerTwo.setLinePointer(DOWN);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        //check if animal can be sent
        this->playerOneQueue->update(WHITE_PLAYER);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        //check if animal can be sent
        this->playerTwoQueue->update(BLACK_PLAYER);
    }

}


void Game::run() {
    this->lines[0]->addAnimalToTeam1(new WhitePig() );
    this->lines[0]->addAnimalToTeam2( new BlackPig() );
    this->lines[0]->addAnimalToTeam1(new WhiteGoat() );
    this->lines[0]->addAnimalToTeam2( new BlackGoat() );
    this->lines[0]->addAnimalToTeam1(new WhiteSheep() );
    this->lines[0]->addAnimalToTeam2( new BlackSheep() );

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
    updateInput();
    playerOneHealth->updateHealth(playerOne.getHealth());
    playerTwoHealth->updateHealth(playerTwo.getHealth());

}
void Game::render() {
    this->window->clear();
    this->window->draw(this->backgroundSprite);
    for (Line* line: lines) {
        line->render(*this->window);
    }
    this->playerOneHealth->render(*this->window);
    this->playerTwoHealth->render(*this->window);
    this->playerOneQueue->render(*this->window);
    this->playerTwoQueue->render(*this->window);

    this->window->display();
}



Game::Game() {
    this->initWindow();
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    this->initHealthBars();
    for (int i = 0; i < numOfLines; ++i) {
        this->lines.push_back(new Line());
    }
    this->initQueues();
}

Game::~Game() {
    delete this->window;
}