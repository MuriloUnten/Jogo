#include "Menu.hpp"

#include "GraphicsManager.hpp"

namespace Menu
{
    Menu::Menu(std::string fileName, sf::Vector2f size, sf::Vector2f position) :
    Being(fileName, size, position),
    controls(this),
    buttonList(),
    selected()
    {
        selected = buttonList.getHead();
        active = false;
        hoveredButton = 0;
    }


    Menu::~Menu()
    {
        buttonList.clear();
        selected = NULL;
    }


    /* Make the menu selection go Up */
    void Menu::selectUp() {
        std::cout << "up\n";
        if (active)
        {
            if(selected->getPrev() != NULL)
            {
                selected->getData()->select(false);
                selected = selected->getPrev();
                selected->getData()->select(true);
                hoveredButton--;
            }
        }
    }


    /* Make the menu selection go Down */
    void Menu::selectDown() {
        if (active)
        {
            if(selected->getNext() != NULL)
            {
                selected->getData()->select(false);
                selected = selected->getNext();
                selected->getData()->select(true);
                hoveredButton++;
            }
        }
    }

}//namespace Menu