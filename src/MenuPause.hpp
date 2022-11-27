#pragma once

#include "Menu.hpp"

class Game;

namespace Menu
{
    class MenuPause : public Menu
    {
    private:
        Game* pGame;
        sf::Text gamePaused;

    public:

        MenuPause(Game* pG = NULL, std::string fileName = MENU_BACKGROUND_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuPause();

        void draw();
        void execute();
        void pushButton();

        void resetState();

    };
}//namespace Menu