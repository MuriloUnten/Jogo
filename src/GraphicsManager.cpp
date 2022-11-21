#include "GraphicsManager.hpp"

#define FONT_PATH "../assets/Fonts/ethn.otf"

namespace Managers
{
    GraphicsManager* GraphicsManager::instance = NULL;
    float GraphicsManager::deltaTime = 0;

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
        window = NULL;
        instance = NULL;
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


    void GraphicsManager::updateDeltaTime()
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 0.1f)
            deltaTime = 0.1f;

    }


    const float GraphicsManager::getDeltaTime()
    {
        return deltaTime;
    }

    /* Returns a font pointer to be used by texts. */
    sf::Font* GraphicsManager::getFont() {
        if (!font) {
            font = new sf::Font();
            if (!font->loadFromFile(FONT_PATH)) {
                std::cout << "Error loading Font!" << std::endl;
                exit(1);
            }
        }
        return font;
    }

}// namespace Managers