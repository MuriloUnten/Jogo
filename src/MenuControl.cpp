#include "MenuControl.hpp"
#include "Menu.hpp"


MenuControl::MenuControl(Menu::Menu* menu):
pMenu(menu),
up("W"),
down("S"),
select("Space")
{

}


MenuControl::~MenuControl()
{
    pMenu = NULL;
}


void MenuControl::handleKeyPressed(std::string key)
{
    std::cout << "keypressed: " << key << std::endl;
    if(key == up)
        pMenu->selectUp();
    else if(key == down)
        pMenu->selectDown();
    // else if(key == select)
        // pMenu->select();
}


void MenuControl::handleKeyReleased(std::string key)
{

}


void MenuControl::setMenu(Menu::Menu* newMenu)
{
    if(newMenu != NULL)
        pMenu = newMenu;
}


void MenuControl::setKeys(std::string newUp, std::string newDown, std::string newSelect)
{
    up = newUp;
    down = newDown;
    select = newSelect;
}
