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


    void GraphicsManager::deleteInstance()
    {
        if (instance)
            delete instance;
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

}// namespace Managers