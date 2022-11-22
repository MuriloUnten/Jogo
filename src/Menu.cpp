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
    }

    Menu::~Menu()
    {
        buttonList.clear();
        selected = NULL;
    }

    /* Make the menu selection go Down */
    void Menu::selectDown() {
        std::cout << "Inside Menu::selectDown()" << std::endl;
        if (active)
        {
            std::cout << "before " << selected << std::endl;
            if(selected->getNext() != NULL)
            {
                selected->getData()->select(false);
                selected = selected->getNext();
                selected->getData()->select(true);
            }
            std::cout << "after " << selected << std::endl;
        }
    }

    /* Make the menu selection go Up */
    void Menu::selectUp() {
        std::cout << "Inside Menu::selectUp()" << std::endl;
        if (active)
        {
            std::cout << "before " << selected << std::endl;
            if(selected->getPrev() != NULL)
            {
                selected->getData()->select(false);
                selected = selected->getPrev();
                selected->getData()->select(true);
            }
            std::cout << "after " << selected << std::endl;
        }
    }

    void Menu::updateView() 
    {
        
    }
}//namespace Menu