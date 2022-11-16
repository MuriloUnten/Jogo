#include "Game.hpp"

#define BG_PATH "../assets/mundo/teste.jpg"


Game::Game() :
graphics(Managers::GraphicsManager::getInstance()),
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
}


/* Runs the core of the program */
void Game::execute()
{
    // Main loop
    while (graphics->isWindowOpen())
    {
        graphics->updateDeltaTime();

        sf::Event event;
        while (graphics->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                graphics->close();
            }
        }

        graphics->clear();
        firstLevel.execute();
        graphics->display();
    }
}