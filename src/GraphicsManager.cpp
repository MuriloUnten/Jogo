#define WIDTH 800
#define HEIGHT 600


#include "GraphicsManager.hpp"


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


void GraphicsManager::display()
{
    if (isWindowOpen())
        window->display();
}


sf::RenderWindow* GraphicsManager::getWindow()
{
    return window;
}


void GraphicsManager::draw(sf::RectangleShape* rect)
{
    if(isWindowOpen())
        window->draw(*rect);
}


void GraphicsManager::draw(EntityList entities)
{
    
}