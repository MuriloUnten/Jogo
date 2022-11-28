#pragma once

#define MENU_PATH "../assets/Menu/PrincipalMenu.png"
#include  "Menu.hpp" 
#include "TextControl.hpp"
#include <fstream>
#include <map>

class Game;


namespace Menu {
    class MenuEndLevel : public Menu
    {
    private:
        Game* pGame;

        sf::Text message;

    public:
        MenuEndLevel(Game* game = NULL, std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuEndLevel();

        void saveData();

        void draw();
        void execute();
        void pushButton();

        void resetState();
        void createEndLevelMenu();
    };

}//namespace Menu