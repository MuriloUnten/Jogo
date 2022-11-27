#pragma once


#include "Menu.hpp"

#include <list>
#include <fstream>

#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

class Game;

namespace Menu
{
    class MenuLeaderboard : public Menu
    {
    private:

        Game* pGame;
        std::list<sf::Text*> ranking;

    public:
        MenuLeaderboard(Game* game = NULL, std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuLeaderboard();
        
        void loadData();
        void draw();
        void execute();
        void pushButton();

        void resetState();
    };//class MenuLeaderboard

}//namespace Menu