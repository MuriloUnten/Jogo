#include "Game.hpp"

#define BG_PATH "../assets/mundo/images.jpeg"


Game::Game() :
graphics(Managers::GraphicsManager::getInstance()),
firstLevel(BG_PATH, sf::Vector2f(WIDTH, HEIGHT))
{
	execute();
}


Game::~Game()
{

}


/* Runs the core of the program */
void Game::execute()
{
    // Main loop
    while (graphics->isWindowOpen())
    {
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