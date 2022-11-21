#include "Menu.hpp"

#include "GraphicsManager.hpp"

namespace Menu
{
    Menu::Menu(std::string fileName, sf::Vector2f position, sf::Vector2f size) :
    Being(fileName, position, size)
    {
        selected = 0;
        min = 0;
        max = 2;
        active = false ;
    }

    Menu::~Menu() {
        Button* bt = NULL;
        while (vectorOfButtons.size() != 0) {
            bt = vectorOfButtons.back();
            delete (bt);
            vectorOfButtons.pop_back();
        }
        vectorOfButtons.clear();
    }

    /* Make the menu selection go Down */
    void Menu::selectDown() {
        if (active) {
            vectorOfButtons[selected]->select(false);
            selected++;
            if (selected > max)
                selected = max;
            vectorOfButtons[selected]->select(true);
        }
    }

    /* Make the menu selection go Up */
    void Menu::selectUp() {
        if (active) {
            vectorOfButtons[selected]->select(false);
            selected--;
            if (selected < min)
                selected = min;
            vectorOfButtons[selected]->select(true);
        }
    }

    void Menu::updateView() 
    {
        
    }
}//namespace Menu