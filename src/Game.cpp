#include "Game.hpp"
#define BG1_PATH "../assets/mundo/teste.jpg"
#define BG2_PATH "../assets/mundo/forestBlack.png"


Game::Game():
/* Initializing Managers */
graphics(Managers::GraphicsManager::getInstance()),
events(Managers::EventsManager::getInstance()),
states(Managers::StateManager::getInstance()),
/* Initializing States */
pLevel(new Levels::Level(LEVEL1, BG2_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0))),
mainMenu(new Menu::MainMenu(this)),
gameOverMenu(new Menu::MenuGameOver()),
pauseMenu(new Menu::MenuPause(this)),
leaderboardMenu(new Menu::MenuLeaderboard(this)),
chooseMenu(new Menu::MenuChoose(this)),
endLevelMenu(new Menu::MenuEndLevel(this))
{
    Being::setInstance();

    /* Adding States to the StateManager's statesMap */
    states->addState(static_cast<State*>(pLevel));
    states->addState(static_cast<State*>(mainMenu));
    states->addState(static_cast<State*>(gameOverMenu));
    states->addState(static_cast<State*>(pauseMenu));
    states->addState(static_cast<State*>(leaderboardMenu));
    states->addState(static_cast<State*>(chooseMenu));
    states->addState(static_cast<State*>(endLevelMenu));

    /* Changing into Main menu and executing main loop */
    states->changeState(stateID::mainMenu);
    execute();
}


Game::~Game()
{
    Managers::GraphicsManager::deleteInstance();
    Managers::EventsManager::deleteInstance();
    Managers::StateManager::deleteInstance();

    // if (pLevel != NULL)
    //     delete (pLevel);
    // if (player1)
    //     delete (player1);
    // if (player2)
    //     delete (player2);
    

}


void Game::execute()
{
    // Main loop
    while (graphics->isWindowOpen())
    {
        graphics->updateDeltaTime();

        graphics->clear();

        events->pollEvents();

        states->executeState();

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


// Entities::MovingEntities::Player* Game::getPlayer1() 
// {
//     if (player1 == NULL)
//         player1 = new Entities::MovingEntities::Player();
//     return player1;
// }


// Entities::MovingEntities::Player* Game::getPlayer2()
//  {
//     if (player2 == NULL)
//         player2 = new Entities::MovingEntities::Player();
//     return player2;
// }


// bool Game::isTwoPlayersActive() const 
// {
//     return ((player1 != NULL) && (player2 != NULL));
// }


int Game::getCurrentLevel() const 
{
    return currentLevel;
}


void Game::setCurrentLevel(int num) 
{
    currentLevel = num;
}

void Game::createLevel()
{
    if(getCurrentLevel() == 1)
        pLevel = new Levels::Level(LEVEL1, BG1_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0));
    else 
        pLevel = new Levels::Level(LEVEL2, BG2_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0));

}

void Game::newGame()
{

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