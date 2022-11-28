#pragma once

#define MENU_PATH "../assets/Menu/PrincipalMenu.png"
#define LEADERBOARD_TXT_PATH "../assets/Saves/Leaderboard.txt"
#include  "Menu.hpp" 
#include "TextControl.hpp"
#include <fstream>
#include <map>

class Game;


namespace Menu
{
    class MenuSaveRanking : public Menu
    {
    private:
        TextControl* textControl;
        sf::Text playerInput;

    public:
        MenuSaveRanking(std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuSaveRanking();

        void saveData();

        void draw();
        void execute();
        void pushButton();
        void resetState();
    };

}//namespace Menu