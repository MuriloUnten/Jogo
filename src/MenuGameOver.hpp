#pragma once

#include "Menu.hpp"


namespace Menu
{
    class MenuGameOver : public Menu
    {
    private:
        sf::Text gameOver;

    public:
        MenuGameOver(std::string fileName = MENU_BACKGROUND_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuGameOver();

        void draw();
        void execute();
        void pushButton();

        void resetState();
    };
}// namespace Menu