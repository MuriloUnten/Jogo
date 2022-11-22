#include "Menu.hpp"

#include "GraphicsManager.hpp"

namespace Menu
{
    Menu::Menu(stateID id, std::string fileName, sf::Vector2f size, sf::Vector2f position) :
    State(id, fileName, size),
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
        std::cout << "menu up\n";
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


    const bool Menu::getActive() const
    {
        return active;
    }


    void Menu::setActive(const bool isActive)
    {
        active = isActive;
    }

}//namespace Menu