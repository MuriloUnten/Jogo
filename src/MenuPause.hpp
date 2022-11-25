#pragma once

#include "Menu.hpp"

class Game;

namespace Menu
{
    class MenuPause : public Menu
    {
    private:

        Game* pGame;

    public:

        MenuPause( Game* game = NULL);
        ~MenuPause();

        void update();
        void draw();
        void execute();
        void pushButton();

        void resetState();

    };
}//namespace Menu