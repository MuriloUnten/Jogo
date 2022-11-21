#include "Game.hpp"

#define BG_PATH "../assets/mundo/teste.jpg"


Game::Game() :
graphics(Managers::GraphicsManager::getInstance()),
events(Managers::EventsManager::getInstance()),
player(),
firstLevel(BG_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0), &player)
{
    Being::setInstance();
	execute();
}


Game::~Game()
{
    Managers::GraphicsManager::deleteInstance();
    graphics = NULL;
    Managers::EventsManager::deleteInstance();
    events = NULL;
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

        firstLevel.execute();

        graphics->display();
    }
}