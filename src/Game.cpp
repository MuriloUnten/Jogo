#include "Game.hpp"

#define BG1_PATH "../assets/mundo/teste.jpg"
#define BG2_PATH "../assets/mundo/forestBlack.png"


Game::Game():
graphics(Managers::GraphicsManager::getInstance()),
events(Managers::EventsManager::getInstance()),
player1(),
//secondLevel(BG2_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0), &player)
mainMenu(new Menu::MainMenu(this))
{
    Being::setInstance();

    lvlEnded = false;

    execute();
}


Game::~Game()
{
    Managers::GraphicsManager::deleteInstance();
    Managers::EventsManager::deleteInstance();

    if (pLevel != NULL)
        delete (pLevel);
    if (player1)
        delete (player1);
    if (player2)
        delete (player2);
}


/* Runs the core of the program */
void Game::execute()
{
    // Main loop
    while (graphics->isWindowOpen())
    {
        graphics->updateDeltaTime();

        graphics->clear();

        events->pollEvents();

        mainMenu->execute();
        //secondLevel.execute();
        graphics->display();
    }
}


Levels::Level* Game::getpLevel() const 
{
    return pLevel;
}

void Game::setLevel(Levels::Level* pLevel)
 {
    this->pLevel = pLevel;
}

Entities::MovingEntities::Player* Game::getPlayer1() 
{
    if (player1 == NULL)
        player1 = new Entities::MovingEntities::Player();
    return player1;
}

Entities::MovingEntities::Player* Game::getPlayer2()
 {
    if (player2 == NULL)
        player2 = new Entities::MovingEntities::Player();
    return player2;
}

bool Game::isTwoPlayersActive() const 
{
    return ((player1 != NULL) && (player2 != NULL));
}

int Game::getCurrentLevel() const 
{
    return currentLevel;
}

void Game::setCurrentLevel(int num) 
{
    currentLevel = num;
}

void Game::endGame() 
{
    graphics->close();
}

void Game::deleteLevel() 
{
    if (pLevel != NULL)
        delete (pLevel);
    pLevel = NULL;
}

void Game::resetPlayers() 
{
    if (player1 != NULL)
        delete player1;
    if (player2 != NULL)
        delete player2;
    player1 = NULL;
    player2 = NULL;
}

bool Game::isPlaying() const
{
    return lvlEnded;
}

void Game::setLvlEnded(bool x) 
{
    lvlEnded = x;
}