#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Observer;


namespace Managers
{
    class InputManager
    {
    private:
        static InputManager* instance;
        InputManager();

        std::map<sf::Keyboard::Key, std::string> keyMap;

        std::vector<Observer*> observers;

    public:
        ~InputManager();
        static InputManager* getInstance();
        static void deleteInstance();

        void notifyKeyPressed(sf::Keyboard::Key key);
        void notifyKeyReleased(sf::Keyboard::Key key);

        void attach(Observer* newObserver);
        void detach(Observer* observer);
    };

}// namespace Managers