#pragma once

#include "Being.hpp"
#include "Button.hpp"
#include "List.hpp"
#include <list>

#define MENU_BACKGROUND_PATH "../assets/Menu/menuBackground.png"


namespace Menu
{
    class Menu : public Being
    {
    protected:
        Lists::List<Button> buttonList;
        Lists::List<Button>::Element<Button>* selected;

        bool active;

    public:
        Menu(std::string fileName = MENU_BACKGROUND_PATH, sf::Vector2f size = sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        virtual ~Menu();

        void updateView();
        void selectDown();
        void selectUp();

        virtual void execute() = 0;
    };
}//namespace Menu