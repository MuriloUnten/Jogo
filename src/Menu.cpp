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


    void Menu::drawButtons()
    {
        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }
    }
}//namespace Menu