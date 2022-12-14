#pragma once 
#include "Menu.hpp"
#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

class Game;

namespace Menu
{
    class MenuChoose : public Menu
    {
    private:
        Game* pGame;
    
    public:

        MenuChoose(Game* game = NULL, std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuChoose();
        void draw();
        void execute();
        void pushButton();

        void resetState();
    };
}//namespace Menu