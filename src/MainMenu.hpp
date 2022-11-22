#pragma once

#include "Menu.hpp"
#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

class Game;

namespace Menu {

    class MainMenu : public Menu
    {
    private:

        Game* pGame;
        sf::Text nameGame;

    public:
        MainMenu( Game* pG = NULL, std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MainMenu();

        void update();
        void draw();
        void execute();
        void pushButton();
    };

}