#include "Menu.hpp"

#include "GraphicsManager.hpp"

namespace Menu
{
    Menu::Menu(std::string fileName, sf::Vector2f size, sf::Vector2f position) :
    Being(fileName, size, position),
    buttonList(),
    selected()
    {
        selected = buttonList.getHead();
        active = false;
    }

    Menu::~Menu()
    {
        buttonList.clear();
        selected = NULL;
    }

    /* Make the menu selection go Down */
    void Menu::selectDown() {
        if (active)
        {
            if(selected->getNext() != NULL)
                selected = selected->getNext();
        }
    }

    /* Make the menu selection go Up */
    void Menu::selectUp() {
        if (active)
        {
            if(selected->getPrev() != NULL)
                selected = selected->getPrev();
        }
    }

    void Menu::updateView() 
    {
        
    }
}//namespace Menu