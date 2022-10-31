#define WIDTH 800
#define HEIGHT 600


#include "GraphicsManager.hpp"

namespace Managers
{
    GraphicsManager* GraphicsManager::instance = NULL;

    GraphicsManager* GraphicsManager::getInstance()
    {
        if (instance == NULL)
        {
            instance = new GraphicsManager();
        }
        return instance;
    }


    GraphicsManager::GraphicsManager() :
        window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "JOGO"))
    {

    }


    GraphicsManager::~GraphicsManager()
    {
        delete window;
    }


    bool GraphicsManager::isWindowOpen()
    {
        return (window->isOpen());
    }


    void GraphicsManager::clear()
    {
        if (isWindowOpen())
            window->clear();
    }


    void GraphicsManager::close()
    {
        if (isWindowOpen())
            window->close();
    }

    /* Updates the window onto the screen */
    void GraphicsManager::display()
    {
        if (isWindowOpen())
            window->display();
    }


    sf::RenderWindow* GraphicsManager::getWindow()
    {
        return window;
    }


    /* Draws given RectangleShape* onto the screen */
    void GraphicsManager::draw(sf::RectangleShape* rect)
    {
        if(isWindowOpen())
            window->draw(*rect);
    }


    /* Draws every element of given list */
    void GraphicsManager::draw(Lists::EntityList entities)
    {
        for(int i = 0; i < entities.getSize(); i++)
        {
            std::cout << "oi";
            
            draw(entities.getList()[i]->getHitBox());
            //entities.getList()[i]->draw();
        }
    }
}// namespace Managers