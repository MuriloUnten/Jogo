#include "EventsManager.hpp"


namespace Managers
{
    EventsManager* EventsManager::instance = NULL;

    EventsManager::EventsManager()
    {
        pGraphics = GraphicsManager::getInstance();
        pInput = InputManager::getInstance();
    }


    EventsManager::~EventsManager()
    {
        pGraphics = NULL;
        pInput->deleteInstance();
        pInput = NULL;
    }


    EventsManager* EventsManager::getInstance()
    {
        if(instance == NULL)
            instance = new EventsManager();

        return instance;
        
    }


    void EventsManager::deleteInstance()
    {
        if(instance)
            delete instance;
    }


    void EventsManager::pollEvents()
    {
        sf::Event event;
        while(pGraphics->getWindow()->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                pGraphics->close();
            else if(event.type == sf::Event::KeyPressed)
                pInput->notifyKeyPressed(event.key.code);
            else if(event.type == sf::Event::KeyReleased)
                pInput->notifyKeyReleased(event.key.code);
        }
        // std::cout << "Polled all events.\n";
    }


}// namespace Managers