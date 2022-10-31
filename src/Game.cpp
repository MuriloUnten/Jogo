#include "Game.hpp"

#define BACKGROUND_PATH "../assets/background.png"
#define MARIO_PATH "../assets/mario.png"


Game::Game() :
    graphics(Managers::GraphicsManager::getInstance()),
	background(BACKGROUND_PATH,  sf::Vector2f(800.0, 600.0), sf::Vector2f(0.0, 0.0)),
	mario(MARIO_PATH, sf::Vector2f(100.0, 100.0), sf::Vector2f(450.0, 50.0))
{
	entityList.pushEntity(&background);
	entityList.pushEntity(&mario);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            
            mario.getHitBox()->move(sf::Vector2f(0, -3));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            mario.getHitBox()->move(sf::Vector2f(-3, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            mario.getHitBox()->move(sf::Vector2f(0, 3));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            mario.getHitBox()->move(sf::Vector2f(3, 0));
        }

        graphics->clear();
        graphics->draw(background.getHitBox());
        graphics->draw(mario.getHitBox());
        
        graphics->display();
    }
}