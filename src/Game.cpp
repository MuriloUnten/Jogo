#include "Game.hpp"

#define MARIO_PATH "../assets/mario.png"


Game::Game() :
    graphics(Managers::GraphicsManager::getInstance()),
    entityList(new Lists::EntityList()),
	mario(MARIO_PATH, sf::Vector2f(100.0, 100.0), sf::Vector2f(450.0, 50.0))
{
    
    //Entities::Entity* pAuxMario = &mario;
    Entities::Entity* pAux = static_cast<Entities::Entity*>(&mario);
	entityList->pushEntity(pAux);

	execute();
}


Game::~Game()
{

}


/* Runs the core of the program */
void Game::execute()
{
    //Entities::Entity* pAux = static_cast<Entities::Entity*>(&mario);
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
        graphics->draw(entityList);
        graphics->display();

        
    }
}