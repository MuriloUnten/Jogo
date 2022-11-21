#include "Game.hpp"

#define BG1_PATH "../assets/mundo/teste.jpg"
#define BG2_PATH "../assets/mundo/forestBlack.png"


Game::Game() :
graphics(Managers::GraphicsManager::getInstance()),
player(),
secondLevel(BG2_PATH, sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f(0, 0), &player)
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
        secondLevel.execute();
        graphics->display();
    }
}