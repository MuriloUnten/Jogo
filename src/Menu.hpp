#pragma once

#include "Being.hpp"
#include "Button.hpp"
#include <vector>

#define MENU_BACKGROUND_PATH "../assets/Menu/menuBackground.png"

class GraphicsManager;

namespace Menu
{
    class Menu : public Being
    {
    protected:
        std::vector<Button*> vectorOfButtons;
        std::vector<Button*>::iterator it;
        int selected;
        int min;
        int max;
        bool active;

    public:
        Menu(std::string fileName = MENU_BACKGROUND_PATH , sf::Vector2f position = sf::Vector2f(0.0f, 0.0f) , sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT));
        virtual ~Menu();

        void updateView();
        void selectDown();
        void selectUp();

        virtual void execute() = 0;
    };
}//namespace Menu