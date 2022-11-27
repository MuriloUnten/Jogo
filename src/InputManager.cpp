#include "InputManager.hpp"
#include "Observer.hpp"
#include <iostream>

namespace Managers
{
    InputManager* InputManager::instance = NULL;

    InputManager::InputManager()
    {
        keyMap[sf::Keyboard::W] = "W";
        keyMap[sf::Keyboard::A] = "A";
        keyMap[sf::Keyboard::S] = "S";
        keyMap[sf::Keyboard::D] = "D";
        keyMap[sf::Keyboard::Space] = "Space";
    }


    InputManager::~InputManager()
    {

    }


    InputManager* InputManager::getInstance()
    {
        if(instance == NULL)
            instance = new InputManager();
        
        return instance;
        
    }


    void InputManager::deleteInstance()
    {
        if(instance)
            delete instance;
    }


    void InputManager::notifyKeyPressed(sf::Keyboard::Key key)
    {
        for(int i = 0; i < observers.size(); i++)
        {
            observers[i]->handleKeyPressed(keyMap[key] == "" ? "Unknown" : keyMap[key]);
        }
    }


    void InputManager::notifyKeyReleased(sf::Keyboard::Key key)
    {
        for(int i = 0; i < observers.size(); i++)
        {
            observers[i]->handleKeyReleased(keyMap[key] == "" ? "Unknown" : keyMap[key]);
        }
    }


    void InputManager::attach(Observer* newObserver)
    {
        if(newObserver != NULL)
            observers.push_back(newObserver);
    }


    void InputManager::detach(Observer* observer)
    {
        for(int i = 0; i < observers.size(); i++)
        {
            if(observers[i] == observer)
            {
                observers.erase(observers.begin() + i);
                return;
            }
        }
    }

}// namespace Managers