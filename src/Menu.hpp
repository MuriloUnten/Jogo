#pragma once

#include "State.hpp"
#include "Button.hpp"
#include "List.hpp"
#include "MenuControl.hpp"

#define MENU_BACKGROUND_PATH "../assets/Menu/PrincipalMenu.png"


namespace Menu
{
    class Menu : public State
    {
    protected:
        MenuControl controls;

        Lists::List<Button> buttonList;
        Lists::List<Button>::Element<Button>* selected;

        int hoveredButton;

    public:
        Menu(stateID id=undefined, std::string fileName = MENU_BACKGROUND_PATH, sf::Vector2f size = sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        virtual ~Menu();

        void selectUp();
        void selectDown();
        virtual void pushButton() = 0;

        virtual void execute() = 0;
        virtual void draw() = 0;
        virtual void resetState() = 0;

        void drawButtons();
    };
}//namespace Menu