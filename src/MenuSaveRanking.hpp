#pragma once

#include  "Menu.hpp" 
#define MENU_PATH "../assets/Menu/PrincipalMenu.png"
#include <fstream>
#include <map>

namespace Menu {
    class MenuSaveRanking : public Menu
    {
    public:
        std::string nameP;
        sf::Text message;
        sf::Text imputPlayer;
        float rankingP;
        
    private:
        MenuSaveRanking( float ranking, std::string fileName = MENU_PATH, sf::Vector2f size= sf::Vector2f(WIDTH, HEIGHT), sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
        ~MenuSaveRanking();

        void saveData();

        void draw();
        void execute();
        void pushButton();
        //void updateString();

        void resetState();
    };

}//namespace Menu