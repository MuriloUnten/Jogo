#pragma once

#include "Observer.hpp"

namespace Menu
{
    class Menu;
}


class MenuControl : public Observer
{
private:
    Menu::Menu* pMenu;

    std::string up;
    std::string down;
    std::string select;

public:
    MenuControl(Menu::Menu* menu);
    ~MenuControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);

    void setMenu(Menu::Menu* newMenu);

    void setKeys(std::string newUp, std::string newDown, std::string newSelect);

};