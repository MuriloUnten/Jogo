#include "Game.hpp"

Game::Game() :
	background("background.png", sf::Vector2f(0.0, 0.0), sf::Vector2f(800.0, 600.0)),
	mario("mario.png", sf::Vector2f(100.0, 100.0), sf::Vector2f(450.0, 50.0)),
    graphics(GraphicsManager::getInstance())
{
	entityList.pushEntity(&background);
	entityList.pushEntity(&mario);

	execute();
}


Game::~Game()
{

}


void Game::execute()
{
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
        
        graphics->getWindow()->draw(*(background.getHitBox()));
        graphics->getWindow()->draw(*(mario.getHitBox()));
        
        graphics->display();
    }
}